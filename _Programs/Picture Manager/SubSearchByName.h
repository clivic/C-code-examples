#pragma once
#include "afxwin.h"
#include "PictureInfoList.h"
#include "SubGetOnePic.h"
#include "constants.h"		//控制導入照片作搜尋和結果顯示的最大量

// CSubSearchByName 对话框

class CSubSearchByName : public CDialogEx
{
	DECLARE_DYNAMIC(CSubSearchByName)

public:
	CSubSearchByName(CWnd* pParent = NULL);			//标准构造函数
	CSubSearchByName(CWnd* pParent, 
		PictureInfoList *ptr,
		bool isN);									//倒入圖list的構造函數
	virtual ~CSubSearchByName();
	//afx_msg void OnPaint();						//畫圖函式

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_NAME_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);		// DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	//四幅圖
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	
	//主窗口傳來的PictureInfoList和判斷用的isByName
	PictureInfoList *picListptr;
	bool isByName;	//1, by name, 0, by location

	//搜尋到的圖片的List
	PictureInfoList picListSearched;

	//照片導入相關
	CString filenames[MAX_NUM_LOADED];	//圖片文件地址(不包含根目錄)
	int currentPage;					//當前頁面號
	int numInPages;						//每頁圖數
	int count;							//縂圖數
	PictureRecord info;					//一個圖的Record
	bool hasSearched;

public:
	afx_msg void OnBnClickedButtonSearchMltpic();
private:
	CString m_search;
public:
	virtual BOOL OnInitDialog();
	
	//繪圖輔助函數
	void DrawPicture(CStatic *m_Pic/*控件名稱*/, int no/*控件編號0 .. numInPages-1*/);

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
	const Node<PictureRecord>* items[MAX_NUM_SEARCHED];
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
