#pragma once
#include "afxwin.h"
#include "PictureRecord.h"


// CSubGetOnePic �Ի���

class CSubGetOnePic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubGetOnePic)

public:
	CSubGetOnePic(CWnd* pParent = NULL);				// ��׼���캯��
	CSubGetOnePic(CWnd* pParent, PictureRecord *rec);	// ���DƬ�ļ����Դ��_
	virtual ~CSubGetOnePic();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DLG_DRAW_ONE_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	CStatic m_bigPic;
	CString title;
	CString m_name;
public:
	afx_msg void OnPaint();
private:
	CString m_titleEn;
	CString m_owner;
	int m_height;
	int m_width;
	int m_size;
	CString m_detail;
	CString m_location;
};
