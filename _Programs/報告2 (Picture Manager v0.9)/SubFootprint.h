#pragma once
#include "LocationGraph.h"
#include "PictureInfoList.h"

// CSubFootprint �Ի���

class CSubFootprint : public CDialogEx
{
	DECLARE_DYNAMIC(CSubFootprint)

public:
	CSubFootprint(CWnd* pParent = NULL);					//��׼���캯��
	CSubFootprint(CWnd* pParent, PictureInfoList *pLPtr);	//�������ڵ�List���^��
	virtual ~CSubFootprint();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_FOOTPRINT_ECNU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	LocationGraph<200> ecnuMap;
	PictureInfoList *picLibraryPtr;

public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
