#pragma once
#include "PictureInfoList.h"

// CSubChoose �Ի���

class CSubChoose : public CDialogEx
{
	DECLARE_DYNAMIC(CSubChoose)

public:
	CSubChoose(CWnd* pParent = NULL);   // ��׼���캯��
	CSubChoose(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);		//����Dlist�Ę��캯��,�Á���o���������E
	virtual ~CSubChoose();

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
