
// try1View.h : Ctry1View e�Ľ���
//

#pragma once


class Ctry1View : public CView
{
protected: // �H�����л�����
	Ctry1View();
	DECLARE_DYNCREATE(Ctry1View)

// ����
public:
	Ctry1Doc* GetDocument() const;

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
	virtual ~Ctry1View();
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


protected:
	int m_xx, m_yy;		//�ſs�ķ��K�����½�����
	bool swit;			//true is ++, false is --
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // try1View.cpp �еĂ��e�汾
inline Ctry1Doc* Ctry1View::GetDocument() const
   { return reinterpret_cast<Ctry1Doc*>(m_pDocument); }
#endif

