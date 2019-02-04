
// PhotoDialogDlg.h : ���^�n
//

#pragma once
#include  <fstream>
#include  <atlimage.h>
#include  "DialogPicture.h"
using namespace std;

// CPhotoDialogDlg ��Ԓ���K
class CPhotoDialogDlg : public CDialogEx
{
// ����
public:
	CPhotoDialogDlg(CWnd*pParent = NULL);	// �˜ʽ�����ʽ

// ��Ԓ���K�Y��
	enum { IDD = IDD_PHOTODIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange*pDX);	// DDX/DDV ֧Ԯ


// ��ʽ�a����
protected:
	HICON m_hIcon;

	// �a����ӍϢ������ʽ
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditSearch();
	
	// TODO:  �ڴ˼����~��ĳ�ʼ�O��
	void drawPicture(CStatic *m_Pic/*�ؼ�����*/, int no/*�ؼ���̖0- numInPages -1*/);

	

	
	afx_msg void OnBnClickedMulti();
};
