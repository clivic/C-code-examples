// SubGetOnePic.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubGetOnePic.h"
#include "afxdialogex.h"
#include <atlimage.h>


// CSubGetOnePic 对话框

IMPLEMENT_DYNAMIC(CSubGetOnePic, CDialogEx)

CSubGetOnePic::CSubGetOnePic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubGetOnePic::IDD, pParent)
	, m_name(_T(""))
	, m_titleEn(_T(""))
	, m_owner(_T(""))
	, m_height(0)
	, m_width(0)
	, m_size(0)
	, m_detail(_T(""))
	, m_location(_T(""))
{

	EnableAutomation();

}

CSubGetOnePic::CSubGetOnePic(CWnd* pParent /*=NULL*/,
	PictureRecord *rec)
: CDialogEx(CSubGetOnePic::IDD, pParent)
{

	EnableAutomation();
	title = rec->the_key().c_str();//filename
	m_titleEn = rec->the_titleEn().c_str();
	m_detail = rec->the_detail().c_str();
	m_owner = rec->the_owner().c_str();
	m_height = rec->the_height();
	m_width = rec->the_width();
	m_size = rec->the_size();
	m_location = rec->the_location().c_str();
}

CSubGetOnePic::~CSubGetOnePic()
{
}

void CSubGetOnePic::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubGetOnePic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ONE_BIG_PIC, m_bigPic);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_TITLEEN, m_titleEn);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_owner);
	DDX_Text(pDX, IDC_EDIT_H, m_height);
	DDX_Text(pDX, IDC_EDIT_W, m_width);
	DDX_Text(pDX, IDC_EDIT_S, m_size);
	DDX_Text(pDX, IDC_EDIT_TITLECH, m_detail);
	DDX_Text(pDX, IDC_EDIT_PLACE, m_location);
}


BEGIN_MESSAGE_MAP(CSubGetOnePic, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubGetOnePic, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubGetOnePic 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {C6A05288-1BE8-4C9A-828E-54DB7B879E45}
static const IID IID_ISubGetOnePic =
{ 0xC6A05288, 0x1BE8, 0x4C9A, { 0x82, 0x8E, 0x54, 0xDB, 0x7B, 0x87, 0x9E, 0x45 } };

BEGIN_INTERFACE_MAP(CSubGetOnePic, CDialogEx)
	INTERFACE_PART(CSubGetOnePic, IID_ISubGetOnePic, Dispatch)
END_INTERFACE_MAP()


// CSubGetOnePic 消息处理程序


void CSubGetOnePic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rectPic;
	m_bigPic.GetClientRect(&rectPic);   //m_picture为Picture Control控件变量，获得控件的区域对象
	CDC* pDC = m_bigPic.GetWindowDC();  //获得显示控件的DC

	CImage *pImage = new CImage();		//装载图像的类

	CString basePath;
	basePath = "d:\\picLibrary\\";
	pImage->Load(basePath + title);		//从磁盘装载图片

	int width = rectPic.Width();		//显示区域的宽和高
	int height = rectPic.Height();

	int picW = pImage->GetWidth();		//图片的宽和高
	int picH = pImage->GetHeight();

	//防止缩放后图片失真
	SetStretchBltMode(pDC->m_hDC, HALFTONE);
	SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
	pImage->StretchBlt(pDC->m_hDC, 5, 5, width - 5, height - 5);

	//显示图片
	pImage->Draw(pDC->m_hDC, 0, 0, width, height);

	m_name = title;
	UpdateData(FALSE); //将变量值的改变更新到界面。
	
}


