//
// Created by ljh on 2021/11/30.
//
#include "Interface.h"

Interface::Interface() {

}
//
//int Interface::inter_rec(vector<vector<int>> loc_tl, vector<vector<int>> loc_dr, vector<vector<int>>& boxes_list) {
//    vector<vector<int>> loc1 = loc_tl;
//    vector<vector<int>> loc2 = loc_dr;
//
//    vector<int> M;
//    vector<int> N;
//    vector<vector<int>> aa;
//    vector<vector<int>> bb;
//    vector<int>loc1x;
//    vector<int>loc1y;
//    vector<vector<int>> loc_tl_tmp = loc1;
//    vector<vector<int>> loc_dr_tmp = loc2;
////    auto loc_tl_tmp = loc1;
////    auto loc_dr_tmp = loc2;
//    for (int i=0; i < loc_dr.size(); i++)
//    {
//        for (int j = 0; j < loc_dr.size(); ++j) {
//            M.clear();
//            N.clear();
//            aa.clear();
//            bb.clear();
//            loc1x.clear();
//            loc1y.clear();
//            if (i != j)
//            {
//                int Xmax = max(loc1[i][0], loc_tl[j][0]);
//                int Ymax = max(loc1[i][1], loc_tl[j][1]);
//                M.push_back(Xmax);
//                M.push_back(Ymax);
//                int Xmin = min(loc2[i][0], loc_dr[j][0]);
//                int Ymin = min(loc2[i][1], loc_dr[j][1]);
//                N.push_back(Xmin);
//                N.push_back(Ymin);
//                // 如果矩形相交
////                cout << M[0] << " " << N[0] << " " << M[1] << " " << N[1] << endl;
////                cout << (M[0] < N[0]) << endl;
////                cout << (M[1] < N[1]) << endl;
//                if ((M[0] < N[0]) && (M[1] < N[1])){
//                    // 若相交，则新的左上角坐标loc1取两个矩形左上角坐标的最小值
//                    loc1x.push_back(min(loc1[i][0], loc_tl[j][0]));
//                    loc1x.push_back(min(loc1[i][1], loc_tl[j][1]));
//                    // 右下角坐标取两个矩形右下角坐标的最大值
//                    loc1y.push_back(max(loc2[i][0], loc_dr[j][0]));
//                    loc1y.push_back(max(loc2[i][1], loc_dr[j][1]));
//                    // aa将满足相交的框的坐标保存下，用于挑选
//
//                    aa.push_back(loc1[i]);
//                    aa.push_back(loc1[j]);
//                    bb.push_back(loc2[i]);
//                    bb.push_back(loc2[j]);
//                    // 并非原地替换，加入中间缓存变量
////                    cout << loc1x[0] << "," << loc1x[1] << " & " << loc1y[0] << "," << loc1y[1] <<endl;
//                    for (int q = 0; q < loc1.size(); ++q) {
//                        if(std::find(aa.begin(), aa.end(), loc1[q]) != aa.end())
//                            loc_tl_tmp[q] = loc1x;
//                        else
//                            loc_tl_tmp[q] = loc1[q];
//                    }
//                    for (int w = 0; w < loc2.size(); ++w) {
//                        if(std::find(bb.begin(), bb.end(), loc2[w]) != bb.end())
//                            loc_dr_tmp[w] = loc1y;
//                        else
//                            loc_dr_tmp[w] = loc2[w];
//                    }
//                    loc1 = loc_tl_tmp;
//                    loc2 = loc_dr_tmp;
//                }
//            }
//        }
//    }
//
//    vector<int> loc_tl_re;
//    vector<vector<int>> loc_tl_res;
//    vector<int> loc_dr_re;
//    vector<vector<int>> loc_dr_res;
//
///// vector开辟太多，不够用了
//    for (int q = 0; q < loc_tl_tmp.size(); ++q) {
//        loc_tl_re.clear();
//        for (int qq = 0; qq < loc_tl_tmp[q].size(); ++qq){
//            if(std::find(loc_tl_re.begin(), loc_tl_re.end(), loc_tl_tmp[q][qq]) == loc_tl_re.end()) {
//                loc_tl_re.push_back(loc_tl_tmp[q][qq]);
//            }
//        }
//        loc_tl_res.push_back(loc_tl_re);
//    }
//    for (int q = 0; q < loc_dr_tmp.size(); ++q) {
//
//        loc_dr_re.clear();
//        for (int qq = 0; qq < loc_dr_tmp[q].size(); ++qq){
//            if(std::find(loc_dr_re.begin(), loc_dr_re.end(), loc_dr_tmp[q][qq]) == loc_dr_re.end()) {
//                loc_dr_re.push_back(loc_dr_tmp[q][qq]);
//            }
//        }
//        loc_dr_res.push_back(loc_dr_re);
//    }
//
////
////    for (auto i : loc_tl_res)
////    {
////        cout << "[";
////        for (auto j:i)
////            cout << j << " ";
////        cout << "]";
////    }
////    cout << endl;
////    for (auto i : loc_dr_res)
////    {
////        cout << "[";
////        for (auto j:i)
////            cout << j << " ";
////        cout << "]";
////    }
////    cout << endl;
////    cout << "******************" << endl;
//
//    /*
//     * boxes_list : 将数据填充到boxes_lists当中
//     * */
////    需要将最后的框转成坐标
//    vector<int> box_list;
//    for (int i = 0; i < loc_tl_res.size(); i++) {
//        box_list.clear();
//        box_list.push_back(loc_tl_res[i][0]);
//        box_list.push_back(loc_tl_res[i][1]);
//        box_list.push_back(loc_dr_res[i][0]);
//        box_list.push_back(loc_dr_res[i][1]);
//        boxes_list.push_back(box_list);
//    }
//    loc_tl_res.clear();
//    loc_dr_res.clear();
//    loc_tl_re.clear();
//    loc_tl_re.clear();
//    loc_tl_tmp.clear();
//    loc_dr_tmp.clear();
//    loc1.clear();
//    loc2.clear();
//
//    return 0;
//}

