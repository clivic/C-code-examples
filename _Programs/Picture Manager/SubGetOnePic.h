#pragma once
#include "afxwin.h"
#include "PictureRecord.h"
#include "PictureInfoList.h"

// CSubGetOnePic �Ի���

class CSubGetOnePic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubGetOnePic)

public:
	CSubGetOnePic(CWnd* pParent = NULL);				// ��׼���캯��
	//CSubGetOnePic(CWnd* pParent, PictureRecord *rec);	// ���DƬ�ļ����Դ��_,1.0�湦��,�F���ò�����
	CSubGetOnePic(CWnd* pParent, PictureInfoList *ptr, const int &no);	//���DƬlist��ԓ�DƬ��num
	virtual ~CSubGetOnePic();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DLG_DRAW_ONE_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	CStatic m_bigPic;
	CString title;
	CString m_name;
public:
	afx_msg void OnPaint();
private:
	//recordӛ�
	CString m_titleEn;
	CString m_owner;
	int m_height;
	int m_width;
	int m_size;
	CString m_detail;
	CString m_location;

	int currentNum;		//��ǰ�DƬ̖
	int count;			//�G�D��(picList��size)
	
	//SubSurf���ڂ����PictureInfoList
	PictureInfoList *picListptr;
public:
	afx_msg void OnBnClickedButtonNext();
	afx_msg void OnBnClickedButtonPrevious();
};
