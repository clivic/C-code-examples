#pragma once


// CDialogResult �Ի���

class CDialogResult : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogResult)

public:
	CDialogResult(CWnd*pParent = NULL);   // ��׼���캯��
	virtual ~CDialogResult();

// �Ի�������
	enum { IDD = IDD_DIALOG_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange*pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
