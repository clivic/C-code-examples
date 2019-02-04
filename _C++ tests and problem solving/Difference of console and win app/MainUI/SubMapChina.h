#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubMapChina �Ի���

class CSubMapChina : public CDialogEx
{
	DECLARE_DYNAMIC(CSubMapChina)

public:
	CSubMapChina(CWnd* pParent = NULL);   // ��׼���캯��
	CSubMapChina(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//����Dlist�Ę��캯��
	virtual ~CSubMapChina();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_CHINA };

private:
	LocationGraph<200> chinaMap;
	PictureInfoList *picLibraryPtr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
