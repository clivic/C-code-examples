//图像的Canny边缘检测與圖像的二值化
#include <cv.h>
#include <highgui.h>
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

//全局變量

//邊緣檢測
IplImage *pSrcImage, *pCannyImg;
const char *pstrWindowsCannyTitle = "边缘检测图";
IplImage *pBinaryImage = NULL;

//二值化
IplImage *pGrayImage = NULL;
const char *pstrWindowsBinaryTitle = "二值圖";

//cvCreateTrackbar的回调函数 -- 指定閾值。
void OnTrackbarCanny(int threshold)
{
	cvCanny(pSrcImage, pCannyImg, threshold, threshold * 3, 3);	//對pSrcImage進行邊緣檢測,輸送到pCannyImg。
	cvShowImage(pstrWindowsCannyTitle, pCannyImg);
}

//通過threshold方法將pGrayImage轉換為二值圖(只能是灰度圖)
void OnTrackbarThreshold(int pos)
{
	cvThreshold(pGrayImage, pBinaryImage, pos, 255, CV_THRESH_BINARY);
	cvShowImage(pstrWindowsBinaryTitle, pBinaryImage);
}

int main()
{
	//圖像的邊緣檢測
	const char *pstrImageName = "C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg";
	const char *pstrWindowsSrcTitle = "原圖";
	const char *pstrWindowsToolBar = "Threshold";

	//从文件中载入图像的灰度图CV_LOAD_IMAGE_GRAYSCALE - 灰度图 
	pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_GRAYSCALE);	//原圖之灰度圖
	pCannyImg = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);	//設好原圖之尺寸

	//創建窗口
	cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);			//邊緣檢測圖之窗口
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);				//原圖之窗口

	//创建滑动条trackbar
	int nThresholdEdge = 1;
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsCannyTitle, &nThresholdEdge, 100, OnTrackbarCanny);	//其中滑動條位置改變就用OnTrackbarCanny()

	//先顯示原圖
	cvShowImage(pstrWindowsSrcTitle, pSrcImage);
	OnTrackbarCanny(1);		//閾值1的邊緣檢測,并創建窗口

	//***************************************************************
	//图像的二值化 
	//仍然用邊緣處理加載之原圖
	pGrayImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_GRAYSCALE);
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);	//設好灰度圖之尺寸

	//創建二值圖窗口
	cvNamedWindow(pstrWindowsBinaryTitle, CV_WINDOW_AUTOSIZE);

	//創建滑動條
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsBinaryTitle, &nThresholdEdge, 254, OnTrackbarThreshold);

	OnTrackbarThreshold(1);		//閾值1的二值化,并創建窗口

	//後處理
	cvWaitKey();
	cvDestroyWindow(pstrWindowsSrcTitle);
	cvDestroyWindow(pstrWindowsCannyTitle);
	cvDestroyWindow(pstrWindowsBinaryTitle);
	cvReleaseImage(&pSrcImage);
	cvReleaseImage(&pCannyImg);
	cvReleaseImage(&pBinaryImage);
	cvReleaseImage(&pGrayImage);
	return 0;
}
