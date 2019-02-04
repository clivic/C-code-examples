
// DlgProxy.cpp : �����n
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "DlgProxy.h"
#include "Picture ManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPictureManagerDlgAutoProxy

IMPLEMENT_DYNCREATE(CPictureManagerDlgAutoProxy, CCmdTarget)

CPictureManagerDlgAutoProxy::CPictureManagerDlgAutoProxy()
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
		ASSERT_KINDOF(CPictureManagerDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CPictureManagerDlg)))
		{
			m_pDialog = reinterpret_cast<CPictureManagerDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CPictureManagerDlgAutoProxy::~CPictureManagerDlgAutoProxy()
{
	// ��Ҫ��ʹ�� Automation �������������֮��Y�����ó�ʽ��
	//	 �☋��ʽ��횺��� AfxOleUnlockApp��
	// ���⣬�@���ݚ�����Ԓ���K
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CPictureManagerDlgAutoProxy::OnFinalRelease()
{
	// ��ጷ� Automation �������ą����r��
	// ������ OnFinalRelease������e���Ԅ�
	// �h����������л���eǰ��Ո�ȼ��������������~����� (Cleanup)
	// ��ʽ�a��

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPictureManagerDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPictureManagerDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: �҂������ˌ� IID_IPictureManager ��֧Ԯ
// �Ա�� VBA ֧Ԯ��Ͱ�ȫ�M�Y���� IID ����c .IDL �n�У�
// ������������� (Dispinterface) �� GUID �����

// {1DBA136B-0F19-4980-B86E-C08CF6880407}
static const IID IID_IPictureManager =
{ 0x1DBA136B, 0xF19, 0x4980, { 0xB8, 0x6E, 0xC0, 0x8C, 0xF6, 0x88, 0x4, 0x7 } };

BEGIN_INTERFACE_MAP(CPictureManagerDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPictureManagerDlgAutoProxy, IID_IPictureManager, Dispatch)
END_INTERFACE_MAP()

// �ڴˌ����� StdAfx.h �ж��x IMPLEMENT_OLECREATE2 �޼�
// {9E4494A9-A9A1-461D-8B81-E1EB4739E618}
IMPLEMENT_OLECREATE2(CPictureManagerDlgAutoProxy, "PictureManager.Application", 0x9e4494a9, 0xa9a1, 0x461d, 0x8b, 0x81, 0xe1, 0xeb, 0x47, 0x39, 0xe6, 0x18)


// CPictureManagerDlgAutoProxy ӍϢ̎��ʽ
