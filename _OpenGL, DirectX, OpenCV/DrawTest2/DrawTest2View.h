
// DrawTest2View.h : CDrawTest2View 類別的介面
//

#include "ChoiceButton.h"
#pragma once

class CDrawTest2View : public CView
{
protected: // 僅從序列化建立
	CDrawTest2View();
	DECLARE_DYNCREATE(CDrawTest2View)

// 屬性
public:
	CDrawTest2Doc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CDrawTest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
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

#ifndef _DEBUG  // DrawTest2View.cpp 中的偵錯版本
inline CDrawTest2Doc* CDrawTest2View::GetDocument() const
   { return reinterpret_cast<CDrawTest2Doc*>(m_pDocument); }
#endif

