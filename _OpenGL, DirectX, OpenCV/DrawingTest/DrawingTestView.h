
// DrawingTestView.h : CDrawingTestView e�Ľ���
//

#pragma once


class CDrawingTestView : public CView
{
protected: // �H�����л�����
	CDrawingTestView();
	DECLARE_DYNCREATE(CDrawingTestView)

// ����
public:
	CDrawingTestDoc* GetDocument() const;

// ���I
public:

// ����
public:
	virtual void OnDraw(CDC* pDC);  // ���������L�˙zҕ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ��ʽ�a����
public:
	virtual ~CDrawingTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint downPoint, upPoint, movingPoint;
	bool isClicked;
// �a����ӍϢ������ʽ
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawingTestView.cpp �еĂ��e�汾
inline CDrawingTestDoc* CDrawingTestView::GetDocument() const
   { return reinterpret_cast<CDrawingTestDoc*>(m_pDocument); }
#endif

