#pragma once
#include "afxwin.h"
#include "PictureInfoList.h"
#include "SubGetOnePic.h"

// CSubSearchByName �Ի���

class CSubSearchByName : public CDialogEx
{
	DECLARE_DYNAMIC(CSubSearchByName)

public:
	CSubSearchByName(CWnd* pParent = NULL);			//��׼���캯��
	CSubSearchByName(CWnd* pParent, 
		PictureInfoList *ptr,
		bool isN);									//����Dlist�Ę��캯��
	virtual ~CSubSearchByName();
	//afx_msg void OnPaint();						//���D��ʽ

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_NAME_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	//�ķ��D
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	
	//�����ڂ����PictureInfoList���Д��õ�isByName
	PictureInfoList *picListptr;
	bool isByName;	//1, by name, 0, by location

	//��Ƭ�������P
	CString filenames[3000];	//�DƬ�ļ���ַ(��������Ŀ�)
	int currentPage;			//��ǰ���̖
	int numInPages;				//ÿ퓈D��
	int count;					//�G�D��
	PictureRecord info;			//һ���D��Record
	bool hasSearched;

public:
	afx_msg void OnBnClickedButtonSearchMltpic();
private:
	CString m_search;
public:
	virtual BOOL OnInitDialog();
	
	//�L�D�o������
	void DrawPicture(CStatic *m_Pic/*�ؼ����Q*/, int no/*�ؼ���̖0 .. numInPages-1*/);

	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonPrevious();
	afx_msg void OnPaint();
	afx_msg void OnEnChangeEditSearchByName();
	afx_msg void OnStnClickedPic1();
	afx_msg void OnStnClickedPic2();
	afx_msg void OnStnClickedPic3();
	afx_msg void OnStnClickedPic4();
private:
	CString m_way;
	const Node<PictureRecord>* items[30];
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
