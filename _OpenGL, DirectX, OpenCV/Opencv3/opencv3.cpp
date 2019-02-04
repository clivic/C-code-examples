//ͼ����������
#include <opencv2/opencv.hpp> 
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//ȫ��׃��
IplImage *pSrcImage;
IplImage *pGrayImage;
IplImage *pBinaryImage;
IplImage *pOutlineImage;
CvMemStorage *pcvMStorage;

//�L�ӗl����
void OnTrackbar(int pos)
{
	cvThreshold(pGrayImage, pBinaryImage, pos, 255, CV_THRESH_BINARY);
	
	//�z��݆�������ؙz������݆������
	pcvMStorage = cvCreateMemStorage();					//�惦݆��������,�����˼���Ҳ�S
	CvSeq *pcvSeq = NULL;								//ݔ����݆����l
	cvFindContours(pBinaryImage, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

	//��݆���D
	pOutlineImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 3);
	int nLevels = 5;									//�L�u݆��֮�Ӕ�

	//��֮���ɰ�ɫ
	cvRectangle(pOutlineImage, cvPoint(0, 0), cvPoint(pOutlineImage->width, pOutlineImage->height), CV_RGB(255, 255, 255), CV_FILLED);

	//�L�u��݆��
	cvDrawContours(pOutlineImage, pcvSeq, CV_RGB(255, 0, 0), CV_RGB(0, 255, 0), nLevels, 2);
}

int main(int argc, char** argv)
{
	const char *pstrWindowsSrcTitle = "ԭͼ";
	const char *pstrWindowsOutlineTitle = "����ͼ";

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 200;

	//�����D��
	pSrcImage = cvCreateImage(cvSize(IMAGE_WIDTH, IMAGE_HEIGHT), IPL_DEPTH_8U, 3);

	//��֮���ɰ�ɫ
	cvRectangle(pSrcImage, cvPoint(0, 0), cvPoint(pSrcImage->width, pSrcImage->height), CV_RGB(255, 255, 255), CV_FILLED);//�˺�������MFC�еĉTɫ����Ҳ�S

	//���ɂ�ͬ�ĈA
	CvPoint ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
	int nRadius = 80;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 0), CV_FILLED);//�˺���Ҳ����MFC�еĉTɫ����Ҳ�S
	ptCircleCenter = cvPoint(IMAGE_WIDTH / 4, IMAGE_HEIGHT / 2);
	nRadius = 30;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255, 255, 255), CV_FILLED);

	//���ɂ�����
	CvPoint ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 20, 20);
	CvPoint ptRightBottom = cvPoint(IMAGE_WIDTH - 20, IMAGE_HEIGHT - 20);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(0, 255, 255), CV_FILLED);
	ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 60, 40);
	ptRightBottom = cvPoint(IMAGE_WIDTH - 60, IMAGE_HEIGHT - 40);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(255, 255, 255), CV_FILLED);

	//�@ʾԭ�D
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsSrcTitle, pSrcImage);

	//���D��ҶȈD(�@�Ӳ����D���ֵ�D,�Ķ��M��݆���z�y)
	pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY);	//�Dɫ����

	//�L�ӗl֮̎��
	int nThreshold = 250;
	const char *pstrWindowsToolBar = "ToolBar";

	//�D���ֵ�D
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);
	OnTrackbar(nThreshold);

	//�@ʾ݆���D
	cvNamedWindow(pstrWindowsOutlineTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrWindowsOutlineTitle, pOutlineImage);
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsOutlineTitle, &nThreshold, 254, OnTrackbar);//�ϝL�ӗl

	//��̎��
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