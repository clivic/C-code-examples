#pragma once
#include "PictureInfoList.h"

// CSubMapChoose 对话框

class CSubMapChoose : public CDialogEx
{
	DECLARE_DYNAMIC(CSubMapChoose)

public:
	CSubMapChoose(CWnd* pParent = NULL);   // 标准构造函数
	CSubMapChoose(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//倒入圖list的構造函數,用來傳給對應的足跡
	virtual ~CSubMapChoose();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_MAP_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	//主窗口傳來的PictureInfoList
	PictureInfoList *picListptr;
public:
	afx_msg void OnBnClickedRadioEcnu();
	afx_msg void OnBnClickedRadioChina();
};
