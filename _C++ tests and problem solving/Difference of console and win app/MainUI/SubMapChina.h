#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubMapChina 对话框

class CSubMapChina : public CDialogEx
{
	DECLARE_DYNAMIC(CSubMapChina)

public:
	CSubMapChina(CWnd* pParent = NULL);   // 标准构造函数
	CSubMapChina(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//倒入圖list的構造函數
	virtual ~CSubMapChina();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_CHINA };

private:
	LocationGraph<200> chinaMap;
	PictureInfoList *picLibraryPtr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
