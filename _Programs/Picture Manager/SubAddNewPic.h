#pragma once
#include "PictureInfoList.h"


// CSubAddNewPic �Ի���

class CSubAddNewPic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubAddNewPic)

public:
	CSubAddNewPic(CWnd* pParent = NULL);   // ��׼���캯��
	CSubAddNewPic(CWnd* pParent = NULL, 
		PictureInfoList *ptr = NULL);	//����Dlist�Ę��캯��
	virtual ~CSubAddNewPic();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

public:
	afx_msg void OnBnClickedButtonOpenfile();
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditHigh();
	afx_msg void OnEnChangeEditWidth();
	afx_msg void OnEnChangeEditSize();

private:
	//�����ڂ����PictureInfoList
	PictureInfoList *picListptr;

	//�����õĔ���
	//key
	CString key;	//�ļ���	

	//�DƬԭʼ·��
	CString sourcePath;

	//othertype
	int height;
	int width;
	int size;
	long time;
	CString m_detail;		//����
	CString m_titleEn;		//Ӣ��title
	string map;				//������ͼ
	CString m_location;		//��ͼ�е�λ��
	string hmap;			//�����ϼ���ͼ
	string hlocation;		//hmap�е�λ��
	CString m_owner;		//����
	
public:
	afx_msg void OnBnClickedButtonInsert();
private:
	bool m_ECNU;
	bool m_CHINA;
	bool hasOpened;			//�Á�����ǲ��Ǆ������_�򣬄����_��ˢ�D
	
public:
	afx_msg void OnEnChangeEditPos();
	afx_msg void OnBnClickedRadioEcnu();
	afx_msg void OnBnClickedRadioChina();
//	afx_msg void OnEnUpdateEditEngtitle();
	afx_msg void OnEnChangeEditEngtitle();
	afx_msg void OnEnChangeEditChineseTitle();
//	afx_msg void OnEnUpdateEditChineseTitle();
	afx_msg void OnEnChangeEditOwner();
//	afx_msg void OnEnUpdateEditOwner();
};
