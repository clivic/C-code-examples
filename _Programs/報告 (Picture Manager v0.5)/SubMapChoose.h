#pragma once
#include "PictureInfoList.h"

// CSubMapChoose �Ի���

class CSubMapChoose : public CDialogEx
{
	DECLARE_DYNAMIC(CSubMapChoose)

public:
	CSubMapChoose(CWnd* pParent = NULL);   // ��׼���캯��
	CSubMapChoose(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//����Dlist�Ę��캯��,�Á���o���������E
	virtual ~CSubMapChoose();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_MAP_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	//�����ڂ����PictureInfoList
	PictureInfoList *picListptr;
public:
	afx_msg void OnBnClickedRadioEcnu();
	afx_msg void OnBnClickedRadioChina();
};
