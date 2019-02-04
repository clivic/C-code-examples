// SubMapChina.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubMapChina.h"
#include "afxdialogex.h"
#include "SubReview.h"

// CSubMapChina 对话框

IMPLEMENT_DYNAMIC(CSubMapChina, CDialogEx)

CSubMapChina::CSubMapChina(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubMapChina::IDD, pParent)
{

}

CSubMapChina::CSubMapChina(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
	: CDialogEx(CSubMapChina::IDD, pParent)
{

	picLibraryPtr = ptr;

}

CSubMapChina::~CSubMapChina()
{
}

void CSubMapChina::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubMapChina, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSubMapChina 消息处理程序


void CSubMapChina::OnPaint()
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
			dc.Ellipse(vr.the_x() - 5, vr.the_y() - 5, vr.the_x() + 5, vr.the_y() + 5);//围绕中心点画个圆形；
			dc.SetTextColor(RGB(255, 0, 0));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}
}


BOOL CSubMapChina::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//爲了坐標準確按照图像比例显示图形。
	//拿到圖的寬高。
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_CHINA);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);

	CRect   temprect(0, 0, bitmap.bmWidth, bitmap.bmHeight);
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


void CSubMapChina::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int no, index;

	chinaMap.positionToNum(point.x, point.y, index, no);

	VertexRecord vr; //图中节点记录
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//图中点对应的照片集合

	chinaMap.get_trackByIndex(index, vr, trackListPtr);	//得到照片集合
	CString tmp(vr.the_location().c_str());				

	CString str_x;//X坐标
	CString str_y;//Y坐标
	str_x.Format(_T("%d"), point.x);//转换point.x到str_x
	str_y.Format(_T("%d"), point.y); //转换point.y到str_y

	tmp = str_x + _T(",") + str_y + _T(",") + tmp;

	//得到名字和一個用來瀏覽並彈出瀏覽框的表
	CString imageNames("");
	const Node<PictureRecord >* cptr;
	PictureInfoList picList;

	for (int i = 0; i<trackListPtr->size(); i++){
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
		CSubReview dlgSurf(NULL, &picList);
		dlgSurf.DoModal(); //打開子框
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
