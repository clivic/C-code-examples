#pragma once
#include "PictureInfoList.h"

// CSubModify 对话框

class CSubModify : public CDialogEx
{
	DECLARE_DYNAMIC(CSubModify)

public:
	CSubModify(CWnd* pParent = NULL);   // 标准构造函数
	CSubModify(CWnd* pParent = NULL,
		PictureInfoList *ptr = NULL);	//倒入圖list的構造函數
	virtual ~CSubModify();

// 对话框数据
	enum { IDD = IDD_DIALOG_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	//主窗口傳來的PictureInfoList
	PictureInfoList *picListptr;

	//導入用的數據
	//key
	CString key;	//文件名	

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

	////一整張圖片記錄
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

	void SetDefault();	//將各個框的值初始化
	void ShowDefault();	//將各個框的值show一下
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedRadioEcnu();
	afx_msg void OnBnClickedRadioChina();
private:
	bool m_ECNU;
	bool m_CHINA;
};