//int Interface::Ini_canvas() {
//
//    return 0;
//}
//
//int Interface::Paste_canvas(cv::Mat img ,vector<vector<int>>& boxes_list, int page_num, json& all_context_info, vector<cv::Mat>& canvas_list,string json_path) {
//    /// boxes_list 形如：
//    /// [[x0,y0,x1,y1,class],
//    ///  [x0,y0,x1,y1,class],
//    ///  [...]
//    ///  ...
//    /// ]
//    /// 判断是否空
//    if (boxes_list.size() == 0) {
//        cerr << "empty!!" << endl;
//        return -1;
//    }
//    /// 转数据结构
//    list<vector<int>> boxes_lists;
//    for (auto bb : boxes_list){
//        boxes_lists.push_back(bb);
//    }
////    应该是有三个框
//    Recur_Paste(img, boxes_lists, page_num, all_context_info, canvas_list, json_path);
//    return 0;
//}
//int Interface::Recur_Paste(cv::Mat img, list<vector<int>>& boxes_list,int page_num, json& all_context_info,vector<cv::Mat>& canvas_list,string json_path) {
////    贴一次图进一次
////    std::cout << "Recur_Paste!" << std::endl;
//    bool out_flag = false;
//    int x_start = 0, y_start = 0, x_end = 0, y_end = 0;
//    int max_y_end = 0;
//    int patch_num = 1;
//    vector<json>this_page_info;
//    cv::Mat canvas (1080, 1920, CV_8UC3, cv::Scalar(255, 255, 255));
////    auto remained_boxes_list = boxes_list;
//    list<vector<int>> remained_boxes_list;
//    for (auto bb : boxes_list){
//        remained_boxes_list.push_back(bb);
//    }
//
////    cout << "remained_boxes size: " <<remained_boxes_list.size() << endl;
////    for(auto reb:remained_boxes_list)
////    {
////        for (auto rebb:reb)
////            cout << rebb << ", ";
////        cout << endl;
////    }
//
//    for(auto & it : boxes_list)
//    {
////        是否有缩放，缩放比例
//        float ratio = 1;
//        int target_w = 1920;
//        int target_h = 1080;
//        x_start = x_end;
////        x_end = x_start + boxes_list[i][2] - boxes_list[i][0];
////        y_end = y_start + boxes_list[i][3] - boxes_list[i][1];
//        x_end = x_start + it[2] - it[0];
//        y_end = y_start + it[3] - it[1];
//        /// 因为只有到了最右端才换行
//        max_y_end = max(max_y_end, y_end);
//        /// 如果换行
////        cout << "Recur_paste!!!!" << endl;
//        /// 超出图像尺寸了
//        if (x_end >= img.cols - 5){
//            x_start = 0;
//            x_end = x_start + it[2] - it[0];
//            y_start = max_y_end;
//            y_end = y_start + it[3] - it[1];
//        }
//        /// 抠出来的区域
////        auto img_block = img[y_start:y_end, x_start:x_end];
//        auto img_block = img(cv::Rect(it[0],it[1] ,it[2] - it[0] ,it[3]-it[1]));
//        remained_boxes_list.pop_front();
//        /// 将剩余框弹出一个
////        cout << "remain boxes numbers..." << remained_boxes_list.size() << endl;
//        /// 判断剩余画布是否越界，如果越界，将img_block缩放
//        if ((y_end >= 1080) || (x_end >= 1920)){
//            out_flag = true;
//            int reserve_blank_w = 1920 - x_start;
//            int reserve_blank_h = 1080 - y_start;
//            /// 判断是哪边缩放
//            if ((img_block.cols / img_block.rows) > (reserve_blank_w / reserve_blank_h))
//            {
////                cout << "resize y" <<endl;
//                target_w = reserve_blank_w;
//                target_h = int(img_block.rows / img_block.cols * target_w);
//                x_end = 1920;
//                y_end = y_start + target_h;
//            }
//            else
//            {
////                cout << "resize x" <<endl;
//                target_h = reserve_blank_h;
//                target_w = int(img_block.cols / img_block.rows * target_h);
//                y_end = 1080;
//                x_end = x_start + target_w;
//            }
//            ratio = img_block.cols / target_w;
//            cv::resize(img_block, img_block, cv::Size(target_w, target_h), cv::INTER_CUBIC);
//        }
//        /// 贴图
////        cout << "img_block shape: " << img_block.rows << "," << img_block.cols <<  " x_start: " << x_start << " y_start: " << y_start << " x_end: " << x_end << " y_end: " << y_end << endl;
////        cout << "canvas shape: " << canvas.rows << "," << canvas.cols << endl;
//        cv::Mat roi=canvas(cv::Rect(x_start, y_start, x_end-x_start, y_end-y_start));
////        cout << "copy success..." << endl;
//// 为什么不贴？
//        img_block.copyTo(roi);
//
//        /// json记录位置
//        json this_page_canvas;
//        this_page_canvas["patch_num"] = patch_num;
//        patch_num +=1;
//        this_page_canvas["patch_width"] = img_block.rows;
//        this_page_canvas["patch_height"] = img_block.cols;
//        // 在原图中的位置 相当于记录两个start
//        this_page_canvas["img_block_start_x"] = it[0];
//        this_page_canvas["img_block_start_y"] = it[1];
//        this_page_canvas["img_block_end_x"] = it[0];
//        this_page_canvas["img_block_end_y"] = it[1];
//        // 在canvas中的位置
//        this_page_canvas["patch_start_x"] = x_start;
//        this_page_canvas["patch_start_y"] = y_start;
//        this_page_canvas["patch_end_x"] = x_end;
//        this_page_canvas["patch_end_y"] = y_end;
//        // 有无缩放
//        this_page_canvas["ratio"] = ratio;
//        list<vector<int>> bolt_info;
//        // 模拟bolts
////        vector<int> bolt_coor1{5,5,105,105,0};
////        vector<int> bolt_coor2{7,7,107,107,1};
////        bolt_info.push_back(bolt_coor1);
////        bolt_info.push_back(bolt_coor2);
//        this_page_canvas["bolt_info"] = bolt_info;
//
//        this_page_info.push_back(this_page_canvas);
//
//    // 不一定要恰好贴满的时候结束，万一正好留了一个patch放在了新的page上，这样就无法保存啦！所以要有兜底的操作
//        if (out_flag == true){
//            // 此图片完全贴完，保存canvas图片
//            out_flag = false;
//            json context;
//            context["page_num"] = page_num;
//            context["this_page_info"] = this_page_info;
////            清空当前页信息
////            vector<json> this_page_info;
//            this_page_info.clear();
//            cv::imwrite("./app/pics/canvas-" + std::to_string(page_num) + ".jpg", canvas);
//            canvas_list.push_back(canvas);
//            page_num+=1;
//            all_context_info.push_back(context);
////            canvas.release();
//            Recur_Paste(img, remained_boxes_list, page_num, all_context_info, canvas_list, json_path);
//        }
////        check remained boxes:
//
////  如果已贴完，并且没有越界
//        if ((remained_boxes_list.empty()) && (out_flag == false)){
////            std::cout << "last paste" << std::endl;
//            json context;
//            context["page_num"] = page_num;
//            context["this_page_info"] = this_page_info;
//            // 清空当前页信息
////            vector<json> this_page_info;
//            this_page_info.clear();
//            cv::imwrite("./app/pics/canvas-" + std::to_string(page_num) + ".jpg", canvas);
//            canvas_list.push_back(canvas);
////            canvas.release();
//            all_context_info.push_back(context);
//            // 在这儿创建就好了嘛
//            json all_context;
//            all_context["info"] = all_context_info;
////            string saveJsonPath = "/app/pics/record.json";
//            std::ofstream oo(json_path);
//            oo << std::setw(4) << all_context << std::endl;   // std::setw(4) 设置格式
//        }
//        /// 保存canvas以及json
//    }
//
//    return 0;
//}

