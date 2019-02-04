#pragma once
#include "PictureInfoList.h"

// CSubModify �Ի���

class CSubModify : public CDialogEx
{
	DECLARE_DYNAMIC(CSubModify)

public:
	CSubModify(CWnd* pParent = NULL);   // ��׼���캯��
	CSubModify(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);	//����Dlist�Ę��캯��
	virtual ~CSubModify();

// �Ի�������
	enum { IDD = IDD_DIALOG_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	//�����ڂ����PictureInfoList
	PictureInfoList *picListptr;

	//�����õĔ���
	//key
	CString key;	//�ļ���	

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

	////һ�����DƬӛ�
	//PictureRecord info;
	
	
	
public:
	afx_msg void OnBnClickedButtonOpenfile();
	afx_msg void OnEnChangeEditPath();
	afx_msg void OnEnChangeEditTitleen();
	afx_msg void OnEnChangeEditDetail();
	afx_msg void OnEnChangeEditOwner();
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditHeight();
	afx_msg void OnEnChangeEditWidth();
	afx_msg void OnEnChangeEditSize();
	afx_msg void OnEnChangeEditLocation();

	void SetDefault();	//���������ֵ��ʼ��
	void ShowDefault();	//���������ֵshowһ��
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedRadioEcnu();
	afx_msg void OnBnClickedRadioChina();
private:
	bool m_ECNU;
	bool m_CHINA;
};
