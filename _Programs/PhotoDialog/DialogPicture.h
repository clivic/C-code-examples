#pragma once
#include  "afxwin.h"


// CDialogPicture �Ի���

class CDialogPicture : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPicture)

public:
	CDialogPicture(CWnd*pParent = NULL);   // ��׼���캯��
	virtual ~CDialogPicture();

// �Ի�������
	enum { IDD = IDD_DIALOG_PICTURE };

protected:
	virtual void DoDataExchange(CDataExchange*pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	CString filenames[10];	//ͼƬ�ļ���ַ
	int currentPage;		//��ǰҳ��
	int numInPages;			//ÿҳ��ͼƬ��Ŀ
	int count;				//�ܵ�ͼƬ��Ŀ
	
public:
//	afx_msg void OnStnClickedStaticPic4();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedPrevious();
	void drawPicture(CStatic*m_Pic/*�ؼ�����*/, int no/*�ؼ����0-n-1*/);
	
	
	afx_msg void OnPaint();
//	afx_msg void OnStnClickedStaticPic1();
//	afx_msg void OnStnDblclickStaticPic2();
//	afx_msg void OnStnDblclickStaticPic1();
//	afx_msg void OnStnDblclickStaticPic3();
//	afx_msg void OnStnDblclickStaticPic4();
	afx_msg void OnStnClickedStaticPic1();
	afx_msg void OnStnClickedStaticPic2();
	afx_msg void OnStnClickedStaticPic3();
	afx_msg void OnStnClickedStaticPic4();
};
