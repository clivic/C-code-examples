// DialogResult.cpp : ʵ���ļ�
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "DialogResult.h"
#include  "afxdialogex.h"


// CDialogResult �Ի���

IMPLEMENT_DYNAMIC(CDialogResult, CDialogEx)

CDialogResult::CDialogResult(CWnd*pParent /*=NULL*/)
	: CDialogEx(CDialogResult::IDD, pParent)
{

}

CDialogResult::~CDialogResult()
{
}

void CDialogResult::DoDataExchange(CDataExchange*pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogResult, CDialogEx)
END_MESSAGE_MAP()


// CDialogResult ��Ϣ�������
