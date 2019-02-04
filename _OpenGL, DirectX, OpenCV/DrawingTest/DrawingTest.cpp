
// DrawingTest.cpp : ���x���ó�ʽ��e�О顣
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "DrawingTest.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "DrawingTestDoc.h"
#include "DrawingTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingTestApp

BEGIN_MESSAGE_MAP(CDrawingTestApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CDrawingTestApp::OnAppAbout)
	// �����ļ�����Ę˜ʙn��
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// �˜���ӡ�O������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDrawingTestApp ����

CDrawingTestApp::CDrawingTestApp()
{
	m_bHiColorIcons = TRUE;

	// ֧Ԯ�����ӹ���T
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ������ó�ʽ��ʹ�� Common Language Runtime ֧Ԯ (/clr) ���õ�: 
	//     1) Ҫʹ�����ӹ���T֧Ԯ�����\����Ҫ�@���~���O����
	//     2) �ڌ����б�회����������� System.Windows.Forms �����M�н��á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ��Ψһ�� ID �ִ�ȡ������đ��ó�ʽ ID �ִ�; ���h��
	// �ִ���ʽ�� CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DrawingTest.AppID.NoVersion"));

	// TODO:  �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}

// �H�е�һ�� CDrawingTestApp ���

CDrawingTestApp theApp;


// CDrawingTestApp ��ʼ�O��

BOOL CDrawingTestApp::InitInstance()
{
	// ���瑪�ó�ʽ�YӍ���ָ��ʹ�� ComCtl32.dll 6 (��) ����汾��
	// �톢��ҕ�X����ʽ���� Windows XP �ϣ��t��Ҫ InitCommonControls()��
	// ��t�κ�ҕ���Ľ�������ʧ����
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �O��Ҫ������������Ҫ��춑��ó�ʽ�е�
	// ͨ�ÿ����e��
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ��ʼ�� OLE ��ʽ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ��Ҫ�� AfxInitRichEdit2() ����ʹ�� RichEdit �����	
	// AfxInitRichEdit2();

	// �˜ʳ�ʼ�O��
	// �������ʹ���@Щ���܁K����p��
	// ������ɵĿɈ��Йn��С��������
	// �����г�ʽ�a�Ƴ�����Ҫ�ĳ�ʼ����ʽ��
	// ׃�������O��ֵ�ĵ�䛙C�a
	// TODO:  ����ԓ�m���޸Ĵ��ִ�
	// (���磬��˾���Q��M�����Q)
	SetRegistryKey(_T("���C AppWizard ���a���đ��ó�ʽ"));
	LoadStdProfileSettings(4);  // �d��˜� INI �n�x� (���� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ��䛑��ó�ʽ���ļ��������ļ�����ؓ؟���ļ���
	// ���ҕ���c�zҕ�g�M���B��
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_DrawingTestTYPE,
		RUNTIME_CLASS(CDrawingTestDoc),
		RUNTIME_CLASS(CChildFrame), // ��ӆ MDI �ӿ��
		RUNTIME_CLASS(CDrawingTestView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ������ MDI ���ҕ��
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// �����˜� Shell ���DDE���n���_���f�n��������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ����������ָ���ķ�����������ʹ�� 
	// /RegServer��/Register��/Unregserver �� /Unregister ���ӑ��ó�ʽ�������� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �ѽ���ʼ�O����ҕ���������@ʾ�K����ԓҕ��
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CDrawingTestApp::ExitInstance()
{
	// TODO:  ̎���������ѽ�������YԴ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CDrawingTestApp ӍϢ̎��ʽ


// �� App About ʹ�� CAboutDlg ��Ԓ���K

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧Ԯ

// ��ʽ�a����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ���Ќ�Ԓ���K�đ��ó�ʽ����
void CDrawingTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDrawingTestApp ��ӆ�d��/���淽��

void CDrawingTestApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CDrawingTestApp::LoadCustomState()
{
}

void CDrawingTestApp::SaveCustomState()
{
}

// CDrawingTestApp ӍϢ̎��ʽ



