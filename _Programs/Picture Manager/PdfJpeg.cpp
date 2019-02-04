#include "PdfJpeg.h"

PdfJpeg::PdfJpeg(void):weidth(0),height(0),buffer(NULL),length(0),file(NULL),name(NULL)
{
}

PdfJpeg::~PdfJpeg(void)
{
	delete[]buffer;
}

int PdfJpeg::ReadImage()
{
	if(file==NULL)
		return -1;
	if(strrchr(file,'.'))
		name=strrchr(file,'.')+1;
	if(!strcmp(name,".jpg")||!strcmp(name,".JPG"))
	{
		printf("%s�ļ�,δ��֧�ָ�ʽ \n" ,file);
		return -1;
	}
	//��ȡ�ļ���
	if(strrchr(file,'\\'))
		name=strrchr(file,'\\')+1;
	else
		name=file;
	//��ȡjpeg����
	FILE *filejpeg;
	errno_t err=fopen_s(&filejpeg,file,"rb");
	//filejpeg = fopen_s(file, "rb");
	if(NULL == filejpeg)
	{
		printf("��ȡ%s�ļ�,��������\n" ,file);
		return -1;
	}
	fseek(filejpeg,0,SEEK_END);
	length=ftell(filejpeg);
	buffer=new unsigned char[length];
	fseek(filejpeg,0,SEEK_SET);
	fread(buffer,length,1,filejpeg);
	fclose(filejpeg);
	return GetSize(buffer,length);
}

int PdfJpeg::GetSize(unsigned char * buffer,long length)
{
	if(!buffer)
		return -1;
	unsigned char * temp=buffer+length,*temp1=buffer;
	unsigned char ff,type=0xff;
	int m_ret=-1,m_pos=0,m_hpx=0,m_wpx=0,uits=0;
	if(*buffer++!=0xff||*buffer++!=0xd8)
	{
		printf("�˷�jepgͼƬ\n");
		return -1;
	}
	while(temp>buffer&&type!=0xDA)
	{
		do 
		{
			ff=*buffer++;
		} while (ff!=0xff);
		do 
		{
			type=*buffer++;
		} while (type==0xff);
		switch(type)
		{
		case 0x00:
		case 0x01:
		case 0xD0:
		case 0xD1:
		case 0xD2:
		case 0xD3:
		case 0xD4:
		case 0xD5:
		case 0xD6:
		case 0xD7:
			break;
		case 0xC0://SOF0��
			temp1=buffer;
			m_pos=(*buffer++)<<8;
			m_pos+=*buffer++;
			buffer++; //��������ֵ
			height=(*buffer++)<<8;
			height+=*buffer++;
			weidth=(*buffer++)<<8;
			weidth+=*buffer;
			m_ret++;
			break;
		case 0xE0: //APP0��
			temp1=buffer;
			m_pos=(*buffer++)<<8;
			m_pos+=*buffer++;
			buffer=buffer+7;        //����APP0���(5bytes)�Լ����汾��(1bytes)���ΰ汾��(1bytes)
			uits=*buffer++;  //0: �޵�λ,units=1:����/Ӣ��,units=2:����/����
			m_wpx=(*buffer++)<<8;
			m_wpx+=*buffer++;
			m_hpx=(*buffer++)<<8;
			m_hpx+=*buffer++;
			hpx=m_hpx*JepgSize(uits);
			wpx=m_wpx*JepgSize(uits);
			m_ret++;
			break;
		default:
			temp1=buffer;
			m_pos=(*buffer++)<<8;
			m_pos+=*buffer++;
			break;
		}
		buffer=temp1+m_pos;
	}
	return m_ret;
}