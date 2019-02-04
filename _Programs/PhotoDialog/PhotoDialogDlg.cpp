
// PhotoDialogDlg.cpp : �����n
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "PhotoDialogDlg.h"
#include  "afxdialogex.h"
#include  "afxwin.h"

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
	virtual void DoDataExchange(CDataExchange*pDX);    // DDX/DDV ֧Ԯ

// ��ʽ�a����
protected:
	DECLARE_MESSAGE_MAP()
private:
//	CStatic m_pic1;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange*pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_ICON, m_pic1);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPhotoDialogDlg ��Ԓ���K



CPhotoDialogDlg::CPhotoDialogDlg(CWnd*pParent /*=NULL*/)
	: CDialogEx(CPhotoDialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPhotoDialogDlg::DoDataExchange(CDataExchange*pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhotoDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CPhotoDialogDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_SEARCH, &CPhotoDialogDlg::OnEnChangeEditSearch)
	ON_BN_CLICKED(IDC_MULTI, &CPhotoDialogDlg::OnBnClickedMulti)
END_MESSAGE_MAP()


// CPhotoDialogDlg ӍϢ̎��ʽ

BOOL CPhotoDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� [�P�...] ���ܱ����ϵ�y���ܱ�

	// IDM_ABOUTBOX �����ϵ�y�����֮�С�
	ASSERT((IDM_ABOUTBOX &0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu*pSysMenu = GetSystemMenu(FALSE);
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
	



	return TRUE;  // ���� TRUE����������������O�����c
}

void CPhotoDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID &0xFFF0) == IDM_ABOUTBOX)
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

void CPhotoDialogDlg::OnPaint()
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
		//CPaintDC dc(this); // �L�u���b�Ã���
		//CDialogEx::OnPaint();
		//CDialog::OnPaint();
		//CRect rect;
		//GetClientRect(&rect);
		//CDC dcMem;
		//dcMem.CreateCompatibleDC(&dc);
		//CBitmap bmpBackground;
		//bmpBackground.LoadBitmap(IDB_APERTURE);

		//BITMAP bitmap;
		//bmpBackground.GetBitmap(&bitmap);
		//CBitmap *pbmpPri = dcMem.SelectObject(&bmpBackground);
		//dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);


		

	}
}

// ��ʹ������ҷ��С��ҕ���r��
// ϵ�y�����@������ȡ���Θ��@ʾ��
HCURSOR CPhotoDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPhotoDialogDlg::OnEnChangeEditSearch()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//��������ֵ�ĸ��±����ڱ�����

}

void CPhotoDialogDlg::OnBnClickedMulti()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogPicture multiPic;
	multiPic.DoModal();
}
