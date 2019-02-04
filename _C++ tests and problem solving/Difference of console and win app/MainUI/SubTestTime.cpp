// SubTestTime.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubTestTime.h"
#include "afxdialogex.h"
#include <atlimage.h>

// CSubTestTime 对话框

IMPLEMENT_DYNAMIC(CSubTestTime, CDialogEx)

CSubTestTime::CSubTestTime(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubTestTime::IDD, pParent)
{

	EnableAutomation();

}
CSubTestTime::CSubTestTime(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubTestTime::IDD, pParent)
{
	EnableAutomation();
	picListptr = ptr;
}

CSubTestTime::~CSubTestTime()
{
	//刪指針
	if (testGraph != NULL)
		delete testGraph;
}

void CSubTestTime::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubTestTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubTestTime, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_CURVE, &CSubTestTime::OnBnClickedButton1Curve)
	ON_BN_CLICKED(IDCLOSE, &CSubTestTime::OnBnClickedClose)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubTestTime, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubTestTime 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {7E9A95C9-DE8A-4B37-95D4-B217672A1365}
static const IID IID_ISubTestTime =
{ 0x7E9A95C9, 0xDE8A, 0x4B37, { 0x95, 0xD4, 0xB2, 0x17, 0x67, 0x2A, 0x13, 0x65 } };

BEGIN_INTERFACE_MAP(CSubTestTime, CDialogEx)
	INTERFACE_PART(CSubTestTime, IID_ISubTestTime, Dispatch)
END_INTERFACE_MAP()


// CSubTestTime 消息处理程序


BOOL CSubTestTime::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	testGraph = new CGraph();

	testGraph->SetGraphTitle(_T("Test Results"));
	testGraph->SetTickRange(150);
	testGraph->SetTickSpace(20);
	testGraph->SetXAxisAlignment(0);
	testGraph->SetXAxisLabel(_T("Students"));
	testGraph->SetYAxisLabel(_T("Test Scores"));

	CGraphSeries* series1 = new CGraphSeries();
	CGraphSeries* series2 = new CGraphSeries();
	CGraphSeries* series3 = new CGraphSeries();
	
	series1->SetLabel(_T("Student 1"));
	series2->SetLabel(_T("Student 2"));
	series3->SetLabel(_T("Student 3"));

	series1->SetData(0, 87);
	series1->SetData(1, 92);
	series1->SetData(2, 73);
	series2->SetData(0, 64);
	series2->SetData(1, 58);
	series2->SetData(2, 86);
	series3->SetData(0, 94);
	series3->SetData(1, 100);
	series3->SetData(2, 91);

	testGraph->AddSeries(series1);
	testGraph->AddSeries(series2);
	testGraph->AddSeries(series3);

	testGraph->SetLegend(0, _T("English "));
	testGraph->SetLegend(1, _T("Math    "));
	testGraph->SetLegend(2, _T("Computer"));



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CSubTestTime::OnBnClickedButton1Curve()
{
	//曲綫圖設定
	testGraph->SetGraphType(1);
	Invalidate(TRUE);
}


void CSubTestTime::OnBnClickedClose()
{
	//推出時的指針處理等
	delete testGraph;
	testGraph = NULL;
	CDialog::OnOK();

}


void CSubTestTime::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CWnd* graphFrame = (CWnd*)GetDlgItem(IDC_STATIC);
	CDC* pDC = graphFrame->GetDC();
	testGraph->DrawGraph(pDC);
	ReleaseDC(pDC);

}
