#include <iostream>
#include <opencv2/opencv.hpp>
#include <sys/time.h>

#include "yolov5c.h"
#include "vpss_capture.h"
#include "yolo_sample.h"
#include "Interface.h"
#include "zbar.h"
#include <vector>
#include <ctime>

#include <stdio.h>
#include <dirent.h>

using namespace zbar;

typedef struct {
    VpssCapture vcap;
    cv::Mat image;
    int fd;
}vcap_t;
vcap_t vcap[YOLO_CHN_MAX];
YOLOV5C yolov5;
Interface anInterface;
static int vcap_cnt = 0;
static int qrcode = 0;

int yolo_init(int VpssGrp[YOLO_CHN_MAX], int VpssChn[YOLO_CHN_MAX], char *ModelPath)
{
    int i = 0, cnt = 10;
    int ret = -1;

    while(1)
    {
    for(i = 0; i < YOLO_CHN_MAX; i++)
    {
        if(VpssGrp[i] == -1 || VpssChn[i] == -1)
            break;

        if(vcap[i].fd <= 0)
        {
            vcap[i].fd = vcap[i].vcap.init(VpssGrp[i], VpssChn[i]);
            if(vcap[i].fd > 0)
            {
                vcap_cnt++;
                printf("vcap[%d].init ok fd:%d\n", i, vcap[i].fd);
            }
            else
            {
                printf("vcap[%d].init err fd:%d\n", i, vcap[i].fd);
            }
        }
    }
    // all is ok;
    if(vcap_cnt == i)
        break;
    // timeout;
    if(--cnt <= 0)
        break;
    // retry once;
    if(vcap_cnt > 0)
        cnt = 1;

    sleep(1);
    }

    printf("init all:%d, vcap_cnt:%d\n", i, vcap_cnt);
    if(vcap_cnt > 0)
    {
        ret = yolov5.init(ModelPath);
        qrcode = strstr(ModelPath, "qrcode")?1:0;
        printf("yolov5.init ret:%d\n", ret);
    }
    return ret;
}

void GetFileNames(const string &path, vector<string> &filenames_) {
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str()))) {
        cout << "Folder doesn't Exist!" << endl;
        return;
    }
    while ((ptr = readdir(pDir)) != nullptr) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
            filenames_.emplace_back(ptr->d_name);
    }
    closedir(pDir);
}

