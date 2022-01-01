#ifndef __VPSS_CAPTURE_H
#define __VPSS_CAPTURE_H

#include <stdio.h>
#include <stdbool.h>
#include "hi_comm_svp.h"
#include "sample_comm.h"
#include "sample_comm_svp.h"
#include "sample_comm_ive.h"
#include <opencv2/opencv.hpp>

#define VALUE_BETWEEN(x,min,max) (((x)>=(min)) && ((x) <= (max)))

typedef struct hiDUMP_MEMBUF_S
{
    VB_BLK  hBlock;
    VB_POOL hPool;
    HI_U32  u32PoolId;

    HI_U64  u64PhyAddr;
    HI_U8*   pVirAddr;
    HI_S32  s32Mdev;
} DUMP_MEMBUF_S;

class VpssCapture
{
public:

    int init(int VpssGrp, int VpssChn);
    int get_frame(cv::Mat &frame);
    int get_frame_lock(cv::Mat &frame, VIDEO_FRAME_INFO_S **pstFrame);
    int get_frame_unlock(VIDEO_FRAME_INFO_S *pstFrame);
    int destroy();

private:
    int YUV2Mat(VIDEO_FRAME_S* pVBuf, cv::Mat &img);
    void VPSS_Chn_Dump_HandleSig(HI_S32 signo);
    HI_S32 VPSS_Restore(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);

private:

    IVE_DST_IMAGE_S stDst;
    VPSS_GRP VpssGrp = 0;
    VPSS_CHN VpssChn = 0;
    HI_U32 u32OrigDepth = 0;

    HI_S32 s32MilliSec = -1;
    HI_U32 u32VpssDepthFlag = 0;
    HI_U32 u32SignalFlag = 0;
    VIDEO_FRAME_INFO_S stFrame;

    HI_U32  u32BlkSize = 0;
    VGS_HANDLE hHandle = -1;
    DUMP_MEMBUF_S stMem = {0};
    VB_POOL hPool  = VB_INVALID_POOLID;

    HI_U32 u32Size = 0;
    HI_CHAR* pUserPageAddr[2] = {HI_NULL, HI_NULL};

    unsigned int frame_id = 0;
    unsigned int frame_lock = 0;
};


#endif

