
// DlgProxy.cpp : 實作檔
//

#include "stdafx.h"
#include "MainUI.h"
#include "DlgProxy.h"
#include "MainUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainUIDlgAutoProxy

IMPLEMENT_DYNCREATE(CMainUIDlgAutoProxy, CCmdTarget)

CMainUIDlgAutoProxy::CMainUIDlgAutoProxy()
{
	EnableAutomation();
	
	// 若要保持應用程式執行的時間與 Automation 物件作用的時間一樣長，
	//	 建構函式必須呼叫 AfxOleLockApp。
	AfxOleLockApp();

	// 經由應用程式主視窗指標，取得對對話方塊的存取。
	// 將 Proxy 的內部指標設定為指向對話方塊，
	// 並設定指向此 Proxy 的
	// 對話方塊返回指標。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CMainUIDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMainUIDlg)))
		{
			m_pDialog = reinterpret_cast<CMainUIDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CMainUIDlgAutoProxy::~CMainUIDlgAutoProxy()
{
	// 若要在使用 Automation 建立了所有物件之後結束應用程式，
	//	 解構函式必須呼叫 AfxOleUnlockApp。
	// 此外，這會摧毀主對話方塊
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMainUIDlgAutoProxy::OnFinalRelease()
{
	// 當釋放 Automation 物件最後的參考時，
	// 會呼叫 OnFinalRelease。基底類別會自動
	// 刪除物件。呼叫基底類別前，請先加入您物件所需的額外清除 (Cleanup)
	// 程式碼。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMainUIDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMainUIDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我們加入了對 IID_IMainUI 的支援
// 以便從 VBA 支援類型安全繫結。此 IID 必須與 .IDL 檔中，
// 附加至分配介面 (Dispinterface) 的 GUID 相符。

// {1DBA136B-0F19-4980-B86E-C08CF6880407}
static const IID IID_IMainUI =
{ 0x1DBA136B, 0xF19, 0x4980, { 0xB8, 0x6E, 0xC0, 0x8C, 0xF6, 0x88, 0x4, 0x7 } };

BEGIN_INTERFACE_MAP(CMainUIDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMainUIDlgAutoProxy, IID_IMainUI, Dispatch)
END_INTERFACE_MAP()

// 在此專案的 StdAfx.h 中定義 IMPLEMENT_OLECREATE2 巨集
// {9E4494A9-A9A1-461D-8B81-E1EB4739E618}
IMPLEMENT_OLECREATE2(CMainUIDlgAutoProxy, "MainUI.Application", 0x9e4494a9, 0xa9a1, 0x461d, 0x8b, 0x81, 0xe1, 0xeb, 0x47, 0x39, 0xe6, 0x18)


// CMainUIDlgAutoProxy 訊息處理常式
