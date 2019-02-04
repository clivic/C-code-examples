
// DrawTest2View.h : CDrawTest2View e�Ľ���
//

#include "ChoiceButton.h"
#pragma once

class CDrawTest2View : public CView
{
protected: // �H�����л�����
	CDrawTest2View();
	DECLARE_DYNCREATE(CDrawTest2View)

// ����
public:
	CDrawTest2Doc* GetDocument() const;

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
	virtual ~CDrawTest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �a����ӍϢ������ʽ
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	CPoint m_originPoint;
	CPoint m_prevPoint;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_movingPoint;
	bool isClicked;
	WayToDraw wayToDraw;
	CChoiceButton m_clearButton;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void DrawRectangle(CPoint LeftTop, CPoint RightBottom, COLORREF color, CDC *pDC);
	void DrawEllipse(CPoint LeftTop, CPoint RightBottom, COLORREF color, CDC *pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // DrawTest2View.cpp �еĂ��e�汾
inline CDrawTest2Doc* CDrawTest2View::GetDocument() const
   { return reinterpret_cast<CDrawTest2Doc*>(m_pDocument); }
#endif

