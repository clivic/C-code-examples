
// MainUIDlg.h : ���^�n
//

#pragma once
#include "PictureInfoList.h"

class CMainUIDlgAutoProxy;


// CMainUIDlg ��Ԓ���K
class CMainUIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainUIDlg);
	friend class CMainUIDlgAutoProxy;

// ����
public:
	CMainUIDlg(CWnd* pParent = NULL);	// �˜ʽ�����ʽ
	virtual ~CMainUIDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_PICTUREMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧Ԯ


// ��ʽ�a����
protected:
	CMainUIDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// �a����ӍϢ������ʽ
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearchByTitle();

	//����PictureInfoList������ͨ��ȫ��
	
	afx_msg void OnBnClickedButtonSearchByLoc();

private:
	PictureInfoList picLibrary;
public:
	afx_msg void OnBnClickedButtonAddpic();
	afx_msg void OnBnClickedButtonFootprint();
	afx_msg void OnBnClickedButtonTesttime();
	afx_msg void OnBnClickedButtonRevpic();
	afx_msg void OnBnClickedButtonDelpic();
	afx_msg void OnBnClickedButtonEditpic();
};
