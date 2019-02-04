
// DrawTest2View.cpp : CDrawTest2View e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
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
	// �˜���ӡ����
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

// CDrawTest2View ����/�☋

CDrawTest2View::CDrawTest2View()
{
	// TODO:  �ڴ˼��뽨����ʽ�a
	isClicked = false;
	wayToDraw = LINE;
}

CDrawTest2View::~CDrawTest2View()
{
}

BOOL CDrawTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˽����޸� CREATESTRUCT cs 
	// �_���޸�ҕ��e���ʽ��Ŀ��

	return CView::PreCreateWindow(cs);
}

// CDrawTest2View ���L

void CDrawTest2View::OnDraw(CDC* pDC)
{
	//int nWidth = 1050, nHeight = 1680;

	//CDrawTest2Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	// TODO:  �ڴ˼���ԭ���Y�ϵ����L��ʽ�a
	pDC->TextOut(0, 60, _T("MFC�h���µĺ��׮���"));
	pDC->TextOut(0, 80, _T("�����f��:"));
	pDC->TextOut(0, 100, _T("��1�I��ֱ��"));
	pDC->TextOut(0, 120, _T("��2�I���E�A"));
	pDC->TextOut(0, 140, _T("��3�I������"));
	pDC->TextOut(0, 160, _T("��0�I����հ��o��ծ���"));
	//CDC   MemDC;   //���ȶ���һ����ʾ�豸����   
	//CBitmap   MemBitmap;//����һ��λͼ����   

	////���������Ļ��ʾ���ݵ��ڴ���ʾ�豸   
	//MemDC.CreateCompatibleDC(NULL);
	////��ʱ�����ܻ�ͼ����Ϊû�еط���   ^_^   
	////���潨��һ������Ļ��ʾ���ݵ�λͼ������λͼ�Ĵ�С������ô��ڵĴ�С   
	//MemBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight);

	////��λͼѡ�뵽�ڴ���ʾ�豸��   
	////ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ��   
	//CBitmap   *pOldBit = MemDC.SelectObject(&MemBitmap);

	////���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ����   
	////��Ҳ�������Լ�Ӧ���õ���ɫ   
	//MemDC.FillSolidRect(0, 0, nWidth, nHeight, RGB(255, 255, 255));

	// //���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ   
 // pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY);   
 //   
 // //��ͼ��ɺ������   
 // MemBitmap.DeleteObject();   
 // MemDC.DeleteDC();  
}


// CDrawTest2View ��ӡ


void CDrawTest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �A�O�Ĝʂ���ӡ��ʽ�a
	return DoPreparePrinting(pInfo);
}

void CDrawTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡǰ�~��ĳ�ʼ�O��
}

void CDrawTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ������ӡ��������ʽ�a
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


// CDrawTest2View �\��

#ifdef _DEBUG
void CDrawTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CDrawTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawTest2Doc* CDrawTest2View::GetDocument() const // ��Ƕ�ǂ��e�汾
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawTest2Doc)));
	return (CDrawTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDrawTest2View ӍϢ̎��ʽ


void CDrawTest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���u��ʼ�L�D����CDC,�\����Ƥ��g���F�τ�Ŀ��
	CClientDC dc(this);
	//OnPrepareDC(&dc);
	//dc.DPtoLP(&point);

	//�@����ʼ�c����
	m_prevPoint = point;
	m_originPoint = point;
	isClicked = true;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawTest2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	isClicked = false;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawTest2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���u��ʼ�L�D����CDC,�\����Ƥ��g���F�τ�Ŀ��
	CClientDC dc(this);
	//OnPrepareDC(&dc);
	//dc.DPtoLP(&point);

	dc.SetROP2(R2_NOT);//��Ƥ��g
	//m_movingPoint = point;
	if (isClicked)
	{
		switch (wayToDraw)
		{
		case LINE:
			dc.MoveTo(m_originPoint);	dc.LineTo(m_prevPoint);	//ӛ�֮ǰ���Ǘl��
			dc.MoveTo(m_originPoint);	dc.LineTo(point);		//ӛ䛬F�ڵ�һ�l��
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
	m_prevPoint = point;	//�F�ڵ�һ�l��׃��"֮ǰ"����,�´��ٮ��@�l��,�����R2_NOT,�����ð׮��P���w֮��
	dc.SetROP2(R2_NOT);		//�֏�֮ǰ�L�Dģʽ
	ReleaseDC(&dc);

	CView::OnMouseMove(nFlags, point);
}


int CDrawTest2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_clearButton.Create(_T("���"), WS_CHILD, CRect(0, 0, 50, 50), this, 120);
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
	case '1':
		wayToDraw = LINE;		break;	//������
	case '2':
		wayToDraw = ELLIPSE;	break;	//���E�A
	case '3':
		wayToDraw = RECTANGLE;	break;	//������
	case '0':
		Invalidate();			break;	//�����Ļ
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
