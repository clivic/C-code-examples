#pragma once

#include <string>
#include "PictureRecord.h"
#include "PictureInfoList.h"
#include "afxwin.h"
#include "SubGetOnePic.h"
// CSubDel �Ի���

class CSubDel : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDel)

public:
	CSubDel(CWnd* pParent = NULL);   // ��׼���캯��
	CSubDel(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);	//����Dlist�Ę��캯��
	virtual ~CSubDel();

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
