
// ChildFrm.h : CChildFrame e�Ľ���
//

#pragma once

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// ����
public:

// ���I
public:

// ����
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ��ʽ�a����
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// �a����ӍϢ������ʽ
protected:
	DECLARE_MESSAGE_MAP()
};
