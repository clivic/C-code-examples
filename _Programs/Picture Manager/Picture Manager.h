
// Picture Manager.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CPictureManagerApp: 
// Ո��醌�����e�� Picture Manager.cpp
//

class CPictureManagerApp : public CWinApp
{
public:
	CPictureManagerApp();

// ����
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ��ʽ�a����

	DECLARE_MESSAGE_MAP()
};

extern CPictureManagerApp theApp;

