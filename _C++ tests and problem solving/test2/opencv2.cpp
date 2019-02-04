#include <cv.h>
#include <highgui.h>

using namespace std;

int main()
{
	IplImage *test;
	test = cvLoadImage("C:\\Users\\Lenovo\\Pictures\\day of defeat.jpg");//Í¼Æ¬Â·¾¶
	cvNamedWindow("day of defeat", 1);
	cvShowImage("day of defeat", test);
	cvWaitKey(0);
	cvDestroyWindow("day of defeat");
	cvReleaseImage(&test);
	return 0;
}
