
// try1.h : try1 ���ó�ʽ�������^�n
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"       // ��Ҫ��̖


// Ctry1App:
// Ո��醌�����e�� try1.cpp
//

class Ctry1App : public CWinAppEx
{
public:
	Ctry1App();


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

extern Ctry1App theApp;
