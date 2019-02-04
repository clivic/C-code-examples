// SubFootprint.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubFootprint.h"
#include "afxdialogex.h"
#include <atlimage.h>


// CSubFootprint 对话框

IMPLEMENT_DYNAMIC(CSubFootprint, CDialogEx)

CSubFootprint::CSubFootprint(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubFootprint::IDD, pParent)
{

	EnableAutomation();

}

CSubFootprint::CSubFootprint(CWnd* pParent /*=NULL*/,
	PictureInfoList *pLPtr)
: CDialogEx(CSubFootprint::IDD, pParent)
{

	EnableAutomation();
	picLibraryPtr = pLPtr;

}

CSubFootprint::~CSubFootprint()
{
}

void CSubFootprint::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubFootprint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubFootprint, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubFootprint, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubFootprint 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {AD9EC178-95AC-4A49-B1F2-15DD03905F22}
static const IID IID_ISubFootprint =
{ 0xAD9EC178, 0x95AC, 0x4A49, { 0xB1, 0xF2, 0x15, 0xDD, 0x3, 0x90, 0x5F, 0x22 } };

BEGIN_INTERFACE_MAP(CSubFootprint, CDialogEx)
	INTERFACE_PART(CSubFootprint, IID_ISubFootprint, Dispatch)
END_INTERFACE_MAP()


// CSubFootprint 消息处理程序


void CSubFootprint::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	//顯示背景圖
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_ECNU);

	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	//绘制足迹信息    
	int count = ecnuMap.get_verterxCount();
	VertexRecord vr; //图中节点记录
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//图中点对应的照片集合
	for (int i = 0; i<count; i++)
	{
		ecnuMap.get_trackByIndex(i, vr, trackListPtr);
		if (trackListPtr != NULL&&trackListPtr->size()>0)
		{
			CBrush * pBrushOld;//画刷
			CBrush brushTmp;
			brushTmp.CreateSolidBrush(RGB(255, 223, 0));//RGB(红，绿，蓝)
			pBrushOld = dc.SelectObject(&brushTmp);

			dc.Ellipse(vr.the_x() - 9, vr.the_y() - 9, vr.the_x() + 9, vr.the_y() + 9);//围绕中心点画个圆形；
			dc.SetTextColor(RGB(255, 0, 0));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}


}


BOOL CSubFootprint::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	//爲了坐標準確按照图像比例显示图形。
	CRect   temprect(0, 0, 877, 740);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	if (ecnuMap.Initialize("华师大", "ecnu") == success)
	{
		MessageBox(_T("OK,Now map is initialized."));
	}
	else
	{
		MessageBox(_T("error,map load failed."));

	}
	//查找足迹
	picLibraryPtr->searchByFootmark(ecnuMap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CSubFootprint::OnLButtonDown(UINT nFlags, CPoint point)
//鍵盤上點擊一個點
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);

	int no, index;

	ecnuMap.positionToNum(point.x, point.y, index, no);

	VertexRecord vr; //图中节点记录
	const List <const Node<PictureRecord >  *>*     trackListPtr = NULL;//图中点对应的照片集合

	ecnuMap.get_trackByIndex(index, vr, trackListPtr);
	CString tmp(vr.the_location().c_str());

	CString str_x;//X坐标
	CString str_y;//Y坐标
	str_x.Format(_T("%d"), point.x);//转换point.x到str_x
	str_y.Format(_T("%d"), point.y); //转换point.y到str_y

	tmp = str_x + _T(",") + str_y + _T(",") + tmp;
	CString imageNames("");
	const Node<PictureRecord >* cptr;

	for (int i = 0; i < trackListPtr->size(); i++)
	{
		trackListPtr->retrieve(i, cptr);
		CString tmpName(cptr->entry.the_key().c_str());
		imageNames = imageNames + _T(",") + tmpName;
	}
	MessageBox(tmp + imageNames);
	CDialog::OnLButtonDown(nFlags, point);

}
