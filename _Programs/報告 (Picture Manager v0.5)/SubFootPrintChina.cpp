// SubFootPrintChina.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubFootPrintChina.h"
#include "afxdialogex.h"


// CSubFootPrintChina 对话框

IMPLEMENT_DYNAMIC(CSubFootPrintChina, CDialogEx)

CSubFootPrintChina::CSubFootPrintChina(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubFootPrintChina::IDD, pParent)
{

}

CSubFootPrintChina::CSubFootPrintChina(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
	: CDialogEx(CSubFootPrintChina::IDD, pParent)
{

	picLibraryPtr = ptr;

}

CSubFootPrintChina::~CSubFootPrintChina()
{
}

void CSubFootPrintChina::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubFootPrintChina, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSubFootPrintChina 消息处理程序


void CSubFootPrintChina::OnPaint()
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
	bmpBackground.LoadBitmap(IDB_BITMAP_CHINA);

	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	//绘制足迹信息    
	int count = chinaMap.get_verterxCount();
	VertexRecord vr; //图中节点记录
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//图中点对应的照片集合
	for (int i = 0; i<count; i++)
	{
		chinaMap.get_trackByIndex(i, vr, trackListPtr);
		if (trackListPtr != NULL&&trackListPtr->size()>0)
		{
			dc.Ellipse(vr.the_x() - 10, vr.the_y() - 10, vr.the_x() + 10, vr.the_y() + 10);//围绕中心点画个圆形；
			dc.SetTextColor(RGB(255, 0, 0));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}
}


BOOL CSubFootPrintChina::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//爲了坐標準確按照图像比例显示图形。
	CRect   temprect(0, 0, 877, 740);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	if (chinaMap.Initialize("中国", "china") == success)
	{
		MessageBox(_T("OK,Now map is initialized."));
	}
	else
	{
		MessageBox(_T("error,map load failed."));

	}
	//查找足迹
	picLibraryPtr->searchByFootmark(chinaMap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
