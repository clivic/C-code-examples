
// try1View.h : Ctry1View 類別的介面
//

#pragma once


class Ctry1View : public CView
{
protected: // 僅從序列化建立
	Ctry1View();
	DECLARE_DYNCREATE(Ctry1View)

// 屬性
public:
	Ctry1Doc* GetDocument() const;

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
	virtual ~Ctry1View();
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


protected:
	int m_xx, m_yy;		//放縮的方塊的右下角坐標
	bool swit;			//true is ++, false is --
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // try1View.cpp 中的偵錯版本
inline Ctry1Doc* Ctry1View::GetDocument() const
   { return reinterpret_cast<Ctry1Doc*>(m_pDocument); }
#endif

