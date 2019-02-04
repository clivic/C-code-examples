
// DlgProxy.cpp : �����n
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
	
	// ��Ҫ���֑��ó�ʽ���еĕr�g�c Automation ������õĕr�gһ���L��
	//	 ������ʽ��횺��� AfxOleLockApp��
	AfxOleLockApp();

	// ���ɑ��ó�ʽ��ҕ��ָ�ˣ�ȡ�Ì���Ԓ���K�Ĵ�ȡ��
	// �� Proxy �ăȲ�ָ���O����ָ��Ԓ���K��
	// �K�O��ָ��� Proxy ��
	// ��Ԓ���K����ָ�ˡ�
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
	// ��Ҫ��ʹ�� Automation �������������֮��Y�����ó�ʽ��
	//	 �☋��ʽ��횺��� AfxOleUnlockApp��
	// ���⣬�@���ݚ�����Ԓ���K
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMainUIDlgAutoProxy::OnFinalRelease()
{
	// ��ጷ� Automation �������ą����r��
	// ������ OnFinalRelease������e���Ԅ�
	// �h����������л���eǰ��Ո�ȼ��������������~����� (Cleanup)
	// ��ʽ�a��

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMainUIDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMainUIDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: �҂������ˌ� IID_IMainUI ��֧Ԯ
// �Ա�� VBA ֧Ԯ��Ͱ�ȫ�M�Y���� IID ����c .IDL �n�У�
// ������������� (Dispinterface) �� GUID �����

// {1DBA136B-0F19-4980-B86E-C08CF6880407}
static const IID IID_IMainUI =
{ 0x1DBA136B, 0xF19, 0x4980, { 0xB8, 0x6E, 0xC0, 0x8C, 0xF6, 0x88, 0x4, 0x7 } };

BEGIN_INTERFACE_MAP(CMainUIDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMainUIDlgAutoProxy, IID_IMainUI, Dispatch)
END_INTERFACE_MAP()

// �ڴˌ����� StdAfx.h �ж��x IMPLEMENT_OLECREATE2 �޼�
// {9E4494A9-A9A1-461D-8B81-E1EB4739E618}
IMPLEMENT_OLECREATE2(CMainUIDlgAutoProxy, "MainUI.Application", 0x9e4494a9, 0xa9a1, 0x461d, 0x8b, 0x81, 0xe1, 0xeb, 0x47, 0x39, 0xe6, 0x18)


// CMainUIDlgAutoProxy ӍϢ̎��ʽ
