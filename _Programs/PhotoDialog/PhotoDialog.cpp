
// PhotoDialog.cpp : ���x���ó�ʽ��e�О顣
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "PhotoDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPhotoDialogApp

BEGIN_MESSAGE_MAP(CPhotoDialogApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPhotoDialogApp ����

CPhotoDialogApp::CPhotoDialogApp()
{
	// ֧Ԯ�����ӹ���T
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CPhotoDialogApp ���

CPhotoDialogApp theApp;


// CPhotoDialogApp ��ʼ�O��

BOOL CPhotoDialogApp::InitInstance()
{
	// ���瑪�ó�ʽ�YӍ���ָ��ʹ�� ComCtl32.dll 6 (��) ����汾��
	// �톢��ҕ�X����ʽ���� Windows XP �ϣ��t��Ҫ InitCommonControls()��
	// ��t�κ�ҕ���Ľ�������ʧ����
	INITCOMMONCONTROLSEX InitCtrls;
	//InitCtrls.dwSize = Sizeof(InitCtrls);
	// �O��Ҫ������������Ҫ��춑��ó�ʽ�е�
	// ͨ�ÿ����e��
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// �������ӹ���T���Է���Ԓ���K����
	// �κΚ��Ә��zҕ�򚤌���Ιzҕ����헡�
	CShellManager *pShellManager = new CShellManager;

	// ���� [Windows ԭ��] ҕ�X������T�Ɇ��� MFC ������е����}
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// �˜ʳ�ʼ�O��
	// �������ʹ���@Щ���܁K����p��
	// ������ɵĿɈ��Йn��С��������
	// �����г�ʽ�a�Ƴ�����Ҫ�ĳ�ʼ����ʽ��
	// ׃�������O��ֵ�ĵ�䛙C�a
	// TODO:  ����ԓ�m���޸Ĵ��ִ�
	// (���磬��˾���Q��M�����Q)
	SetRegistryKey(_T("���C AppWizard ���a���đ��ó�ʽ"));

	CPhotoDialogDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷����ʹ�� [�_��] ��ֹͣʹ�Ì�Ԓ���K�r
		// ̎���ĳ�ʽ�a
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷����ʹ�� [ȡ��] ��ֹͣʹ�Ì�Ԓ���K�r
		// ̎���ĳ�ʽ�a
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: ��Ԓ���K����ʧ������ˣ����ó�ʽ����Kֹ��\n");
		TRACE(traceAppMsg, 0, "����: �����Ҫ�ڌ�Ԓ���K��ʹ�� MFC ����헣��t�o�� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// �h�������������Ě��ӹ���T��
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ����ѽ��P�]��Ԓ���K������ FALSE�������҂����Y�����ó�ʽ��
	// ������ʾ�_ʼ���ó�ʽ��ӍϢ��
	return FALSE;
}
