#pragma once
#include <string.h>
#include <stdio.h>
#pragma warning(disable: 4244)

class PdfJpeg
{
public:
	PdfJpeg(void);
	~PdfJpeg(void);
	PdfJpeg( char *filename):
	weidth(0),height(0),buffer(NULL),length(0),file(filename?filename:NULL),name(NULL){}
private:
	//jpeg���
	int weidth; 
	//jpeg�߶�
	int height; 
	 //jpeg����
	unsigned char *buffer;
	//jpeg���ݳ���
	long length; 
	//jpeg�ļ�����·��
	char *file;  
	//jpeg�ļ���
	char *name;  
	PdfJpeg& operator=(const PdfJpeg &j);
	//��ȡjpegͼƬ�ߴ�
	int GetSize(unsigned char * buffer,long length);
	float inline JepgSize(int x)
	{
		return x!=2?1:2.56;
	}
	//��ֱ���ص�
	float hpx;
	//ˮƽ���ص�
	float wpx;
public:
	//��ȡjpeg�ļ�,ʧ�ܷ���-1,�ɹ�����1
	int ReadImage();
	int inline GetWidth() const
	{
		return weidth;
	}

	int inline GetHeight() const
	{
		return height;
	}

	unsigned char inline *GetData() const
	{
		return buffer;
	}

	long inline GetDataLength() const
	{
		return length;
	}

	char * GetFileName() const
	{
		return name;
	}

	float inline GetHDpi()
	{
		return hpx;
	}

	float inline GetWDpi()
	{
		return wpx;
	}

};
