#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubFootPrintChina �Ի���

class CSubFootPrintChina : public CDialogEx
{
	DECLARE_DYNAMIC(CSubFootPrintChina)

public:
	CSubFootPrintChina(CWnd* pParent = NULL);   // ��׼���캯��
	CSubFootPrintChina(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//����Dlist�Ę��캯��
	virtual ~CSubFootPrintChina();

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
};
