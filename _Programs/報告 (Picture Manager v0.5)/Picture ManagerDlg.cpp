
// Picture ManagerDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "Picture ManagerDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

//用來產生子框對象
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


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CPictureManagerDlg 對話方塊


IMPLEMENT_DYNAMIC(CPictureManagerDlg, CDialogEx);

CPictureManagerDlg::CPictureManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPictureManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CPictureManagerDlg::~CPictureManagerDlg()
{
	// 如果有此對話方塊的 Automation Proxy，
	// 請將其指向此對話方塊的返回指標設為 NULL，
	// 所以會知道是否已經刪除對話方塊。
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


// CPictureManagerDlg 訊息處理常式

BOOL CPictureManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定
	// 對PhotoList的初始化
	if (picLibrary.initialization() == success)
	{
		MessageBox(_T("OK, Now picture List is initialized."));
	}
	else
	{
		MessageBox(_T("Warning: Fail to initialize picture List."));
	}


	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CPictureManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();

		//畫圖
		//白背景
		CPaintDC dc(this); // 繪製的裝置內容

		//CBrush brush;				
		//brush.CreateSolidBrush(WHITE_BRUSH);
		//dc.SelectObject(&brush);					
		
		dc.Rectangle(0, 0, 800, 400);

		//Invalidate(FALSE);//FALSE表示在原有图形上继续绘制


		//插圖
		//开始
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
		//----结束

	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CPictureManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 如果控制器仍保持其物件之一，而使用者
// 關閉 UI 時，Automation 伺服器不應該結束。
// 這些訊息處理常式會確認是否仍在使用 Proxy，
// 如果已結束使用，則會隱藏 UI，但是對話方塊
// 仍保持在附近。

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
	// 如果 Proxy 物件仍在附近，則 Automation 控制器
	// 仍掌控此應用程式。請將對話方塊保持在附近，
	// 但是隱藏其 UI。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CPictureManagerDlg::OnBnClickedButtonSearchByTitle()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubSearchByName dlgSearchByTitle(NULL, &picLibrary, 1);
	dlgSearchByTitle.DoModal();	//打開子框
}


void CPictureManagerDlg::OnBnClickedButtonSearchByLoc()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubSearchByName dlgSearchByLoc(NULL, &picLibrary, 0);
	dlgSearchByLoc.DoModal();	//打開子框
}


void CPictureManagerDlg::OnBnClickedButtonAddpic()
{
	// TODO:  在此添加控件通知处理程序代码
	CAddNewPic dlgAddNewPic(NULL, &picLibrary);
	dlgAddNewPic.DoModal(); //打開子框
}


void CPictureManagerDlg::OnBnClickedButtonFootprint()
{
	// TODO:  在此添加控件通知处理程序代码
	//CSubFootprint dlgFootPrint(NULL, &picLibrary);
	//dlgFootPrint.DoModal(); //打開子框
	CSubMapChoose dlgChooseMap(NULL, &picLibrary);
	dlgChooseMap.DoModal();
}


void CPictureManagerDlg::OnBnClickedButtonTesttime()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubTestTime dlgTestTime(NULL, &picLibrary);

}


void CPictureManagerDlg::OnBnClickedButtonRevpic()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubSurf dlgSurf(NULL, &picLibrary);
	dlgSurf.DoModal(); //打開子框
}


void CPictureManagerDlg::OnBnClickedButtonDelpic()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubDel dlgDel(NULL, &picLibrary);
	dlgDel.DoModal(); //打開子框
}


void CPictureManagerDlg::OnBnClickedButtonEditpic()
{
	// TODO:  在此添加控件通知处理程序代码
	CSubModify dlgModify(NULL, &picLibrary);
	dlgModify.DoModal(); //打開子框
}
