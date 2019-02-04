
// Picture ManagerDlg.h : ���^�n
//

#pragma once
#include "PictureInfoList.h"

class CPictureManagerDlgAutoProxy;


// CPictureManagerDlg ��Ԓ���K
class CPictureManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureManagerDlg);
	friend class CPictureManagerDlgAutoProxy;

// ����
public:
	CPictureManagerDlg(CWnd* pParent = NULL);	// �˜ʽ�����ʽ
	virtual ~CPictureManagerDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_PICTUREMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧Ԯ


// ��ʽ�a����
protected:
	CPictureManagerDlgAutoProxy* m_pAutoProxy;
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
