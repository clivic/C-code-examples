#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"
#include "constants.h"

// CSubFootPrintECNU �Ի���

class CSubFootPrintECNU : public CDialogEx
{
	DECLARE_DYNAMIC(CSubFootPrintECNU)

public:
	CSubFootPrintECNU(CWnd* pParent = NULL);					//��׼���캯��
	CSubFootPrintECNU(CWnd* pParent, PictureInfoList *pLPtr);	//�������ڵ�List���^��
	virtual ~CSubFootPrintECNU();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_ECNU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	LocationGraph<FOOTPRINT_SIZE> ecnuMap;
	PictureInfoList *picLibraryPtr;

public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
