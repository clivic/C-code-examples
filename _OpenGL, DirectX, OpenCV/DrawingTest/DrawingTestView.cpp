
// DrawingTestView.cpp : CDrawingTestView e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
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
	// �˜���ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CDrawingTestView ����/�☋

CDrawingTestView::CDrawingTestView()
{
	// TODO:  �ڴ˼��뽨����ʽ�a
	//x0 = y0 = 50;
	//x1 = y1 = 200;
	isClicked = false;
}

CDrawingTestView::~CDrawingTestView()
{
}

BOOL CDrawingTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˽����޸� CREATESTRUCT cs 
	// �_���޸�ҕ��e���ʽ��Ŀ��

	return CView::PreCreateWindow(cs);
}

// CDrawingTestView ���L

void CDrawingTestView::OnDraw(CDC* pDC)
{
	CDrawingTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˼���ԭ���Y�ϵ����L��ʽ�a
	// ���¶Ξ��o�B�خ����c�A
	//// �L���E�A
	//pDC->Ellipse(x0 + 50, y0 + 20, x1 + 70, y1);

	//// �L��ֱ����
	//CPoint startPoint(x0, y0);
	//pDC->MoveTo(startPoint);
	//pDC->LineTo(x1, y1);

	//�������ָ�]�خ����c�A
	pDC->MoveTo(downPoint);
	pDC->LineTo(upPoint);
	if (isClicked)
	{
		pDC->MoveTo(downPoint);
		pDC->LineTo(movingPoint);
	}
}


// CDrawingTestView ��ӡ


void CDrawingTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �A�O�Ĝʂ���ӡ��ʽ�a
	return DoPreparePrinting(pInfo);
}

void CDrawingTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡǰ�~��ĳ�ʼ�O��
}

void CDrawingTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡ��������ʽ�a
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


// CDrawingTestView �\��

#ifdef _DEBUG
void CDrawingTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingTestDoc* CDrawingTestView::GetDocument() const // ��Ƕ�ǂ��e�汾
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingTestDoc)));
	return (CDrawingTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingTestView ӍϢ̎��ʽ


void CDrawingTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//UpdateWindow();
	movingPoint = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CDrawingTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	downPoint = point;
	isClicked = true;
	upPoint = downPoint;	//���˷�ֹ��һ�������ĕr���ǰһ�����B

	CView::OnLButtonDown(nFlags, point);
}


void CDrawingTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	upPoint = point;
	Invalidate();			//��ʾһ��ֱ�����ꮅ
	isClicked = false;

	CView::OnLButtonUp(nFlags, point);
}
