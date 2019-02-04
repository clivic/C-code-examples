#pragma once
#include "afxwin.h"
#include "PictureRecord.h"
#include "PictureInfoList.h"

// CSubGetOnePic 对话框

class CSubGetOnePic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubGetOnePic)

public:
	CSubGetOnePic(CWnd* pParent = NULL);				// 标准构造函数
	//CSubGetOnePic(CWnd* pParent, PictureRecord *rec);	// 傳圖片文件名以打開,1.0版功能,現在用不著了
	CSubGetOnePic(CWnd* pParent, PictureInfoList *ptr, const int &no);	//傳圖片list及該圖片的num
	virtual ~CSubGetOnePic();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DLG_DRAW_ONE_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	CStatic m_bigPic;
	CString title;
	CString m_name;
public:
	afx_msg void OnPaint();
private:
	//record記錄
	CString m_titleEn;
	CString m_owner;
	int m_height;
	int m_width;
	int m_size;
	CString m_detail;
	CString m_location;

	int currentNum;		//當前圖片號
	int count;			//縂圖數(picList的size)
	
	//SubSurf窗口傳來的PictureInfoList
	PictureInfoList *picListptr;
public:
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonPrevious();
};
