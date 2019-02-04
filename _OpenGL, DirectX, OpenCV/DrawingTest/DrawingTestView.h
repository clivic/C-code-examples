
// DrawingTestView.h : CDrawingTestView 類別的介面
//

#pragma once


class CDrawingTestView : public CView
{
protected: // 僅從序列化建立
	CDrawingTestView();
	DECLARE_DYNCREATE(CDrawingTestView)

// 屬性
public:
	CDrawingTestDoc* GetDocument() const;

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
	virtual ~CDrawingTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint downPoint, upPoint, movingPoint;
	bool isClicked;
// 產生的訊息對應函式
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

#ifndef _DEBUG  // DrawingTestView.cpp 中的偵錯版本
inline CDrawingTestDoc* CDrawingTestView::GetDocument() const
   { return reinterpret_cast<CDrawingTestDoc*>(m_pDocument); }
#endif