int Interface::ReadJson(string json_path, json& all_info) {

    /// read json
    json j;
    vector<json> this_page_info;
    vector<json> next_page_info;
    std::ifstream jfile(json_path);
    jfile >> j;
    jfile.close();
    all_info = j.at("info");

    return 0;
}
//int Interface::ParseJson(string pic_path,string save_path, string json_path) {
//    /*
//     * 之前是直接读取的图片，现在先是用一张图片做测试，然后考虑转成视频流
//     * */
//    json all_info;
//    bool defect = false;
//    cv::Mat raw_img = cv::imread("/app/pics/"+pic_path);
////    cv::Mat raw_img (1080, 1920, CV_8UC3, cv::Scalar(255, 255, 255));
//    /// 保存record3.json
//    json all_info3;
//    json all_page_info;
//    vector<json> bolts_info;
//
//    ReadJson(json_path, all_info);
//    for (auto page_info : all_info) {
//        auto this_page_info = page_info.at("this_page_info");
//        for (auto info : this_page_info) {
////            int x0 = info.at("img_block_start_x");
////            int y0 = info.at("img_block_start_y");
////            int x1 = info.at("img_block_end_x");
////            int y1 = info.at("img_block_end_y");
//            int canvas_x_start = info.at("img_block_start_x");
//            int canvas_y_start = info.at("img_block_start_y");
//            int canvas_x_end = info.at("img_block_end_x");
//            int canvas_y_end = info.at("img_block_end_y");
//            float ratio = info.at("ratio");
//            auto bolt_info = info.at("bolt_info");
//
//            for (auto coors : bolt_info) {
//
//                int x0 = coors[0];
//                int y0 = coors[1];
//                int x1 = coors[2];
//                int y1 = coors[3];
//                int class_name = coors[4];
//                float conf = coors[5];
////                cout << "x0: " << x0 << " y0: " << y0 << " x1: " << x1 << " y1: " << y1 << endl;
//                int x0_real = int(x0 * ratio) + canvas_x_start;
//                int y0_real = int(y0 * ratio) + canvas_y_start;
//                int x1_real = int(x1 * ratio) + canvas_x_start;
//                int y1_real = int(y1 * ratio) + canvas_y_start;
//
//                json coor;
//                coor["x0"] = x0_real;
//                coor["y0"] = y0_real;
//                coor["x1"] = x1_real;
//                coor["y1"] = y1_real;
//                coor["class"] = class_name;
//                coor["conf"] = conf;
//                bolts_info.push_back(coor);
//
//                ofstream pre_label_file;
//                string predict_label_path;
//                predict_label_path = "/home/pics/" +  pic_path.substr(0, pic_path.rfind(".")); + ".txt";
//                pre_label_file.open(predict_label_path, ios::binary | ios::in);
//                if (pre_label_file.is_open())
//                {
//                    pre_label_file << class_name << " " << x0_real << " " << y0_real << " " << x1_real << " " << y1_real << " " << conf << "\n";
//                } else{
//                    cerr << "model file can't open" << endl;
//                    return -1;
//                }
//
//                if (class_name == 0){
//                    defect = true;
//                    cv::rectangle(raw_img, cv::Point(x0_real, y0_real), cv::Point(x1_real, y1_real), (0,255,255), 3,3);
//                }
//                if (class_name == 1)
//                    cv::rectangle(raw_img, cv::Point(x0_real, y0_real), cv::Point(x1_real, y1_real), (255,0,255), 3,3);
//            }
//        }
//    }
//
//
//
//    cv::imwrite(save_path, raw_img);
//    FILE *fp = NULL;
//    unsigned int imageSize;        //图片字节数
//    char *imageBin;
//    char *imageBase64;
//    char *imageOutput;
//    size_t result;
//    char *ret;
//    unsigned int base64StrLength;
//
//    fp = fopen(save_path.c_str(),"rb");   //待编码图片
//    if (NULL == fp)
//    {
//        printf("file open file");
//        return -1;
//    }
//
//    //获取图片大小
//    fseek(fp, 0L, SEEK_END);
//    imageSize = ftell(fp);
//    fseek(fp, 0L, SEEK_SET);
//
//    //分配内存存储整个图片
//    imageBin = (char *)malloc(sizeof(char)*imageSize);
//    if (NULL == imageBin)
//    {
//        printf("malloc failed");
//        return -1;
//    }
//    //读取图片
////    cat /proc/media-mem
//    result = fread(imageBin, 1, imageSize, fp);
//    if (result != imageSize)
//    {
//        printf("file read failed");
//        return -1;
//    }
//    fclose(fp);
//
//    //分配编码后图片所在buffer
//    imageBase64 = (char *)malloc(sizeof(char)*imageSize*2);//因为编码一版会比源数据大1/3的样子，这里直接申请源文件一倍的空间
//    if (NULL == imageBase64)
//    {
//        printf("malloc failed");
//        return -1;
//    }
//
//    //base64编码
//    base64_encode(imageBin, imageBase64, imageSize);
//    base64StrLength = strlen(imageBase64);
////    printf("base64 str length:%d\n", base64StrLength);
////    printf("%s\n", imageBase64);
//    cout << "encoding..." << endl;
//
//    all_page_info["page_info"] = imageBase64;
//    all_page_info["img_info"] = bolts_info;
////    all_page_info["nest_info"] =
////    all_page_info["others_info"] =
//
//    all_info3["page_info"] = all_page_info;
//
//
//    std::string saveJsonPath = "/app/pics/record3.json";
//    std::ofstream oo(saveJsonPath);
//    oo << std::setw(4) << all_info3 << std::endl;   // std::setw(4) 设置格式
//
///// 只有当检测出来有问题的螺栓才保存图片，同时保存图片的名字用时间戳
////    if (defect)
//
//    return 0;
//}




