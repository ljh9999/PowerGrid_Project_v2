#include "Interface.h"
#include "json.hpp"
using namespace std;

int main() {

    /// step1 先获得一些框，然后取相交
    auto anInterface = Interface();
    const std::string name1 = "image";
    cv::namedWindow(name1, cv::WINDOW_AUTOSIZE);

    const std::string name2 = "image2";
    cv::namedWindow(name2, cv::WINDOW_AUTOSIZE);

    vector<vector<int>> loc_tl{
            {478, 528}, {185, 525}, {423, 489}, {200, 474}, {595, 467}, {488, 467}, {313, 454}, {391, 442}, { 244, 435}, {240, 418},
            {431, 404}, {437, 403}, {352, 403}, {365, 343}, {303, 338}, {436, 331}, {343, 331}, {222, 318}, {353, 258}, {241, 163}
    };
    vector<vector<int>> loc_dr{
            {494, 552}, {201, 556}, {485, 509}, {222, 524}, {613, 495}, {544, 511}, {340, 481}, {423, 507}, {308, 490}, {264, 475},
            {468, 471}, {459, 447}, {385, 457}, {382, 370}, {335, 373}, {459, 350}, {365, 362}, {294, 485}, {391, 298}, {542, 429}
    };
    cv::Mat img(1080, 1920, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat img2(1080, 1920, CV_8UC3, cv::Scalar(255, 255, 255));
    int points = loc_dr.size();
    for(int i = 0; i < points; i++){
        cv::rectangle(img, cv::Point(loc_tl[i][0], loc_tl[i][1]), cv::Point(loc_dr[i][0], loc_dr[i][1]), (0,0,0), 2);
    }
    /// step1 合并
    vector<vector<int>> boxes_list;

    anInterface.inter_rec(loc_tl, loc_dr,boxes_list);

    points = boxes_list.size();
    for(int i = 0; i < points; i++){
//        cout << cv::Point(loc_tl_res[i][0], loc_tl_res[i][1]) << cv::Point(loc_dr_res[i][0], loc_dr_res[i][1]) << endl;
        cv::rectangle(img2, cv::Point(boxes_list[i][0], boxes_list[i][1]), cv::Point(boxes_list[i][2], boxes_list[i][3]), (0,0,255), 2);
    }

    cv::imshow(name1, img);
    cv::imshow(name2, img2);
    cv::imwrite("aa.jpg", img2);
    cv::waitKey();

    /// step2 贴图Paste_canvas
    int page_num = 1;  // 从第一页
    json all_context_info; // 记录位置信息
    vector<cv::Mat> canvas_list; // 记录图片信息
    anInterface.Paste_canvas(img2, boxes_list, page_num, all_context_info, canvas_list,"xdfile.json");

    /// step3 解析ParseJson
    anInterface.ParseJson("aa.jpg","xdfile.json");

    return 0;
}

