#pragma once
#include "afxwin.h"
#include "PictureInfoList.h"


// CSubSurf �Ի���

class CSubSurf : public CDialogEx
{
	DECLARE_DYNAMIC(CSubSurf)

public:
	CSubSurf(CWnd* pParent = NULL);   // ��׼���캯��
	CSubSurf(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL); // ����Dlist�Ę��캯��
	virtual ~CSubSurf();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_SURF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	//CStatic m_pic;
	CString m_filename;
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	CStatic m_pic5;
	CStatic m_pic6;
	CStatic m_pic7;
	CStatic m_pic8;
	CStatic m_pic9;
	CStatic m_pic10;
	CStatic m_pic11;
	CStatic m_pic12;
	CStatic m_pic13;
	CStatic m_pic14;
	CStatic m_pic15;
	CStatic m_pic16;
	CStatic m_pic17;
	CStatic m_pic18;
	CStatic m_pic19;
	CStatic m_pic20;
	CStatic m_pic21;
	CStatic m_pic22;
	CStatic m_pic23;
	CStatic m_pic24;
	CStatic m_pic25;

	//�����ڂ����PictureInfoList���Д��õ�isByName
	PictureInfoList *picListptr;

	//��Ƭ�������P
	CString filenames[3000];	//�DƬ�ļ���ַ(��������Ŀ�)
	int currentPage;			//��ǰ���̖
	int numInPages;				//ÿ퓈D��
	int count;					//�G�D��
	PictureRecord info;			//һ���D��Record
public:
	afx_msg void OnPaint();
	void DrawPicture(CStatic *m_Pic/*�ؼ����Q*/, int no/*�ؼ���̖0 .. numInPages-1*/);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSurfNext();
	afx_msg void OnBnClickedButtonSurfPrevious();

	afx_msg void OnStnClickedStaticPic1();
	afx_msg void OnStnClickedStaticPic2();
	afx_msg void OnStnClickedStaticPic3();
	afx_msg void OnStnClickedStaticPic4();
	afx_msg void OnStnClickedStaticPic5();
	afx_msg void OnStnClickedStaticPic6();
	afx_msg void OnStnClickedStaticPic7();
	afx_msg void OnStnClickedStaticPic8();
	afx_msg void OnStnClickedStaticPic9();
	afx_msg void OnStnClickedStaticPic10();
	afx_msg void OnStnClickedStaticPic11();
	afx_msg void OnStnClickedStaticPic12();
	afx_msg void OnStnClickedStaticPic13();
	afx_msg void OnStnClickedStaticPic14();
	afx_msg void OnStnClickedStaticPic15();
	afx_msg void OnStnClickedStaticPic16();
	afx_msg void OnStnClickedStaticPic17();
	afx_msg void OnStnClickedStaticPic18();
	afx_msg void OnStnClickedStaticPic19();
	afx_msg void OnStnClickedStaticPic20();
	afx_msg void OnStnClickedStaticPic21();
	afx_msg void OnStnClickedStaticPic22();
	afx_msg void OnStnClickedStaticPic23();
	afx_msg void OnStnClickedStaticPic24();
	afx_msg void OnStnClickedStaticPic25(); 

};
