// SubChoose.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubChoose.h"
#include "afxdialogex.h"
#include "SubMapECNU.h"
#include "SubMapChina.h"


// CSubChoose �Ի���

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


// CSubChoose ��Ϣ�������


//���_�������E����
void CSubChoose::OnBnClickedRadioEcnu()
{
	CSubMapECNU dlgFootPrintECNU(NULL, picListptr);
	dlgFootPrintECNU.DoModal(); //���_�ӿ�
}



void CSubChoose::OnBnClickedRadioChina()
{
	CSubMapChina dlgFootPrintChina(NULL, picListptr);
	dlgFootPrintChina.DoModal(); //���_�ӿ�
}