/// 从摄像头获取图片
int yolo_detect_cam(yolo_boxs_t _boxs[YOLO_CHN_MAX])
{
    VIDEO_FRAME_INFO_S *pstFrame = NULL;
    yolo_boxs_t *boxs = _boxs;
    int ret = 0;
    int maxfd = 0;
    struct timeval to;
    fd_set read_fds;
    cv::Mat frame;
    FD_ZERO(&read_fds);

    for (int i = 0; i < vcap_cnt; i++)
    {
        FD_SET(vcap[i].fd, &read_fds);
        maxfd = (maxfd < vcap[i].fd)?vcap[i].fd:maxfd;
    }
    to.tv_sec  = 2; to.tv_usec = 0;
    ret = select(maxfd + 1, &read_fds, NULL, NULL, &to);
    if (ret < 0)
    {
        printf("vpss select failed!\n");
        return -1;
    }
    else if (ret == 0)
    {
        printf("vpss get timeout!\n");
        return 0;
    }
    for (int i = 0; i < vcap_cnt; i++)
    {
        if (FD_ISSET(vcap[i].fd, &read_fds))
        {
            //printf("vpss get ok! [fd:%d]\n", vcap[i].fd);
            vcap[i].vcap.get_frame_lock(vcap[i].image, &pstFrame);
            if(vcap[i].image.empty())
            {
                std::cout << "vpss capture failed!!!\n";
                return -1;
            }

            struct timespec ts1, ts2;
            clock_gettime(CLOCK_MONOTONIC, &ts1);

            std::vector<BoxInfo> bboxs;

//        realize new detect func, read single image from memory

//            cv::imwrite("./temp.jpg", vcap[i].image);
//        ret = yolov5.detect(vcap[i].image, bboxs);

            boxs->chn = i;
            boxs->w = vcap[i].image.cols;
            boxs->h = vcap[i].image.rows;
////
            frame = vcap[i].image;
            int half_bolt = 100;
            std::vector<cv::Mat> patch_list; // 记录四份图片信息
            int subImageNum = 2;    // 给原图分4块

            if(!frame.data){
                cout<<"source image error! [subImageExtract()]"<<endl;
                return -1;
            }
            patch_list.clear();

            //    得到原图的宽高
            int srcHeight, srcWidth, subHeight, subWidth;
            srcHeight = frame.rows;   // 获取原图宽、高
            srcWidth  = frame.cols;
            subHeight = srcHeight / subImageNum;
            subWidth  = srcWidth / subImageNum;

    //    给原图分块
            for(int j = 0; j < subImageNum; j++) {
                for (int i = 0; i < subImageNum; i++) {
                    cv::Mat temImage(subHeight+half_bolt, subWidth+half_bolt, CV_8UC3, cv::Scalar(0, 0, 0));
                    if (j==0 && i==0) {
                        cv::Mat imageROI = frame(cv::Rect(i * subWidth, j * subHeight, temImage.cols, temImage.rows));
                        cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                        patch_list.push_back(temImage);
                    }
                    if (j==0 && i==1) {
                        cv::Mat imageROI = frame(cv::Rect(i * subWidth-half_bolt, j * subHeight , temImage.cols, temImage.rows));
                        cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                        patch_list.push_back(temImage);
                    }
                    if (j==1 && i==0) {
                        cv::Mat imageROI = frame(cv::Rect(i * subWidth, j * subHeight - half_bolt, temImage.cols, temImage.rows));
                        cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                        patch_list.push_back(temImage);
                    }
                    if (j==1 && i==1) {
                        cv::Mat imageROI = frame(cv::Rect(i * subWidth-half_bolt, j * subHeight - half_bolt, temImage.cols, temImage.rows));
                        cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                        patch_list.push_back(temImage);
                    }
                }
            }
            json page_info;
            for (int i = 0; i < patch_list.size(); i++)
            {
                json all_bolt_info;
                json this_patch;
                this_patch["patch_num"] = i;
                vector<vector<int>> all_bolt_coors;
                vector<vector<float>> all_bolt_score;

                std::vector<BoxInfo> bboxs_bolt;
                int ret = yolov5.detect(patch_list[i], bboxs_bolt);
                std::cout << "box numbers: **********************" << std::endl;
                std::cout << bboxs_bolt.size() << std::endl;

                for (int j = 0; j < bboxs_bolt.size(); j++) {
                    std::vector<int> real_coor;
                    vector<float> scores;

                    int rel_x0 = bboxs_bolt[j].box.x;
                    int rel_y0 = bboxs_bolt[j].box.y;
                    int real_x0 = 0;
                    int real_y0 = 0;
                    if (i == 0) {
                        real_x0 = rel_x0;
                        real_y0 = rel_y0;
                    }
                    else if (i == 1) {
                        real_x0 = rel_x0 + subWidth - half_bolt;
                        real_y0 = rel_y0;
                    }
                    else if (i == 2) {
                        real_x0 = rel_x0;
                        real_y0 = rel_y0 + subHeight - half_bolt;
                    }
                    else {
                        real_x0 = rel_x0 + subWidth - half_bolt;
                        real_y0 = rel_y0 + subHeight - half_bolt;
                    }

                    int width = bboxs_bolt[j].box.width;
                    int height = bboxs_bolt[j].box.height;
                    int label = bboxs_bolt[j].label;
                    float score = bboxs_bolt[j].score;

                    real_coor.push_back(real_x0);
                    real_coor.push_back(real_y0);
                    real_coor.push_back(width);
                    real_coor.push_back(height);
                    real_coor.push_back(label);
                    scores.push_back(score);
                    all_bolt_coors.push_back(real_coor);
                    all_bolt_score.push_back(scores);
                }
                all_bolt_info["coors"] = all_bolt_coors;
                all_bolt_info["scores"] = all_bolt_score;

                this_patch["bolt_info"] = all_bolt_info;
                page_info.push_back(this_patch);
            }
            json all_context;
            all_context["info"] = page_info;
            std::string json_path2{"/app/pics/record2.json"};
            std::ofstream oo(json_path2);
            oo << std::setw(4) << all_context << std::endl;   // std::setw(4) 设置格式
            std::time_t t = std::time(0);  // t is an integer type
            string timestamp = to_string(t);
            cv::imwrite("/home/pics/"+timestamp+".jpg", frame);
//            cv::imwrite("/home/pics/test/"+timestamp+".jpg", frame);
            anInterface.ParseJson(timestamp, timestamp ,json_path2);

            if(std::remove(json_path2.c_str()) == 0){
                cout << "delect success!!" << endl;
            }

            char *srcVirAddr = (char*)HI_MPI_SYS_Mmap(pstFrame->stVFrame.u64PhyAddr[0], boxs->w*boxs->h);
            //printf("chn:%d, srcVirAddr:%p, w:%d, h:%d\n", i, srcVirAddr, boxs->w, boxs->h);

            clock_gettime(CLOCK_MONOTONIC, &ts2);
            HI_MPI_SYS_Munmap(srcVirAddr, boxs->w*boxs->h);
            vcap[i].vcap.get_frame_unlock(pstFrame);
            boxs++;
        }
    }
    return 0;
}

