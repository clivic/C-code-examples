#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubFootPrintChina 对话框

class CSubFootPrintChina : public CDialogEx
{
	DECLARE_DYNAMIC(CSubFootPrintChina)

public:
	CSubFootPrintChina(CWnd* pParent = NULL);   // 标准构造函数
	CSubFootPrintChina(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//倒入圖list的構造函數
	virtual ~CSubFootPrintChina();

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
};
