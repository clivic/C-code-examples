
// MainUI.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CMainUIApp: 
// Ո��醌�����e�� MainUI.cpp
//

class CMainUIApp : public CWinApp
{
public:
	CMainUIApp();

// ����
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ��ʽ�a����

	DECLARE_MESSAGE_MAP()
};

extern CMainUIApp theApp;
