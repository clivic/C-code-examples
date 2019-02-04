
// PhotoDialogDlg.h : 標頭檔
//

#pragma once
#include  <fstream>
#include  <atlimage.h>
#include  "DialogPicture.h"
using namespace std;

// CPhotoDialogDlg 對話方塊
class CPhotoDialogDlg : public CDialogEx
{
// 建構
public:
	CPhotoDialogDlg(CWnd*pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_PHOTODIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange*pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditSearch();
	
	// TODO:  在此加入額外的初始設定
	void drawPicture(CStatic *m_Pic/*控件名称*/, int no/*控件編號0- numInPages -1*/);

	

	
	afx_msg void OnBnClickedMulti();
};
