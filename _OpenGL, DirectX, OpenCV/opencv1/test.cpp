#include <cv.h>
#include <highgui.h>
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

int main()
{
	////�@ʾDay of Defeat Source
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

	////�s�ňD��
	//const char *pstrDefaultName = "day of defeat.jpg";
	//const char *pstrAfterName = "Day of Defeat Source.jpg";
	//const char *pstrDefaultWindowTitle = "ԭ��ķ���";
	//const char *pstrAfterWindowTitle = "�s�������";

	//double fScale = 0.314;      //���ű���
	//CvSize czSize;              //Ŀ��ͼ��ߴ�

	//const char *directory = "C:\\Users\\Lenovo\\Pictures\\" + *pstrDefaultName;
	//IplImage *pDefaultImage = cvLoadImage(directory, CV_LOAD_IMAGE_UNCHANGED);
	//IplImage *pAfterImage = NULL;

	////Ӌ��Ŀ�ˈDƬ֮���гߴ�
	//czSize.height = (int)(pDefaultImage->height * fScale);
	//czSize.width = (int)(pDefaultImage->width * fScale);

	////��С�_��
	//pAfterImage = cvCreateImage(czSize, pDefaultImage->depth, pDefaultImage->nChannels);
	//cvResize(pDefaultImage, pAfterImage, CV_INTER_LINEAR);

	////��������
	//cvNamedWindow(pstrDefaultWindowTitle, CV_WINDOW_AUTOSIZE);
	//cvNamedWindow(pstrAfterWindowTitle, CV_WINDOW_AUTOSIZE);

	////�ڴ������@ʾ�D��
	//cvShowImage(pstrDefaultWindowTitle, pDefaultImage);
	//cvShowImage(pstrAfterWindowTitle, pAfterImage);

	////�ȴ����I
	//cvWaitKey();

	////����s����֮�DƬ
	//cvSaveImage(pstrAfterName, pAfterImage);

	////�����D��
	//cvDestroyWindow(pstrAfterWindowTitle);
	//cvDestroyWindow(pstrDefaultWindowTitle);
	//cvReleaseImage(&pAfterImage);
	//cvReleaseImage(&pDefaultImage);

	//�@ʾDay of Defeat Source
	const char *pstrDefaultImageName = "C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg";
	const char *pstrDefaultWinTitle = "default";
	const char *pstrAfterImageName = "C:\\Users\\Lenovo\\Pictures\\Day of Defeat Source.jpg";
	const char *pstrAfterWinTitle = "after";

	double fScale = 0.5;		//���ű���
	CvSize czSize;				//Ŀ��ͼ��ߴ�

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