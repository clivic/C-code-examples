#pragma once


// CDialogResult 对话框

class CDialogResult : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogResult)

public:
	CDialogResult(CWnd*pParent = NULL);   // 标准构造函数
	virtual ~CDialogResult();

// 对话框数据
	enum { IDD = IDD_DIALOG_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange*pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
