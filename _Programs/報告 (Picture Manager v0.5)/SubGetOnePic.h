#pragma once
#include "afxwin.h"
#include "PictureRecord.h"


// CSubGetOnePic 对话框

class CSubGetOnePic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubGetOnePic)

public:
	CSubGetOnePic(CWnd* pParent = NULL);				// 标准构造函数
	CSubGetOnePic(CWnd* pParent, PictureRecord *rec);	// 傳圖片文件名以打開
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
	CString m_titleEn;
	CString m_owner;
	int m_height;
	int m_width;
	int m_size;
	CString m_detail;
	CString m_location;
};