/// 从本地获取图片
int yolo_detect_pic_list(std::string folder_path, std::string json_path2){

    vector<string> piclist;
    cout << "GetFileNames!" << endl;
    GetFileNames(folder_path, piclist);
    cout << "GetFileNames success!" << endl;
    sort(piclist.begin(), piclist.end());
    cv::Mat frame;
    for (auto &pic_name:piclist) {
        cout << folder_path + '/' + pic_name << endl;
        frame = cv::imread(folder_path + '/' + pic_name);
        int half_bolt = 100;
        std::vector<cv::Mat> patch_list; // 记录四份图片信息
        int subImageNum = 2;    // 给原图分4块

        if(!frame.data){
            cout<<"source image error! [subImageExtract()]"<<endl;
            return -1;
        }
        patch_list.clear();


        //    得到原图的宽高
        int srcHeight, srcWidth, subHeight, subWidth;
        srcHeight = frame.rows;   // 获取原图宽、高
        srcWidth  = frame.cols;
        subHeight = srcHeight / subImageNum;
        subWidth  = srcWidth / subImageNum;

//    给原图分块
        for(int j = 0; j < subImageNum; j++) {
            for (int i = 0; i < subImageNum; i++) {
                cv::Mat temImage(subHeight+half_bolt, subWidth+half_bolt, CV_8UC3, cv::Scalar(0, 0, 0));
                if (j==0 && i==0) {
                    cv::Mat imageROI = frame(cv::Rect(i * subWidth, j * subHeight, temImage.cols, temImage.rows));
                    cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                    patch_list.push_back(temImage);
                }
                if (j==0 && i==1) {
                    cv::Mat imageROI = frame(cv::Rect(i * subWidth-half_bolt, j * subHeight , temImage.cols, temImage.rows));
                    cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                    patch_list.push_back(temImage);
                }
                if (j==1 && i==0) {
                    cv::Mat imageROI = frame(cv::Rect(i * subWidth, j * subHeight - half_bolt, temImage.cols, temImage.rows));
                    cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                    patch_list.push_back(temImage);
                }
                if (j==1 && i==1) {
                    cv::Mat imageROI = frame(cv::Rect(i * subWidth-half_bolt, j * subHeight - half_bolt, temImage.cols, temImage.rows));
                    cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
                    patch_list.push_back(temImage);
                }
            }
        }
        json page_info;
        for (int i = 0; i < patch_list.size(); i++)
        {
            json all_bolt_info;
            json this_patch;
            this_patch["patch_num"] = i;
            vector<vector<int>> all_bolt_coors;
            vector<vector<float>> all_bolt_score;

            std::vector<BoxInfo> bboxs_bolt;
            int ret = yolov5.detect(patch_list[i], bboxs_bolt);
            std::cout << "box numbers: **********************" << std::endl;
            std::cout << bboxs_bolt.size() << std::endl;

            for (int j = 0; j < bboxs_bolt.size(); j++) {
                std::vector<int> real_coor;
                vector<float> scores;

                int rel_x0 = bboxs_bolt[j].box.x;
                int rel_y0 = bboxs_bolt[j].box.y;
                int real_x0 = 0;
                int real_y0 = 0;
                if (i == 0) {
                    real_x0 = rel_x0;
                    real_y0 = rel_y0;
                }
                else if (i == 1) {
                    real_x0 = rel_x0 + subWidth - half_bolt;
                    real_y0 = rel_y0;
                }
                else if (i == 2) {
                    real_x0 = rel_x0;
                    real_y0 = rel_y0 + subHeight - half_bolt;
                }
                else {
                    real_x0 = rel_x0 + subWidth - half_bolt;
                    real_y0 = rel_y0 + subHeight - half_bolt;
                }

                int width = bboxs_bolt[j].box.width;
                int height = bboxs_bolt[j].box.height;
                int label = bboxs_bolt[j].label;
                float score = bboxs_bolt[j].score;

                real_coor.push_back(real_x0);
                real_coor.push_back(real_y0);
                real_coor.push_back(width);
                real_coor.push_back(height);
                real_coor.push_back(label);
                scores.push_back(score);
                all_bolt_coors.push_back(real_coor);
                all_bolt_score.push_back(scores);
            }
            all_bolt_info["coors"] = all_bolt_coors;
            all_bolt_info["scores"] = all_bolt_score;

            this_patch["bolt_info"] = all_bolt_info;
            page_info.push_back(this_patch);
        }

        json all_context;

        all_context["info"] = page_info;

        std::ofstream oo(json_path2);
        oo << std::setw(4) << all_context << std::endl;   // std::setw(4) 设置格式
        std::time_t t = std::time(0);  // t is an integer type
        string timestamp = to_string(t);
        string out_path = "/app/pics/" + timestamp + ".jpg";
        anInterface.ParseJson(pic_name, timestamp ,json_path2);

        if(std::remove(json_path2.c_str()) == 0){
            cout << "delect success!!" << endl;
        }
    }

    return 0;
}

