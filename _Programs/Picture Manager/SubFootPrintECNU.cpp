// SubFootPrintECNU.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubFootPrintECNU.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include "SubSurf.h"
#include "constants.h"	//標圓圈的顏色和半徑


// CSubFootPrintECNU 对话框

IMPLEMENT_DYNAMIC(CSubFootPrintECNU, CDialogEx)

CSubFootPrintECNU::CSubFootPrintECNU(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubFootPrintECNU::IDD, pParent)
{

	EnableAutomation();

}

CSubFootPrintECNU::CSubFootPrintECNU(CWnd* pParent /*=NULL*/,
	PictureInfoList *pLPtr)
: CDialogEx(CSubFootPrintECNU::IDD, pParent)
{

	EnableAutomation();
	picLibraryPtr = pLPtr;

}

CSubFootPrintECNU::~CSubFootPrintECNU()
{
}

void CSubFootPrintECNU::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubFootPrintECNU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubFootPrintECNU, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubFootPrintECNU, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubFootPrintECNU 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {AD9EC178-95AC-4A49-B1F2-15DD03905F22}
static const IID IID_ISubFootPrintECNU =
{ 0xAD9EC178, 0x95AC, 0x4A49, { 0xB1, 0xF2, 0x15, 0xDD, 0x3, 0x90, 0x5F, 0x22 } };

BEGIN_INTERFACE_MAP(CSubFootPrintECNU, CDialogEx)
	INTERFACE_PART(CSubFootPrintECNU, IID_ISubFootPrintECNU, Dispatch)
END_INTERFACE_MAP()


// CSubFootPrintECNU 消息处理程序


void CSubFootPrintECNU::OnPaint()
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
			//標黃顏色點
			CBrush * pBrushOld;//画刷
			CBrush brushTmp;
			brushTmp.CreateSolidBrush(RGB(BRUSH_COLOR_X, BRUSH_COLOR_Y, BRUSH_COLOR_Z));//RGB(红，绿，蓝)
			pBrushOld = dc.SelectObject(&brushTmp);

			dc.Ellipse(vr.the_x() - CIRCLE_R_ECNU, vr.the_y() - CIRCLE_R_ECNU, 
				vr.the_x() + CIRCLE_R_ECNU, vr.the_y() + CIRCLE_R_ECNU);//围绕中心点画个圆形；
			dc.SetTextColor(RGB(TEXT_COLOR_X, TEXT_COLOR_Y, TEXT_COLOR_Z));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}


}


BOOL CSubFootPrintECNU::OnInitDialog()
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
		MessageBox(_T("OK, Now map is initialized."));
	}
	else
	{
		MessageBox(_T("Sorry, map load failed."));

	}
	//查找足迹
	picLibraryPtr->searchByFootmark(ecnuMap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CSubFootPrintECNU::OnLButtonDown(UINT nFlags, CPoint point)
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

	//得到名字和一個用來瀏覽並彈出瀏覽框的表
	CString imageNames("");
	const Node<PictureRecord >* cptr = NULL;
	PictureInfoList picList;

	for (int i = 0; i < trackListPtr->size(); i++)
	{
		trackListPtr->retrieve(i, cptr);
		//添到PictureInfoList
		picList.insert(cptr->entry);	//avoid the passing by reference

		//拿到名字
		CString tmpName(cptr->entry.the_key().c_str());
		imageNames = imageNames + _T(",") + tmpName;
	}
	MessageBox(tmp + imageNames);

	//彈出瀏覽框
	if (!picList.empty())
	{
		CSubSurf dlgSurf(NULL, &picList);
		dlgSurf.DoModal(); //打開子框
	}
	CDialog::OnLButtonDown(nFlags, point);

}
