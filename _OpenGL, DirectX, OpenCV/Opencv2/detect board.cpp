//ͼ���Canny��Ե����c�D��Ķ�ֵ��
#include <cv.h>
#include <highgui.h>
using namespace std;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

//ȫ��׃��

//߅���z�y
IplImage *pSrcImage, *pCannyImg;
const char *pstrWindowsCannyTitle = "��Ե���ͼ";
IplImage *pBinaryImage = NULL;

//��ֵ��
IplImage *pGrayImage = NULL;
const char *pstrWindowsBinaryTitle = "��ֵ�D";

//cvCreateTrackbar�Ļص����� -- ָ���ֵ��
void OnTrackbarCanny(int threshold)
{
	cvCanny(pSrcImage, pCannyImg, threshold, threshold * 3, 3);	//��pSrcImage�M��߅���z�y,ݔ�͵�pCannyImg��
	cvShowImage(pstrWindowsCannyTitle, pCannyImg);
}

//ͨ�^threshold������pGrayImage�D�Q���ֵ�D(ֻ���ǻҶȈD)
void OnTrackbarThreshold(int pos)
{
	cvThreshold(pGrayImage, pBinaryImage, pos, 255, CV_THRESH_BINARY);
	cvShowImage(pstrWindowsBinaryTitle, pBinaryImage);
}

int main()
{
	//�D���߅���z�y
	const char *pstrImageName = "C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg";
	const char *pstrWindowsSrcTitle = "ԭ�D";
	const char *pstrWindowsToolBar = "Threshold";

	//���ļ�������ͼ��ĻҶ�ͼCV_LOAD_IMAGE_GRAYSCALE - �Ҷ�ͼ 
	pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_GRAYSCALE);	//ԭ�D֮�ҶȈD
	pCannyImg = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);	//�O��ԭ�D֮�ߴ�

	//��������
	cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);			//߅���z�y�D֮����
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);				//ԭ�D֮����

	//����������trackbar
	int nThresholdEdge = 1;
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsCannyTitle, &nThresholdEdge, 100, OnTrackbarCanny);	//���л��ӗlλ�ø�׃����OnTrackbarCanny()

	//���@ʾԭ�D
	cvShowImage(pstrWindowsSrcTitle, pSrcImage);
	OnTrackbarCanny(1);		//�ֵ1��߅���z�y,����������

	//***************************************************************
	//ͼ��Ķ�ֵ�� 
	//��Ȼ��߅��̎����d֮ԭ�D
	pGrayImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_GRAYSCALE);
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);	//�O�ûҶȈD֮�ߴ�

	//������ֵ�D����
	cvNamedWindow(pstrWindowsBinaryTitle, CV_WINDOW_AUTOSIZE);

	//�������ӗl
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsBinaryTitle, &nThresholdEdge, 254, OnTrackbarThreshold);

	OnTrackbarThreshold(1);		//�ֵ1�Ķ�ֵ��,����������

	//��̎��
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
