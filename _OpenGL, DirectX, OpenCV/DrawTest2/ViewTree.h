
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree ҕ��

class CViewTree : public CTreeCtrl
{
// ����
public:
	CViewTree();

// ����
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

// ��ʽ�a����
public:
	virtual ~CViewTree();

protected:
	DECLARE_MESSAGE_MAP()
};
