
// try1View.cpp : Ctry1View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "try1.h"
#endif

#include "try1Doc.h"
#include "try1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctry1View

IMPLEMENT_DYNCREATE(Ctry1View, CView)

BEGIN_MESSAGE_MAP(Ctry1View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctry1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctry1View 建構/解構

Ctry1View::Ctry1View()
{
	// TODO:  在此加入建構程式碼
	//放縮矩形的右下角座標初始化
	m_xx = 350;
	m_yy = 500;
	//指定放大還是縮小
	swit = true;
}

Ctry1View::~Ctry1View()
{
}

BOOL Ctry1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// Ctry1View 描繪

void Ctry1View::OnDraw(CDC* pDC)
{
	Ctry1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此加入原生資料的描繪程式碼
	CString ss = _T("Hello, World!");
	pDC->TextOut(0, 0, ss);

	//劃綫函數
	pDC->MoveTo(10, 10);
	pDC->LineTo(100, 150);

	//加畫筆，可以擁有顏色
	CPen myPen;
	myPen.CreatePen(PS_SOLID, 4, RGB(100, 30, 155));
	pDC->SelectObject(&myPen);	//要選了才能夠用畫筆開始畫



	//畫矩形函數

	/*SetTimer(1, 20, NULL);*/
	SetTimer(1, 0, NULL);
	pDC->Rectangle(100, 150, m_xx, m_yy);
}


// Ctry1View 列印


void Ctry1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctry1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void Ctry1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印前額外的初始設定
}

void Ctry1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印後的清除程式碼
}

void Ctry1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctry1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctry1View 診斷

#ifdef _DEBUG
void Ctry1View::AssertValid() const
{
	CView::AssertValid();
}

void Ctry1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctry1Doc* Ctry1View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctry1Doc)));
	return (Ctry1Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctry1View 訊息處理常式


void Ctry1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (swit)
	{
		m_xx++;
		m_yy++;
	}
	else
	{
		m_xx--;
		m_yy--;
	}
	if (m_xx > 400)	swit = false;	//開始縮小
	if (m_xx < 350)	swit = true;	//開始放大

	Invalidate();
	CView::OnTimer(nIDEvent);
}
