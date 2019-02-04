
// DlgProxy.h: 標頭檔
//

#pragma once

class CMainUIDlg;


// CMainUIDlgAutoProxy 命令目標

class CMainUIDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMainUIDlgAutoProxy)

	CMainUIDlgAutoProxy();           // 動態建立所使用的保護建構函式

// 屬性
public:
	CMainUIDlg* m_pDialog;

// 作業
public:

// 覆寫
	public:
	virtual void OnFinalRelease();

// 程式碼實作
protected:
	virtual ~CMainUIDlgAutoProxy();

	// 產生的訊息對應函式

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMainUIDlgAutoProxy)

	// 產生的 OLE 分派對應函式

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

