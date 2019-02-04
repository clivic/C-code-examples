// MfcHostAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MfcHostApp.h"
#include "MfcHostAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcHostAppDlg dialog




CMfcHostAppDlg::CMfcHostAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMfcHostAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcHostAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_ManagedControl(pDX, IDC_CUSTOM1, m_button1);
	DDX_ManagedControl(pDX, IDC_CUSTOM2, m_button2);
	DDX_ManagedControl(pDX, IDC_CUSTOM3, m_button3);
	DDX_ManagedControl(pDX, IDC_CUSTOM4, m_button4);
}

BEGIN_MESSAGE_MAP(CMfcHostAppDlg, CDialog)
	//{{AFX_MSG_MAP
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// CMfcHostAppDlg message handlers

BOOL CMfcHostAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_button1->Text = "Standard Glass Button";
	m_button2->Text = "Disabled Glass Button";
	m_button2->Enabled = false;
	m_button3->Text = "Modified Glass Button";
	m_button3->GlowColor = ::System::Drawing::Color::Red;
	m_button3->ShineColor = ::System::Drawing::Color::Gold;
	m_button3->BackColor = ::System::Drawing::Color::Brown;

	m_button4->Text = "Glass Button with Image";
	m_button4->Image = ::System::Drawing::SystemIcons::Error->ToBitmap()->GetThumbnailImage(24, 24, nullptr, ::System::IntPtr::Zero);
	m_button4->BackColor = ::System::Drawing::SystemColors::ControlDark;
	m_button4->ForeColor = ::System::Drawing::SystemColors::ControlText;
	m_button4->ImageAlign = ::System::Drawing::ContentAlignment::MiddleLeft;

	m_button1->Click += MAKE_DELEGATE(::System::EventHandler, OnClick);
	m_button3->Click += MAKE_DELEGATE(::System::EventHandler, OnClick);
	m_button4->Click += MAKE_DELEGATE(::System::EventHandler, OnClick);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcHostAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMfcHostAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMfcHostAppDlg::OnClick(::System::Object^ sender, ::System::EventArgs^ e)
{
	CString str = "You have clicked the '" + ((::Glass::GlassButton^)sender)->Text + "' button.";
	::MessageBox(m_hWnd, str, (LPCTSTR)L"MfcHostApp", MB_ICONINFORMATION);
}