
// try1View.cpp : Ctry1View e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
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
	// �˜���ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctry1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctry1View ����/�☋

Ctry1View::Ctry1View()
{
	// TODO:  �ڴ˼��뽨����ʽ�a
	//�ſs���ε����½����˳�ʼ��
	m_xx = 350;
	m_yy = 500;
	//ָ���Ŵ�߀�ǿsС
	swit = true;
}

Ctry1View::~Ctry1View()
{
}

BOOL Ctry1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˽����޸� CREATESTRUCT cs 
	// �_���޸�ҕ��e���ʽ��Ŀ��

	return CView::PreCreateWindow(cs);
}

// Ctry1View ���L

void Ctry1View::OnDraw(CDC* pDC)
{
	Ctry1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˼���ԭ���Y�ϵ����L��ʽ�a
	CString ss = _T("Hello, World!");
	pDC->TextOut(0, 0, ss);

	//���Q����
	pDC->MoveTo(10, 10);
	pDC->LineTo(100, 150);

	//�Ӯ��P�����ԓ����ɫ
	CPen myPen;
	myPen.CreatePen(PS_SOLID, 4, RGB(100, 30, 155));
	pDC->SelectObject(&myPen);	//Ҫ�x�˲��܉��î��P�_ʼ��



	//�����κ���

	/*SetTimer(1, 20, NULL);*/
	SetTimer(1, 0, NULL);
	pDC->Rectangle(100, 150, m_xx, m_yy);
}


// Ctry1View ��ӡ


void Ctry1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctry1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �A�O�Ĝʂ���ӡ��ʽ�a
	return DoPreparePrinting(pInfo);
}

void Ctry1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡǰ�~��ĳ�ʼ�O��
}

void Ctry1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡ��������ʽ�a
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


// Ctry1View �\��

#ifdef _DEBUG
void Ctry1View::AssertValid() const
{
	CView::AssertValid();
}

void Ctry1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctry1Doc* Ctry1View::GetDocument() const // ��Ƕ�ǂ��e�汾
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctry1Doc)));
	return (Ctry1Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctry1View ӍϢ̎��ʽ


void Ctry1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	if (m_xx > 400)	swit = false;	//�_ʼ�sС
	if (m_xx < 350)	swit = true;	//�_ʼ�Ŵ�

	Invalidate();
	CView::OnTimer(nIDEvent);
}
