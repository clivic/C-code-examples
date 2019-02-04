// MfcHostAppDlg.h : header file
//

#pragma once


// CMfcHostAppDlg dialog
class CMfcHostAppDlg : public CDialog
{
// Construction
public:
	CMfcHostAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCHOSTAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	// Data member for the .NET User Control:
	CWinFormsControl<Glass::GlassButton> m_button1;
	CWinFormsControl<Glass::GlassButton> m_button2;
	CWinFormsControl<Glass::GlassButton> m_button3;
	CWinFormsControl<Glass::GlassButton> m_button4;

public:
// delegate map
BEGIN_DELEGATE_MAP(CMfcHostAppDlg)
	EVENT_DELEGATE_ENTRY(OnClick, System::Object^, System::EventArgs^)
END_DELEGATE_MAP()

	void OnClick(::System::Object^ sender, ::System::EventArgs^ e);
};
