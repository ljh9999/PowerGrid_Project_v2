//
// Created by ljh on 2021/11/30.
//

#ifndef INTERFACE_INTERFACE_H
#define INTERFACE_INTERFACE_H
#include "opencv2/opencv.hpp"
//#include <iostream>
#include <math.h>
#include "json.hpp"
#include <list>
#include <fstream>
#include <istream>
#include "base64.h"
using namespace std;
using json = nlohmann::json;
struct Rect {
    float x1;
    float y1;
    float x2;
    float y2;
    Rect() :x1(0), y1(0), x2(0), y2(0) {}
    Rect(float x1, float y1, float x2, float y2) :x1(x1), y1(y1), x2(x2), y2(y2) {}
};
struct BBox {
    int idx;
    float conf;
    Rect rect;
    BBox() :idx(0), conf(0), rect(0, 0, 0, 0) {}
    BBox(int idx, float conf, Rect rect) : idx(idx), conf(conf), rect(rect) {}
};

class Interface {
public:
    Interface();
//    int inter_rec(vector<vector<int>> loc_tl, vector<vector<int>> loc_dr,vector<vector<int>>& boxes_list);
//    int Ini_canvas();
//    int SaveJson();
    int ReadJson(string path,json& all_info);
//    int Paste_canvas(cv::Mat img ,vector<vector<int>>& boxes_list, int page_num, json& all_context_info, vector<cv::Mat>& canvas_list,string json_path);
//    int Recur_Paste(cv::Mat img, list<vector<int>>& boxes_list,int page_num, json& all_context_info,vector<cv::Mat>& canvas_list,string json_path);
    int ParseJson(string pic_path,string save_path, string json_path);
//    新增一个计算mAP的功能
//private:
//    cv::Mat _canvas;
    float iou(Rect& r1, Rect& r2);
//    vector<Rect> nms(vector<Rect>& rects, vector<float>& confs, float conf_thresh = 0.5, float iou_thresh = 0.5);
    vector<BBox> nms(vector<Rect>& rects, vector<float>& confs, float conf_thresh = 0.5, float iou_thresh = 0.5);
};


#endif //INTERFACE_INTERFACE_H
