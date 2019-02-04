
// MainUIDlg.cpp : �����n
//

#include "stdafx.h"
#include "MainUI.h"
#include "MainUIDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

//�Á�a���ӿ���
#include "SubSearch.h"
#include "SubInsert.h"
#include "SubMapECNU.h"
#include "SubTestTime.h"
#include "SubReview.h"
#include "SubDelete.h"
#include "SubModify.h"
#include "SubChoose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMainUIDlg ��Ԓ���K


IMPLEMENT_DYNAMIC(CMainUIDlg, CDialogEx);

CMainUIDlg::CMainUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainUIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMainUIDlg::~CMainUIDlg()
{
	// ����дˌ�Ԓ���K�� Automation Proxy��
	// Ո����ָ��ˌ�Ԓ���K�ķ���ָ���O�� NULL��
	// ���ԕ�֪���Ƿ��ѽ��h����Ԓ���K��
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CMainUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMainUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_BY_TITLE, &CMainUIDlg::OnBnClickedButtonSearchByTitle)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_BY_LOC, &CMainUIDlg::OnBnClickedButtonSearchByLoc)
	ON_BN_CLICKED(IDC_BUTTON_ADDPIC, &CMainUIDlg::OnBnClickedButtonAddpic)
	ON_BN_CLICKED(IDC_BUTTON_FOOTPRINT, &CMainUIDlg::OnBnClickedButtonFootprint)
	ON_BN_CLICKED(IDC_BUTTON_TESTTIME, &CMainUIDlg::OnBnClickedButtonTesttime)
	ON_BN_CLICKED(IDC_BUTTON_REVPIC, &CMainUIDlg::OnBnClickedButtonRevpic)
	ON_BN_CLICKED(IDC_BUTTON_DELPIC, &CMainUIDlg::OnBnClickedButtonDelpic)
	ON_BN_CLICKED(IDC_BUTTON_EDITPIC, &CMainUIDlg::OnBnClickedButtonEditpic)
END_MESSAGE_MAP()


// CMainUIDlg ӍϢ̎��ʽ

BOOL CMainUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� [�P�...] ���ܱ����ϵ�y���ܱ�

	// IDM_ABOUTBOX �����ϵ�y�����֮�С�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �O���ˌ�Ԓ���K�ĈDʾ�������ó�ʽ����ҕ�����ǌ�Ԓ���K�r��
	// ��ܕ��Ԅӏ��´����I
	SetIcon(m_hIcon, TRUE);			// �O����Dʾ
	SetIcon(m_hIcon, FALSE);		// �O��С�Dʾ

	// TODO:  �ڴ˼����~��ĳ�ʼ�O��
	// ��PhotoList�ĳ�ʼ��
	if (picLibrary.initialization() == success)
	{
		MessageBox(_T("OK, Now picture List is initialized."));
	}
	else
	{
		MessageBox(_T("Warning: Fail to initialize picture List."));
	}


	return TRUE;  // ���� TRUE����������������O�����c
}

void CMainUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �������С�����o�������Č�Ԓ���K������Ҫ���еĳ�ʽ�a��
// �Ա��L�u�Dʾ�����ʹ���ļ�/�zҕģʽ�� MFC ���ó�ʽ��
// ��ܕ��Ԅ���ɴ����I��

void CMainUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �L�u���b�Ã���

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ���Dʾ������Ñ��˾���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ���L�Dʾ
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		//���D
		//�ױ���
		//CPaintDC dc(this); // �L�u���b�Ã���

		//dc.Rectangle(0, 0, 800, 400);

		//��D
		//��ʼ
		/*CRect rect;
		GetClientRect(&rect);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP_PIC_MANAGER);

		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(170, 25, bitmap.bmWidth, bitmap.bmWidth, &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmWidth, SRCCOPY);*/
		//----����

	}
}

// ��ʹ������ҷ��С��ҕ���r��
// ϵ�y�����@������ȡ���Θ��@ʾ��
HCURSOR CMainUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ����������Ա��������֮һ����ʹ����
// �P�] UI �r��Automation �ŷ�������ԓ�Y����
// �@ЩӍϢ̎��ʽ���_�J�Ƿ�����ʹ�� Proxy��
// ����ѽY��ʹ�ã��t���[�� UI�����ǌ�Ԓ���K
// �Ա����ڸ�����

void CMainUIDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CMainUIDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CMainUIDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CMainUIDlg::CanExit()
{
	// ��� Proxy ������ڸ������t Automation ������
	// ���ƿشˑ��ó�ʽ��Ո����Ԓ���K�����ڸ�����
	// �����[���� UI��
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CMainUIDlg::OnBnClickedButtonSearchByTitle()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubSearch dlgSearchByTitle(NULL, &picLibrary, 1);
	dlgSearchByTitle.DoModal();	//���_�ӿ�
}


void CMainUIDlg::OnBnClickedButtonSearchByLoc()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubSearch dlgSearchByLoc(NULL, &picLibrary, 0);
	dlgSearchByLoc.DoModal();	//���_�ӿ�
}


void CMainUIDlg::OnBnClickedButtonAddpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubInsert dlgSubInsert(NULL, &picLibrary);
	dlgSubInsert.DoModal(); //���_�ӿ�
}


void CMainUIDlg::OnBnClickedButtonFootprint()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CSubMapECNU dlgFootPrint(NULL, &picLibrary);
	//dlgFootPrint.DoModal(); //���_�ӿ�
	CSubChoose dlgChooseMap(NULL, &picLibrary);
	dlgChooseMap.DoModal();
}


void CMainUIDlg::OnBnClickedButtonTesttime()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CSubTestTime dlgTestTime(NULL, &picLibrary);
	//**********************************
	//�@�e���ĳ��ˏ����P춿򣬜yԇ������
	//**********************************
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();

}


void CMainUIDlg::OnBnClickedButtonRevpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubReview dlgSurf(NULL, &picLibrary);
	dlgSurf.DoModal(); //���_�ӿ�
}


void CMainUIDlg::OnBnClickedButtonDelpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubDelete dlgDel(NULL, &picLibrary);
	dlgDel.DoModal(); //���_�ӿ�
}


void CMainUIDlg::OnBnClickedButtonEditpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubModify dlgModify(NULL, &picLibrary);
	dlgModify.DoModal(); //���_�ӿ�
}
