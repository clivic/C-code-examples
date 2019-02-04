
// MainUIDlg.h : 標頭檔
//

#pragma once
#include "PictureInfoList.h"

class CMainUIDlgAutoProxy;


// CMainUIDlg 對話方塊
class CMainUIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainUIDlg);
	friend class CMainUIDlgAutoProxy;

// 建構
public:
	CMainUIDlg(CWnd* pParent = NULL);	// 標準建構函式
	virtual ~CMainUIDlg();

// 對話方塊資料
	enum { IDD = IDD_PICTUREMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	CMainUIDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearchByTitle();

	//創建PictureInfoList對象以通用全局
	
	afx_msg void OnBnClickedButtonSearchByLoc();

private:
	PictureInfoList picLibrary;
public:
	afx_msg void OnBnClickedButtonAddpic();
	afx_msg void OnBnClickedButtonFootprint();
	afx_msg void OnBnClickedButtonTesttime();
	afx_msg void OnBnClickedButtonRevpic();
	afx_msg void OnBnClickedButtonDelpic();
	afx_msg void OnBnClickedButtonEditpic();
};
