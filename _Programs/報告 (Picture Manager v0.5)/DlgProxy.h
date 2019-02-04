
// DlgProxy.h: 標頭檔
//

#pragma once

class CPictureManagerDlg;


// CPictureManagerDlgAutoProxy 命令目標

class CPictureManagerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CPictureManagerDlgAutoProxy)

	CPictureManagerDlgAutoProxy();           // 動態建立所使用的保護建構函式

// 屬性
public:
	CPictureManagerDlg* m_pDialog;

// 作業
public:

// 覆寫
	public:
	virtual void OnFinalRelease();

// 程式碼實作
protected:
	virtual ~CPictureManagerDlgAutoProxy();

	// 產生的訊息對應函式

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPictureManagerDlgAutoProxy)

	// 產生的 OLE 分派對應函式

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

