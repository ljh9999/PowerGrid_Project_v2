#ifndef __YOLOV5C_H
#define __YOLOV5C_H

struct BoxInfo
{
	int label;
	float score;
	cv::Rect2f box;
};

class YOLOV5C
{
public:
    int init(char* model_path);
    int detect(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.3);
    int detect(unsigned char* imageStream, std::vector<BoxInfo> &bboxs, float threshold=0.3);
    int destroy();
//	int init(char* model_path);
//    int init(char *conn_model_path, char *bolt_model_path);
//	int detect(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.5, bool conn_flag=true);
//	int detect(unsigned char* imageStream, std::vector<BoxInfo> &bboxs, float threshold=0.3);
//	int destroy();

//    int init(char *conn_model_path, char *bolt_model_path);
//    int detect(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.3, bool conn_flag=true);
//    int detect(unsigned char* imageStream, std::vector<BoxInfo> &bboxs, float threshold=0.3, bool conn_flag=true);
//    int destroy();


//    int init_conn(char *conn_model_path, char *bolt_model_path);
//    int detect_conn(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.3);
//    // int detect_conn(unsigned char* imageStream, std::vector<BoxInfo> &bboxs, float threshold=0.3);
//    int destroy_conn();
//
//
//    int init_bolt(char *conn_model_path, char *bolt_model_path);
//    int detect_bolt(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.3);
//    // int detect_bolt(unsigned char* imageStream, std::vector<BoxInfo> &bboxs, float threshold=0.3);
//    int destroy_bolt();

};


#endif
