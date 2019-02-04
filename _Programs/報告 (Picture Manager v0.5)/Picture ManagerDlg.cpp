
// Picture ManagerDlg.cpp : �����n
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "Picture ManagerDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

//�Á�a���ӿ���
#include "SubSearchByName.h"
#include "AddNewPic.h"
#include "SubFootprint.h"
#include "SubTestTime.h"
#include "SubSurf.h"
#include "SubDel.h"
#include "SubModify.h"
#include "SubMapChoose.h"

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


// CPictureManagerDlg ��Ԓ���K


IMPLEMENT_DYNAMIC(CPictureManagerDlg, CDialogEx);

CPictureManagerDlg::CPictureManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPictureManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CPictureManagerDlg::~CPictureManagerDlg()
{
	// ����дˌ�Ԓ���K�� Automation Proxy��
	// Ո����ָ��ˌ�Ԓ���K�ķ���ָ���O�� NULL��
	// ���ԕ�֪���Ƿ��ѽ��h����Ԓ���K��
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CPictureManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPictureManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_BY_TITLE, &CPictureManagerDlg::OnBnClickedButtonSearchByTitle)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_BY_LOC, &CPictureManagerDlg::OnBnClickedButtonSearchByLoc)
	ON_BN_CLICKED(IDC_BUTTON_ADDPIC, &CPictureManagerDlg::OnBnClickedButtonAddpic)
	ON_BN_CLICKED(IDC_BUTTON_FOOTPRINT, &CPictureManagerDlg::OnBnClickedButtonFootprint)
	ON_BN_CLICKED(IDC_BUTTON_TESTTIME, &CPictureManagerDlg::OnBnClickedButtonTesttime)
	ON_BN_CLICKED(IDC_BUTTON_REVPIC, &CPictureManagerDlg::OnBnClickedButtonRevpic)
	ON_BN_CLICKED(IDC_BUTTON_DELPIC, &CPictureManagerDlg::OnBnClickedButtonDelpic)
	ON_BN_CLICKED(IDC_BUTTON_EDITPIC, &CPictureManagerDlg::OnBnClickedButtonEditpic)
END_MESSAGE_MAP()


// CPictureManagerDlg ӍϢ̎��ʽ

BOOL CPictureManagerDlg::OnInitDialog()
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

void CPictureManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPictureManagerDlg::OnPaint()
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
		//CDialogEx::OnPaint();

		//���D
		//�ױ���
		CPaintDC dc(this); // �L�u���b�Ã���

		//CBrush brush;				
		//brush.CreateSolidBrush(WHITE_BRUSH);
		//dc.SelectObject(&brush);					
		
		dc.Rectangle(0, 0, 800, 400);

		//Invalidate(FALSE);//FALSE��ʾ��ԭ��ͼ���ϼ�������


		//��D
		//��ʼ
		CRect rect;
		GetClientRect(&rect);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP_PIC_MANAGER);

		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(170, 25, bitmap.bmWidth, bitmap.bmWidth, &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmWidth, SRCCOPY);
		//----����

	}
}

// ��ʹ������ҷ��С��ҕ���r��
// ϵ�y�����@������ȡ���Θ��@ʾ��
HCURSOR CPictureManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ����������Ա��������֮һ����ʹ����
// �P�] UI �r��Automation �ŷ�������ԓ�Y����
// �@ЩӍϢ̎��ʽ���_�J�Ƿ�����ʹ�� Proxy��
// ����ѽY��ʹ�ã��t���[�� UI�����ǌ�Ԓ���K
// �Ա����ڸ�����

void CPictureManagerDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CPictureManagerDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CPictureManagerDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CPictureManagerDlg::CanExit()
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



void CPictureManagerDlg::OnBnClickedButtonSearchByTitle()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubSearchByName dlgSearchByTitle(NULL, &picLibrary, 1);
	dlgSearchByTitle.DoModal();	//���_�ӿ�
}


void CPictureManagerDlg::OnBnClickedButtonSearchByLoc()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubSearchByName dlgSearchByLoc(NULL, &picLibrary, 0);
	dlgSearchByLoc.DoModal();	//���_�ӿ�
}


void CPictureManagerDlg::OnBnClickedButtonAddpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CAddNewPic dlgAddNewPic(NULL, &picLibrary);
	dlgAddNewPic.DoModal(); //���_�ӿ�
}


void CPictureManagerDlg::OnBnClickedButtonFootprint()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CSubFootprint dlgFootPrint(NULL, &picLibrary);
	//dlgFootPrint.DoModal(); //���_�ӿ�
	CSubMapChoose dlgChooseMap(NULL, &picLibrary);
	dlgChooseMap.DoModal();
}


void CPictureManagerDlg::OnBnClickedButtonTesttime()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubTestTime dlgTestTime(NULL, &picLibrary);

}


void CPictureManagerDlg::OnBnClickedButtonRevpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubSurf dlgSurf(NULL, &picLibrary);
	dlgSurf.DoModal(); //���_�ӿ�
}


void CPictureManagerDlg::OnBnClickedButtonDelpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubDel dlgDel(NULL, &picLibrary);
	dlgDel.DoModal(); //���_�ӿ�
}


void CPictureManagerDlg::OnBnClickedButtonEditpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSubModify dlgModify(NULL, &picLibrary);
	dlgModify.DoModal(); //���_�ӿ�
}
