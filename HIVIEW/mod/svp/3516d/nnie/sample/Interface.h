//
// Created by ljh on 2021/11/30.
//

#ifndef INTERFACE_INTERFACE_H
#define INTERFACE_INTERFACE_H
#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>
#include "json.hpp"
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <istream>
using json = nlohmann::json;
using namespace std;
class Interface {
public:
    Interface();
    int ReadJson(string path,json& all_info);
    int ParseJson(string pic_path,string save_path, string json_path);
};


#endif //INTERFACE_INTERFACE_H
