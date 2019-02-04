
// DrawingTestView.cpp : CDrawingTestView 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "DrawingTest.h"
#endif

#include "DrawingTestDoc.h"
#include "DrawingTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingTestView

IMPLEMENT_DYNCREATE(CDrawingTestView, CView)

BEGIN_MESSAGE_MAP(CDrawingTestView, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CDrawingTestView 建構/解構

CDrawingTestView::CDrawingTestView()
{
	// TODO:  在此加入建構程式碼
	//x0 = y0 = 50;
	//x1 = y1 = 200;
	isClicked = false;
}

CDrawingTestView::~CDrawingTestView()
{
}

BOOL CDrawingTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CDrawingTestView 描繪

void CDrawingTestView::OnDraw(CDC* pDC)
{
	CDrawingTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此加入原生資料的描繪程式碼
	// 以下段為靜態地畫線與圓
	//// 繪畫橢圓
	//pDC->Ellipse(x0 + 50, y0 + 20, x1 + 70, y1);

	//// 繪畫直線段
	//CPoint startPoint(x0, y0);
	//pDC->MoveTo(startPoint);
	//pDC->LineTo(x1, y1);

	//以下為鼠標指揮地畫線與圓
	pDC->MoveTo(downPoint);
	pDC->LineTo(upPoint);
	if (isClicked)
	{
		pDC->MoveTo(downPoint);
		pDC->LineTo(movingPoint);
	}
}


// CDrawingTestView 列印


void CDrawingTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CDrawingTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印前額外的初始設定
}

void CDrawingTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印後的清除程式碼
}

void CDrawingTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawingTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawingTestView 診斷

#ifdef _DEBUG
void CDrawingTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingTestDoc* CDrawingTestView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingTestDoc)));
	return (CDrawingTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingTestView 訊息處理常式


void CDrawingTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//UpdateWindow();
	movingPoint = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CDrawingTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	downPoint = point;
	isClicked = true;
	upPoint = downPoint;	//為了防止後一根線畫的時候跟前一根相連

	CView::OnLButtonDown(nFlags, point);
}


void CDrawingTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	upPoint = point;
	Invalidate();			//表示一根直線畫完畢
	isClicked = false;

	CView::OnLButtonUp(nFlags, point);
}
