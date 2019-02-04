
// DrawTest2View.cpp : CDrawTest2View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "DrawTest2.h"
#endif

#include "DrawTest2Doc.h"
#include "DrawTest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawTest2View

IMPLEMENT_DYNCREATE(CDrawTest2View, CView)

BEGIN_MESSAGE_MAP(CDrawTest2View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawTest2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CDrawTest2View 建構/解構

CDrawTest2View::CDrawTest2View()
{
	// TODO:  在此加入建構程式碼
	isClicked = false;
	wayToDraw = LINE;
}

CDrawTest2View::~CDrawTest2View()
{
}

BOOL CDrawTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CDrawTest2View 描繪

void CDrawTest2View::OnDraw(CDC* pDC)
{
	//int nWidth = 1050, nHeight = 1680;

	//CDrawTest2Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	// TODO:  在此加入原生資料的描繪程式碼
	pDC->TextOut(0, 60, _T("MFC環境下的簡易畫板"));
	pDC->TextOut(0, 80, _T("操作說明:"));
	pDC->TextOut(0, 100, _T("按1鍵畫直線"));
	pDC->TextOut(0, 120, _T("按2鍵畫橢圓"));
	pDC->TextOut(0, 140, _T("按3鍵畫矩形"));
	pDC->TextOut(0, 160, _T("按0鍵或清空按鈕清空畫板"));
	//CDC   MemDC;   //首先定义一个显示设备对象   
	//CBitmap   MemBitmap;//定义一个位图对象   

	////随后建立与屏幕显示兼容的内存显示设备   
	//MemDC.CreateCompatibleDC(NULL);
	////这时还不能绘图，因为没有地方画   ^_^   
	////下面建立一个与屏幕显示兼容的位图，至于位图的大小嘛，可以用窗口的大小   
	//MemBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight);

	////将位图选入到内存显示设备中   
	////只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上   
	//CBitmap   *pOldBit = MemDC.SelectObject(&MemBitmap);

	////先用背景色将位图清除干净，这里我用的是白色作为背景   
	////你也可以用自己应该用的颜色   
	//MemDC.FillSolidRect(0, 0, nWidth, nHeight, RGB(255, 255, 255));

	// //将内存中的图拷贝到屏幕上进行显示   
 // pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY);   
 //   
 // //绘图完成后的清理   
 // MemBitmap.DeleteObject();   
 // MemDC.DeleteDC();  
}


// CDrawTest2View 列印


void CDrawTest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CDrawTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印前額外的初始設定
}

void CDrawTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印後的清除程式碼
}

void CDrawTest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawTest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawTest2View 診斷

#ifdef _DEBUG
void CDrawTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CDrawTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawTest2Doc* CDrawTest2View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawTest2Doc)));
	return (CDrawTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDrawTest2View 訊息處理常式


void CDrawTest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//建製初始繪圖工具CDC,運用橡皮筋技術實現拖動目標
	CClientDC dc(this);
	//OnPrepareDC(&dc);
	//dc.DPtoLP(&point);

	//獲得起始點座標
	m_prevPoint = point;
	m_originPoint = point;
	isClicked = true;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawTest2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	isClicked = false;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawTest2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//建製初始繪圖工具CDC,運用橡皮筋技術實現拖動目標
	CClientDC dc(this);
	//OnPrepareDC(&dc);
	//dc.DPtoLP(&point);

	dc.SetROP2(R2_NOT);//橡皮筋技術
	//m_movingPoint = point;
	if (isClicked)
	{
		switch (wayToDraw)
		{
		case LINE:
			dc.MoveTo(m_originPoint);	dc.LineTo(m_prevPoint);	//記錄之前的那條線
			dc.MoveTo(m_originPoint);	dc.LineTo(point);		//記錄現在的一條線
			break;
		case ELLIPSE:
			//dc.Ellipse(CRect(this->m_originPoint, m_prevPoint));
			DrawEllipse(m_originPoint, m_prevPoint, RGB(255, 0, 0), &dc);
			DrawEllipse(m_originPoint, point, RGB(255, 0, 0), &dc);
			break;
		case RECTANGLE:
			DrawRectangle(m_originPoint, m_prevPoint, RGB(255, 0, 0), &dc);
			DrawRectangle(m_originPoint, point, RGB(255, 0, 0), &dc);
			break;
		}	
	}
	m_prevPoint = point;	//現在的一條線變成"之前"的了,下次再畫這條線,因為是R2_NOT,所以用白畫筆覆蓋之了
	dc.SetROP2(R2_NOT);		//恢復之前繪圖模式
	ReleaseDC(&dc);

	CView::OnMouseMove(nFlags, point);
}


int CDrawTest2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_clearButton.Create(_T("清空"), WS_CHILD, CRect(0, 0, 50, 50), this, 120);
	m_clearButton.ShowWindow(SW_SHOWNORMAL);

	return 0;
}

void CDrawTest2View::DrawRectangle(CPoint LeftTop, CPoint RightBottom, COLORREF color, CDC *pDC)
{
	CPen pen(PS_DASH, 1, color);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush *pOldBr = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	pDC->Rectangle(LeftTop.x, LeftTop.y, RightBottom.x, RightBottom.y);
	pDC->SelectObject(pOldBr);
	pDC->SelectObject(pOldPen);
}

void CDrawTest2View::DrawEllipse(CPoint LeftTop, CPoint RightBottom, COLORREF color, CDC *pDC)
{
	CPen pen(PS_DASH, 1, color);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush *pOldBr = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	pDC->Ellipse(LeftTop.x, LeftTop.y, RightBottom.x, RightBottom.y);
	pDC->SelectObject(pOldBr);
	pDC->SelectObject(pOldPen);
}

void CDrawTest2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (nChar)
	{
	case '1':
		wayToDraw = LINE;		break;	//畫線段
	case '2':
		wayToDraw = ELLIPSE;	break;	//畫橢圓
	case '3':
		wayToDraw = RECTANGLE;	break;	//畫矩形
	case '0':
		Invalidate();			break;	//清空屏幕
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
