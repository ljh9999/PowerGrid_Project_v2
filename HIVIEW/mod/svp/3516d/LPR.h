#ifndef __LPR_H
#define __LPR_H

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#else
#include <strings.h>
#endif

#ifdef _WIN32  
#define DLL_DECLARE __declspec(dllexport)  
#else  
#define DLL_DECLARE  
#endif 
#define MAX_PLATE_NUM 6
#define LPR_PLATE_NUM_LEN     16
#define LPR_COLOR_LEN         8

//ͼ���ʽ
#define LPR_BGR               0
#define LPR_YUV420P           1
#define LPR_YUV422P           2
#define LPR_UYVY422           3
#define LPR_YUV420SP          4


//ʶ��ʽ
#define   LPR_NORMAL          0
#define   LPR_FAST            1

//��������
typedef struct tag_LPR_RECT
{
	int m_iLeft;        //���
	int m_iTop;         //�ϱ�
	int m_iRight;       //�ұ�
	int m_iBottom;      //�±�
}LPR_RECT,*pLPR_RECT;

//ʶ����
typedef struct tag_LPR_Result
{
	char 	  m_cPlatenum[LPR_PLATE_NUM_LEN];		//���ƺ���
	char 	  m_cPlatecolor[LPR_COLOR_LEN];  		//������ɫ
	float     m_fPlaterealty;   					//�������Ŷ�
	LPR_RECT  m_fPlaterect ;  					    //��������
	int       m_iPlatetype ;                       //��������
	float 	  m_fLetterrealty[LPR_PLATE_NUM_LEN];	//�ַ����Ŷ�
	float     m_fVertangle;                        //��ֱ�Ƕ�
	float     m_fHorzangle;                        //ˮƽ�Ƕ�
	//int       m_iPlatecolor;                        //0---"��",1--- "��",2--- "��3----", "��", 4-----"��"
}LPR_Result, *pLPR_Result;

typedef void (*LprEventCallBack)(LPR_Result *pPlateRet,int iPlateNum,void *pData);




/*-------------------------------------------------------------------
��������liblpr_Init SDK��ʼ��
��������nMaxWidth: ����ͼ�����������
		        nMaxHeight: ����ͼ���������߶�
		        pPath -----keyĿ¼·��(�ɶ�д)
                    ����ֵ: NULL-----ʧ�ܷ�NULL ---�ɹ�
 �衡��: ֻ���ڴ˽ӿڵ��óɹ�����ܵ���ʶ��ӿ�
-------------------------------------------------------------------*/

#if defined(ANDROID) || defined(__ANDROID__)
DLL_DECLARE void *  liblpr_Init(int nMaxWidth, int nMaxHeight);
#else
DLL_DECLARE void *  liblpr_Init(int nMaxWidth, int nMaxHeight,char *pPath);
#endif


/*-------------------------------------------------------------------
������:liblpr_Recognition
��������
                    LPR_Handle:LPR_Init�����ķ���ֵ
    			RecogType: ����ʶ��ʽ LPR_NORMAL---��ͨLPR_FAST---����
    			pImage: ����ͼ������
    			ImageFormat:  �����ͼ���ʽ����ο�ǰ��ĺ궨��
    			                     LPR_BGR-----RGB888
    			                     LPR_YUV420P-----YUV420P
    			                     LPR_UYVY422-----YUV422
    			                     LPR_YUV420SP----YUV420SP
    			nWidth: ����ͼ����(������Ϊ��λ)
    			nHeight: ����ͼ��߶�(������Ϊ��λ)
    			rcRange: ����ʶ��Χ(������Ϊ��λ)Ҫ������
    			             0<rcRange.m_iLeft<rcRange.m_iRight<nWidth
    			             0<rcRange.m_iTop<rcRange.m_Bottom<nHeight
    			             
    			pPlateResult: ���ʶ�����ڴ��ɵ���������
    			pPlateNum: �����趨ʶ���Ƹ��� ���ʵ��ʶ���Ƹ���
����ֵ: ����0���ɹ� С�ڵ���0��ʧ��
�衡��: ����ʶ��ӿ�
//-------------------------------------------------------------------*/
DLL_DECLARE int liblpr_Recognition(void *  LPR_Handle, int RecogType, unsigned char *pImage, int ImageFormat, int nWidth, int nHeight, LPR_RECT rcRange, LPR_Result *pPlateResult, int *pPlateNum);

/*-------------------------------------------------------------------
��������LPR_UnInit
��������LPR_Handle :LPR_Init�����ķ���ֵ
����ֵ: ��
�衡��:����ʶ���ķ���ʼ���ӿ�
-------------------------------------------------------------------*/
DLL_DECLARE void  liblpr_UnInit(void * LPR_Handle);



DLL_DECLARE int  liblpr_GetDevID(char * pDevID);




#ifdef __cplusplus
}
#endif

#endif 
