
// DlgProxy.h: ���^�n
//

#pragma once

class CPictureManagerDlg;


// CPictureManagerDlgAutoProxy ����Ŀ��

class CPictureManagerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CPictureManagerDlgAutoProxy)

	CPictureManagerDlgAutoProxy();           // �ӑB������ʹ�õı��o������ʽ

// ����
public:
	CPictureManagerDlg* m_pDialog;

// ���I
public:

// ����
	public:
	virtual void OnFinalRelease();

// ��ʽ�a����
protected:
	virtual ~CPictureManagerDlgAutoProxy();

	// �a����ӍϢ������ʽ

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPictureManagerDlgAutoProxy)

	// �a���� OLE ���Ɍ�����ʽ

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

