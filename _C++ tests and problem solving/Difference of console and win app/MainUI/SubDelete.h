#pragma once

#include <string>
#include "PictureRecord.h"
#include "PictureInfoList.h"
#include "afxwin.h"
#include "SubGetOnePic.h"
// CSubDelete 对话框

class CSubDelete : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDelete)

public:
	CSubDelete(CWnd* pParent = NULL);   // 标准构造函数
	CSubDelete(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);	//倒入圖list的構造函數
	virtual ~CSubDelete();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_DEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpen();
private:
	//主窗口傳來的PictureInfoList
	PictureInfoList *picListptr;
	PictureRecord info;			//一個圖的Record
public:
	afx_msg void OnPaint();
	void DrawPicture(CStatic *m_Pic/*控件名稱*/);
private:
	CStatic m_pic;
	bool hasOpened;				//用來控制是不是剛剛打開框，剛打開不刷圖
public:
	afx_msg void OnStnClickedStaticPic();
	afx_msg void OnBnClickedButtonDel();
};

//用來刪除文件
void DeleteFileInDirectory(CString strDir);
