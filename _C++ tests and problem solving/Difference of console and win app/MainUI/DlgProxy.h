
// DlgProxy.h: ���^�n
//

#pragma once

class CMainUIDlg;


// CMainUIDlgAutoProxy ����Ŀ��

class CMainUIDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMainUIDlgAutoProxy)

	CMainUIDlgAutoProxy();           // �ӑB������ʹ�õı��o������ʽ

// ����
public:
	CMainUIDlg* m_pDialog;

// ���I
public:

// ����
	public:
	virtual void OnFinalRelease();

// ��ʽ�a����
protected:
	virtual ~CMainUIDlgAutoProxy();

	// �a����ӍϢ������ʽ

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMainUIDlgAutoProxy)

	// �a���� OLE ���Ɍ�����ʽ

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

