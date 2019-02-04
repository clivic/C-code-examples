// DialogResult.cpp : 实现文件
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "DialogResult.h"
#include  "afxdialogex.h"


// CDialogResult 对话框

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


// CDialogResult 消息处理程序
