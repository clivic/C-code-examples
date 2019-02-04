//图像的轮廓检测
#include <opencv2/opencv.hpp> 
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//全局變量
IplImage *pSrcImage;
IplImage *pGrayImage;
IplImage *pBinaryImage;
IplImage *pOutlineImage;
CvMemStorage *pcvMStorage;

//滾動條控制
void OnTrackbar(int pos)
{
	cvThreshold(pGrayImage, pBinaryImage, pos, 255, CV_THRESH_BINARY);
	
	//檢索輪廓并返回檢索到的輪廓個數
	pcvMStorage = cvCreateMemStorage();					//存儲輪廓的容器,創建了即可也許
	CvSeq *pcvSeq = NULL;								//輸出的輪廓鏈錶
	cvFindContours(pBinaryImage, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

	//畫輪廓圖
	pOutlineImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 3);
	int nLevels = 5;									//繪製輪廓之層數

	//將之填充成白色
	cvRectangle(pOutlineImage, cvPoint(0, 0), cvPoint(pOutlineImage->width, pOutlineImage->height), CV_RGB(255, 255, 255), CV_FILLED);

	//繪製上輪廓
	cvDrawContours(pOutlineImage, pcvSeq, CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), nLevels, 2);
}

int main(int argc, char** argv)
{
	const char *pstrWindowsSrcTitle = "原图";
	const char *pstrWindowsOutlineTitle = "轮廓图";

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 200;

	//創建圖像
	pSrcImage = cvCreateImage(cvSize(IMAGE_WIDTH, IMAGE_HEIGHT), IPL_DEPTH_8U, 3);

	//將之填充成白色
	cvRectangle(pSrcImage, cvPoint(0, 0), cvPoint(pSrcImage->width, pSrcImage->height), CV_RGB(255, 255, 255), CV_FILLED);//此函數類似於MFC中的塗色函數也許

	//畫兩個同心圓
	CvPoint ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
	int nRadius = 80;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 0), CV_FILLED);//此函數也類似於MFC中的塗色函數也許
	ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
	nRadius = 30;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 255), CV_FILLED);

	//畫兩個矩形
	CvPoint ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 20, 20);
	CvPoint ptRightBottom = cvPoint(IMAGE_WIDTH - 20, IMAGE_HEIGHT - 20);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(0, 255, 255), CV_FILLED);
	ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 60, 40);
	ptRightBottom = cvPoint(IMAGE_WIDTH - 60, IMAGE_HEIGHT - 40);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(255, 255, 255), CV_FILLED);

	//顯示原圖
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsSrcTitle, pSrcImage);

	//先轉為灰度圖(這樣才能轉為二值圖,從而進行輪廓檢測)
	pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY);	//轉色函數

	//滾動條之處理
	int nThreshold = 250;
	const char *pstrWindowsToolBar = "ToolBar";

	//轉為二值圖
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);
	OnTrackbar(nThreshold);

	//顯示輪廓圖
	cvNamedWindow(pstrWindowsOutlineTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsOutlineTitle, pOutlineImage);
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsOutlineTitle, &nThreshold, 254, OnTrackbar);//上滾動條

	//後處理
	cvWaitKey();
	cvReleaseMemStorage(&pcvMStorage);
	cvDestroyWindow(pstrWindowsOutlineTitle);
	cvDestroyWindow(pstrWindowsSrcTitle);
	cvReleaseImage(&pBinaryImage);
	cvReleaseImage(&pGrayImage);
	cvReleaseImage(&pSrcImage);
	cvReleaseImage(&pOutlineImage);
	return 0;
}