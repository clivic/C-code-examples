
// PhotoDialog.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include  "resource.h"		// ��Ҫ��̖


// CPhotoDialogApp: 
// Ո��醌�����e�� PhotoDialog.cpp
//

class CPhotoDialogApp : public CWinApp
{
public:
	CPhotoDialogApp();

// ����
public:
	virtual BOOL InitInstance();

// ��ʽ�a����

	DECLARE_MESSAGE_MAP()
};

extern CPhotoDialogApp theApp;