//int yolo_detect_bolt(string pic_path, string json_path){
//    int half_bolt = 100;
//    std::vector<cv::Mat> patch_list; // 记录四份图片信息
//
//    int subImageNum = 2;    // 给原图分16块
//    cv::Mat src;
//    //Mat subImages;
//    //std::cout<<subImages[0]<<std::endl;
//    src = cv::imread(pic_path);
//
//    if(!src.data){
//        cout<<"source image error! [subImageExtract()]"<<endl;
//        return -1;
//    }
//    patch_list.clear();
////    得到原图的宽高
//    int srcHeight, srcWidth, subHeight, subWidth;
//    srcHeight = src.rows;   // 获取原图宽、高
//    srcWidth  = src.cols;
//    subHeight = srcHeight / subImageNum;
//    subWidth  = srcWidth / subImageNum;
//
////    给原图分块
//    for(int j = 0; j < subImageNum; j++) {
//        for (int i = 0; i < subImageNum; i++) {
//            cv::Mat temImage(subHeight+half_bolt, subWidth+half_bolt, CV_8UC3, cv::Scalar(0, 0, 0));
//            if (j==0 && i==0) {
//                cv::Mat imageROI = src(cv::Rect(i * subWidth, j * subHeight, temImage.cols, temImage.rows));
//                cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
//                patch_list.push_back(temImage);
//            }
//            if (j==0 && i==1) {
//                cv::Mat imageROI = src(cv::Rect(i * subWidth-half_bolt, j * subHeight , temImage.cols, temImage.rows));
//                cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
//                patch_list.push_back(temImage);
//            }
//            if (j==1 && i==0) {
//                cv::Mat imageROI = src(cv::Rect(i * subWidth, j * subHeight - half_bolt, temImage.cols, temImage.rows));
//                cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
//                patch_list.push_back(temImage);
//            }
//            if (j==1 && i==1) {
//                cv::Mat imageROI = src(cv::Rect(i * subWidth-half_bolt, j * subHeight - half_bolt, temImage.cols, temImage.rows));
//                cv::addWeighted(temImage, 1.0, imageROI, 1.0, 0., temImage);
//                patch_list.push_back(temImage);
//            }
//        }
//    }
//    json page_info;
//    for (int i = 0; i < patch_list.size(); i++)
//    {
//        json all_bolt_info;
//        json this_patch;
//        this_patch["patch_num"] = i;
//        vector<vector<int>> all_bolt_coors;
//        vector<vector<float>> all_bolt_score;
//
//        std::vector<BoxInfo> bboxs_bolt;
//        int ret = yolov5.detect(patch_list[i], bboxs_bolt);
//        std::cout << "box numbers: **********************" << std::endl;
//        std::cout << bboxs_bolt.size() << std::endl;
//
//        for (int j = 0; j < bboxs_bolt.size(); j++) {
//            std::vector<int> real_coor;
//            vector<float> scores;
//
//            int rel_x0 = bboxs_bolt[j].box.x;
//            int rel_y0 = bboxs_bolt[j].box.y;
//            int real_x0 = 0;
//            int real_y0 = 0;
//            if (i == 0) {
//                real_x0 = rel_x0;
//                real_y0 = rel_y0;
//            }
//            else if (i == 1) {
//                real_x0 = rel_x0 + subWidth - half_bolt;
//                real_y0 = rel_y0;
//            }
//            else if (i == 2) {
//                real_x0 = rel_x0;
//                real_y0 = rel_y0 + subHeight - half_bolt;
//            }
//            else {
//                real_x0 = rel_x0 + subWidth - half_bolt;
//                real_y0 = rel_y0 + subHeight - half_bolt;
//            }
//
//            int width = bboxs_bolt[j].box.width;
//            int height = bboxs_bolt[j].box.height;
//            int label = bboxs_bolt[j].label;
//            float score = bboxs_bolt[j].score;
//
//            real_coor.push_back(real_x0);
//            real_coor.push_back(real_y0);
//            real_coor.push_back(width);
//            real_coor.push_back(height);
//            real_coor.push_back(label);
//            scores.push_back(score);
//            all_bolt_coors.push_back(real_coor);
//            all_bolt_score.push_back(scores);
//        }
//        all_bolt_info["coors"] = all_bolt_coors;
//        all_bolt_info["scores"] = all_bolt_score;
//
//        this_patch["bolt_info"] = all_bolt_info;
//        page_info.push_back(this_patch);
//    }
//
//    json all_context;
//
//    all_context["info"] = page_info;
//
//    std::ofstream oo(json_path);
//
//    oo << std::setw(4) << all_context << std::endl;   // std::setw(4) 设置格式
//
//
//
//    return 0;
//}

int yolo_detect(yolo_boxs_t boxs[YOLO_CHN_MAX])
{
    string json_path2 = "/app/pics/record2.json";
    string json_path3 = "/app/pics/record3.json";
    string folder_path = "/home/pics/test";
    yolo_detect_cam(boxs);
//    yolo_detect_pic_list(folder_path, json_path2);

    return 0;
}

// 这个deinit()可以等全部运行完之后，统一进行nnie等资源的释放
int yolo_deinit()
{
//  yolov5.destroy();
    yolov5.destroy();
  vcap[0].vcap.destroy();  
  return 0;
}
 