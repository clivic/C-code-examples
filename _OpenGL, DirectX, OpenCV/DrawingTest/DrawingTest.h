
// DrawingTest.h : DrawingTest ���ó�ʽ�������^�n
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"       // ��Ҫ��̖


// CDrawingTestApp:
// Ո��醌�����e�� DrawingTest.cpp
//

class CDrawingTestApp : public CWinAppEx
{
public:
	CDrawingTestApp();


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

extern CDrawingTestApp theApp;
