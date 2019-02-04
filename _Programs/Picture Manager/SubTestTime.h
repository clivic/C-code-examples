#pragma once
#include "Graph.h"
#include "GraphSeries.h"
#include "PictureInfoList.h"

// CSubTestTime �Ի���

class CSubTestTime : public CDialogEx
{
	DECLARE_DYNAMIC(CSubTestTime)

public:
	CSubTestTime(CWnd* pParent = NULL);   // ��׼���캯��
	CSubTestTime(CWnd* pParent = NULL, PictureInfoList *ptr = NULL);
	virtual ~CSubTestTime();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_TEST_TIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	CGraph* testGraph;
	PictureInfoList *picListptr;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1Curve();
	afx_msg void OnBnClickedClose();
	afx_msg void OnPaint();
};
