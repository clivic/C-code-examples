// SubMapChoose.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubMapChoose.h"
#include "afxdialogex.h"
#include "SubFootprint.h"
#include "SubFootPrintChina.h"


// CSubMapChoose 对话框

IMPLEMENT_DYNAMIC(CSubMapChoose, CDialogEx)

CSubMapChoose::CSubMapChoose(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubMapChoose::IDD, pParent)
{

}

CSubMapChoose::CSubMapChoose(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubMapChoose::IDD, pParent)
{
	picListptr = ptr;
}

CSubMapChoose::~CSubMapChoose()
{
}

void CSubMapChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubMapChoose, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_ECNU, &CSubMapChoose::OnBnClickedRadioEcnu)
	ON_BN_CLICKED(IDC_RADIO_CHINA, &CSubMapChoose::OnBnClickedRadioChina)
END_MESSAGE_MAP()


// CSubMapChoose 消息处理程序


//打開相應足跡功能
void CSubMapChoose::OnBnClickedRadioEcnu()
{
	CSubFootprint dlgFootPrintECNU(NULL, picListptr);
	dlgFootPrintECNU.DoModal(); //打開子框
}



void CSubMapChoose::OnBnClickedRadioChina()
{
	CSubFootPrintChina dlgFootPrintChina(NULL, picListptr);
	dlgFootPrintChina.DoModal(); //打開子框
}
