#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubMapECNU 对话框

class CSubMapECNU : public CDialogEx
{
	DECLARE_DYNAMIC(CSubMapECNU)

public:
	CSubMapECNU(CWnd* pParent = NULL);					//标准构造函数
	CSubMapECNU(CWnd* pParent, PictureInfoList *pLPtr);	//將父窗口的List傳過來
	virtual ~CSubMapECNU();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_ECNU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	LocationGraph<200> ecnuMap;
	PictureInfoList *picLibraryPtr;

public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
