#pragma once

#include <string>
#include "PictureRecord.h"
#include "PictureInfoList.h"
#include "afxwin.h"
#include "SubGetOnePic.h"
// CSubDelete �Ի���

class CSubDelete : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDelete)

public:
	CSubDelete(CWnd* pParent = NULL);   // ��׼���캯��
	CSubDelete(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);	//����Dlist�Ę��캯��
	virtual ~CSubDelete();

// �Ի�������
	enum { IDD = IDD_SUBDIALOG_DEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpen();
private:
	//�����ڂ����PictureInfoList
	PictureInfoList *picListptr;
	PictureRecord info;			//һ���D��Record
public:
	afx_msg void OnPaint();
	void DrawPicture(CStatic *m_Pic/*�ؼ����Q*/);
private:
	CStatic m_pic;
	bool hasOpened;				//�Á�����ǲ��Ǆ������_�򣬄����_��ˢ�D
public:
	afx_msg void OnStnClickedStaticPic();
	afx_msg void OnBnClickedButtonDel();
};

//�Á�h���ļ�
void DeleteFileInDirectory(CString strDir);
