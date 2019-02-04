#pragma once
#include  "afxwin.h"


// CDialogPicture 对话框

class CDialogPicture : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPicture)

public:
	CDialogPicture(CWnd*pParent = NULL);   // 标准构造函数
	virtual ~CDialogPicture();

// 对话框数据
	enum { IDD = IDD_DIALOG_PICTURE };

protected:
	virtual void DoDataExchange(CDataExchange*pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	CString filenames[10];	//图片文件地址
	int currentPage;		//当前页面
	int numInPages;			//每页的图片数目
	int count;				//总的图片数目
	
public:
//	afx_msg void OnStnClickedStaticPic4();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedPrevious();
	void drawPicture(CStatic*m_Pic/*控件名称*/, int no/*控件编号0-n-1*/);
	
	
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
