#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"
#include "constants.h"

// CSubFootPrintECNU 对话框

class CSubFootPrintECNU : public CDialogEx
{
	DECLARE_DYNAMIC(CSubFootPrintECNU)

public:
	CSubFootPrintECNU(CWnd* pParent = NULL);					//标准构造函数
	CSubFootPrintECNU(CWnd* pParent, PictureInfoList *pLPtr);	//將父窗口的List傳過來
	virtual ~CSubFootPrintECNU();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_ECNU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	LocationGraph<FOOTPRINT_SIZE> ecnuMap;
	PictureInfoList *picLibraryPtr;

public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
