// SubChoose.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubChoose.h"
#include "afxdialogex.h"
#include "SubMapECNU.h"
#include "SubMapChina.h"


// CSubChoose 对话框

IMPLEMENT_DYNAMIC(CSubChoose, CDialogEx)

CSubChoose::CSubChoose(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubChoose::IDD, pParent)
{

}

CSubChoose::CSubChoose(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubChoose::IDD, pParent)
{
	picListptr = ptr;
}

CSubChoose::~CSubChoose()
{
}

void CSubChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubChoose, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_ECNU, &CSubChoose::OnBnClickedRadioEcnu)
	ON_BN_CLICKED(IDC_RADIO_CHINA, &CSubChoose::OnBnClickedRadioChina)
END_MESSAGE_MAP()


// CSubChoose 消息处理程序


//打開相應足跡功能
void CSubChoose::OnBnClickedRadioEcnu()
{
	CSubMapECNU dlgFootPrintECNU(NULL, picListptr);
	dlgFootPrintECNU.DoModal(); //打開子框
}



void CSubChoose::OnBnClickedRadioChina()
{
	CSubMapChina dlgFootPrintChina(NULL, picListptr);
	dlgFootPrintChina.DoModal(); //打開子框
}