int Interface::ParseJson(string pic_path,string save_path, string json_path) {
    /*
     * 之前是直接读取的图片，现在先是用一张图片做测试，然后考虑转成视频流
     * */
    json all_info;
    bool defect = false;
    string tmp_path = "/app/pics/" + save_path + ".jpg";
    cv::Mat raw_img = cv::imread("/app/pics/"+pic_path);
//    cv::Mat raw_img (1080, 1920, CV_8UC3, cv::Scalar(255, 255, 255));
    /// 保存record3.json
    json all_info3;
    json all_page_info;
    vector<json> bolts_info;
    ReadJson(json_path, all_info);
    vector<Rect> boxes;
    vector<float> confidences;
    vector<int> classes;
    for (auto patch_info : all_info) {
        auto bolt_info = patch_info.at("bolt_info");
//        cout << "************bolt_info**********" << endl;
        vector<vector<int>> bolts_coors = bolt_info.at("coors");
        vector<vector<float>> bolts_scores = bolt_info.at("scores");
        for (int i = 0; i < bolts_coors.size();i++) {

            Rect box;
            int class_name = bolts_coors[i][4];
            box.x1 = bolts_coors[i][0];
            box.y1 = bolts_coors[i][1];
            box.x2 = box.x1 + bolts_coors[i][2];
            box.y2 = box.y1 + bolts_coors[i][3];
            classes.push_back(class_name);
            boxes.push_back(box);

//            int x0_real = bolts_coors[i][0];
//            int y0_real = bolts_coors[i][1];
//            int x1_real = x0_real + bolts_coors[i][2];
//            int y1_real = y0_real + bolts_coors[i][3];

            float sc = bolts_scores[i][0];
            confidences.push_back(sc);
            }
    }

    /// 过滤重复框 https://blog.csdn.net/qq_38316300/article/details/120174900
    auto ress = nms(boxes, confidences, 0.25, 0.3);
    cout << "**************************" << endl;
    for (auto res:ress) {
        float _conf = res.conf;
        Rect _rect = res.rect;
        int _idx = res.idx;
        int class_name = classes[_idx];
        cout << "class_name: " << class_name << endl;
        json coor;
        coor["x0"] = _rect.x1;
        coor["y0"] = _rect.y1;
        coor["x1"] = _rect.x2;
        coor["y1"] = _rect.y2;
        coor["class"] = class_name;
        coor["conf"] = _conf;
        bolts_info.push_back(coor);


        // 将预测结果保存到txt中
        ofstream pre_label_file;
        string predict_label_path;
        predict_label_path = "/app/pics/" +  save_path  + ".txt";
        pre_label_file.open(predict_label_path, ios::app);
        if (pre_label_file.is_open())
        {
            pre_label_file << class_name << " " << _rect.x1 << " " << _rect.y1 << " " << _rect.x2 << " " << _rect.y2 << " " << _conf << "\n";
        } else{
            cerr << "model file can't open" << endl;
            return -1;
        }

        if (class_name == 0){
            defect = true;
            cv::rectangle(raw_img, cv::Point(_rect.x1, _rect.y1), cv::Point(_rect.x2, _rect.y2), (0,255,255), 3,3);
        }
        if (class_name == 1)
            cv::rectangle(raw_img, cv::Point(_rect.x1, _rect.y1), cv::Point(_rect.x2, _rect.y2), (255,0,255), 3,3);
    }

    cout << "save path: " << tmp_path << endl;
    cv::imwrite(tmp_path, raw_img);
    FILE *fp = NULL;
    unsigned int imageSize;        //图片字节数
    char *imageBin;
    char *imageBase64;
    char *imageOutput;
    size_t result;
    char *ret;
    unsigned int base64StrLength;

    fp = fopen(tmp_path.c_str(),"rb");   //待编码图片
    if (NULL == fp)
    {
        printf("file open error");
        return -1;
    }

    //获取图片大小
    fseek(fp, 0L, SEEK_END);
    imageSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    //分配内存存储整个图片
    imageBin = (char *)malloc(sizeof(char)*imageSize);
    if (NULL == imageBin)
    {
        printf("malloc failed");
        return -1;
    }
    //读取图片
//    cat /proc/media-mem
    result = fread(imageBin, 1, imageSize, fp);
    if (result != imageSize)
    {
        printf("file read failed");
        return -1;
    }
    fclose(fp);

    //分配编码后图片所在buffer
    imageBase64 = (char *)malloc(sizeof(char)*imageSize*2);//因为编码一版会比源数据大1/3的样子，这里直接申请源文件一倍的空间
    if (NULL == imageBase64)
    {
        printf("malloc failed");
        return -1;
    }

    //base64编码
    base64_encode(imageBin, imageBase64, imageSize);
    base64StrLength = strlen(imageBase64);
//    printf("base64 str length:%d\n", base64StrLength);
//    printf("%s\n", imageBase64);
    cout << "encoding..." << endl;

    all_page_info["img_info"] = imageBase64;
    all_page_info["bolts_info"] = bolts_info;
//    all_page_info["nest_info"] =
//    all_page_info["others_info"] =

    all_info3["info"] = all_page_info;


    std::string saveJsonPath = "/app/pics/record3.json";
    cout << "save json3 success..." << endl;
    std::ofstream oo(saveJsonPath);
    oo << std::setw(4) << all_info3 << std::endl;   // std::setw(4) 设置格式

/// 只有当检测出来有问题的螺栓才保存图片，同时保存图片的名字用时间戳
//    if (defect)

    return 0;
}

