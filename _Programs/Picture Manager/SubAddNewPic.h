#pragma once
#include "PictureInfoList.h"


// CSubAddNewPic 对话框

class CSubAddNewPic : public CDialogEx
{
	DECLARE_DYNAMIC(CSubAddNewPic)

public:
	CSubAddNewPic(CWnd* pParent = NULL);   // 标准构造函数
	CSubAddNewPic(CWnd* pParent = NULL, 
		PictureInfoList *ptr = NULL);	//倒入圖list的構造函數
	virtual ~CSubAddNewPic();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_SUBDIALOG_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
	//主窗口傳來的PictureInfoList
	PictureInfoList *picListptr;

	//導入用的數據
	//key
	CString key;	//文件名	

	//圖片原始路徑
	CString sourcePath;

	//othertype
	int height;
	int width;
	int size;
	long time;
	CString m_detail;		//中文
	CString m_titleEn;		//英文title
	string map;				//所属地图
	CString m_location;		//地图中的位置
	string hmap;			//所属上级地图
	string hlocation;		//hmap中的位置
	CString m_owner;		//属主
	
public:
	afx_msg void OnBnClickedButtonInsert();
private:
	bool m_ECNU;
	bool m_CHINA;
	bool hasOpened;			//用來控制是不是剛剛打開框，剛打開不刷圖
	
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
