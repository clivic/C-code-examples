
// DrawTest2.h : DrawTest2 ���ó�ʽ�������^�n
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"       // ��Ҫ��̖


// CDrawTest2App:
// Ո��醌�����e�� DrawTest2.cpp
//

class CDrawTest2App : public CWinAppEx
{
public:
	CDrawTest2App();


// ����
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ��ʽ�a����
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawTest2App theApp;