float Interface::iou(Rect &r1, Rect &r2) {
    float area1 = (r1.x2 - r1.x1) * (r1.y2 - r1.y1), area2 = (r2.x2 - r2.x1) * (r2.y2 - r2.y1);
    float xx1 = max(r1.x1, r2.x1), yy1 = max(r1.y1, r2.y1), xx2 = min(r1.x2, r2.x2), yy2 = min(r1.y2, r2.y2);
    float w = max(0.0f, xx2 - xx1), h = max(0.0f, yy2 - yy1);
    float inter_area = h * w, union_area = area1 + area2 - inter_area;
    return inter_area / union_area;
}

//vector<Rect> Interface::nms(vector<Rect> &rects, vector<float> &confs, float conf_thresh, float iou_thresh) {
vector<BBox> Interface::nms(vector<Rect> &rects, vector<float> &confs, float conf_thresh, float iou_thresh) {
    vector<BBox> bboxes;
    BBox bbox;
    vector<int> keep_idx;
//    vector<Rect> ans;
    vector<BBox> ans;
    for (int i = 0; i < (int)rects.size(); ++i) {
        bboxes.push_back(BBox(i, confs[i], rects[i]));
    }
    // 对bbox的conf进行降序排序
    sort(bboxes.begin(), bboxes.end(), [&](const BBox& a, const BBox& b) {
        return a.conf > b.conf;
    });
    while (!bboxes.empty()) {
        bbox = bboxes[0];
        if (bbox.conf < conf_thresh) {
            break;
        }
        keep_idx.emplace_back(bbox.idx);
        bboxes.erase(bboxes.begin());
        // 让conf最高的bbox与其他剩余的bbox进行iou计算
        int size = bboxes.size();
        for (int i = 0; i < size; ++i) {
            float iou_ans = iou(bbox.rect, bboxes[i].rect);
            if (iou_ans > iou_thresh) {
                bboxes.erase(bboxes.begin() + i);
                size = bboxes.size();
                i = i - 1;
            }
        }
    }
//    for (const int number : keep_idx) {
//        ans.push_back(rects[number]);
//    }
    for (const int number : keep_idx) {
//        ans.push_back(rects[number]);
        BBox a;
        a.conf = confs[number];
        a.idx = number;
        a.rect = rects[number];
        ans.push_back(a);
    }
    return ans;
}

