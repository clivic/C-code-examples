#include <cv.h>
#include <highgui.h>
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

int main()
{
	////顯示Day of Defeat Source
	//const char *pstrImageName = "C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg";
	//const char *pstrWindowsTitle = "day of defeat";

	////read image
	//IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);

	////create window
	//cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);

	////show image in the window
	//cvShowImage(pstrWindowsTitle, pImage);

	////wait for entering a key
	//cvWaitKey();

	////destructor(necessary perhaps)
	//cvDestroyWindow(pstrWindowsTitle);
	//cvReleaseImage(&pImage);

	//***************************************************************

	////縮放圖像
	//const char *pstrDefaultName = "day of defeat.jpg";
	//const char *pstrAfterName = "Day of Defeat Source.jpg";
	//const char *pstrDefaultWindowTitle = "原來的封面";
	//const char *pstrAfterWindowTitle = "縮放後封面";

	//double fScale = 0.314;      //缩放倍数
	//CvSize czSize;              //目标图像尺寸

	//const char *directory = "C:\\Users\\Lenovo\\Pictures\\" + *pstrDefaultName;
	//IplImage *pDefaultImage = cvLoadImage(directory, CV_LOAD_IMAGE_UNCHANGED);
	//IplImage *pAfterImage = NULL;

	////計算目標圖片之應有尺寸
	//czSize.height = (int)(pDefaultImage->height * fScale);
	//czSize.width = (int)(pDefaultImage->width * fScale);

	////大小確定
	//pAfterImage = cvCreateImage(czSize, pDefaultImage->depth, pDefaultImage->nChannels);
	//cvResize(pDefaultImage, pAfterImage, CV_INTER_LINEAR);

	////創建窗口
	//cvNamedWindow(pstrDefaultWindowTitle, CV_WINDOW_AUTOSIZE);
	//cvNamedWindow(pstrAfterWindowTitle, CV_WINDOW_AUTOSIZE);

	////在窗口中顯示圖像
	//cvShowImage(pstrDefaultWindowTitle, pDefaultImage);
	//cvShowImage(pstrAfterWindowTitle, pAfterImage);

	////等待按鍵
	//cvWaitKey();

	////保存縮放後之圖片
	//cvSaveImage(pstrAfterName, pAfterImage);

	////析構圖像
	//cvDestroyWindow(pstrAfterWindowTitle);
	//cvDestroyWindow(pstrDefaultWindowTitle);
	//cvReleaseImage(&pAfterImage);
	//cvReleaseImage(&pDefaultImage);

	//顯示Day of Defeat Source
	const char *pstrDefaultImageName = "C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg";
	const char *pstrDefaultWinTitle = "default";
	const char *pstrAfterImageName = "C:\\Users\\Lenovo\\Pictures\\Day of Defeat Source.jpg";
	const char *pstrAfterWinTitle = "after";

	double fScale = 0.5;		//缩放倍数
	CvSize czSize;				//目标图像尺寸

	//read default image
	IplImage *pImage = cvLoadImage(pstrDefaultImageName, CV_LOAD_IMAGE_UNCHANGED);

	//resize
	czSize.height = (int)(pImage->height * fScale);
	czSize.width = (int)(pImage->width * fScale);
	IplImage *pAfterImage = cvCreateImage(czSize, pImage->depth, pImage->nChannels);
	cvResize(pImage, pAfterImage, CV_INTER_AREA);

	//create window
	cvNamedWindow(pstrDefaultWinTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrAfterWinTitle, CV_WINDOW_AUTOSIZE);

	//show image in the window
	cvShowImage(pstrDefaultWinTitle, pImage);
	cvShowImage(pstrAfterWinTitle, pAfterImage);

	//wait for entering a key
	cvWaitKey();

	//save image
	cvSaveImage(pstrAfterImageName, pAfterImage);

	//destructor(necessary perhaps)
	cvDestroyWindow(pstrDefaultWinTitle);
	cvDestroyWindow(pstrAfterWinTitle);
	cvReleaseImage(&pImage);
	cvReleaseImage(&pAfterImage);
	return 0;
}