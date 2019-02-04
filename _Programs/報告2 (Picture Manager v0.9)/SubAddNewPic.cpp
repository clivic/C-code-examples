// SubAddNewPic.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubAddNewPic.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"
#include "Node.h"				//Error_code


// CSubAddNewPic 对话框

IMPLEMENT_DYNAMIC(CSubAddNewPic, CDialogEx)

CSubAddNewPic::CSubAddNewPic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubAddNewPic::IDD, pParent)
	, m_titleEn(_T(""))
	, m_detail(_T(""))
	, m_owner(_T(""))
	, m_ECNU(false)
	, m_CHINA(false)
	, m_location(_T(""))
{
	EnableAutomation();

}

CSubAddNewPic::CSubAddNewPic(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubAddNewPic::IDD, pParent)
, m_titleEn(_T(""))
, m_detail(_T(""))
, m_owner(_T(""))
, m_ECNU(false)
, m_CHINA(false)
, m_location(_T(""))
{
	EnableAutomation();
	picListptr = ptr;
	//默認初始化值
	height = size = width = 0;	time = 0;
	key = m_detail = m_titleEn = m_location = m_owner = "";
	map = hmap = hlocation = "";
	hasOpened = false;	//初始值，不能搜，打開之后再也不能是false
}

CSubAddNewPic::~CSubAddNewPic()
{
}

void CSubAddNewPic::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubAddNewPic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ENGTITLE, m_titleEn);
	DDX_Text(pDX, IDC_EDIT_CHINESE_TITLE, m_detail);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_owner);
	DDX_Text(pDX, IDC_EDIT_POS, m_location);
}


BEGIN_MESSAGE_MAP(CSubAddNewPic, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CSubAddNewPic::OnBnClickedButtonOpenfile)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CSubAddNewPic::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_HIGH, &CSubAddNewPic::OnEnChangeEditHigh)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CSubAddNewPic::OnEnChangeEditWidth)
	ON_EN_CHANGE(IDC_EDIT_SIZE, &CSubAddNewPic::OnEnChangeEditSize)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CSubAddNewPic::OnBnClickedButtonInsert)
	ON_EN_CHANGE(IDC_EDIT_POS, &CSubAddNewPic::OnEnChangeEditPos)
	ON_BN_CLICKED(IDC_RADIO_ECNU, &CSubAddNewPic::OnBnClickedRadioEcnu)
	ON_BN_CLICKED(IDC_RADIO_CHINA, &CSubAddNewPic::OnBnClickedRadioChina)
//	ON_EN_UPDATE(IDC_EDIT_ENGTITLE, &CSubAddNewPic::OnEnUpdateEditEngtitle)
	ON_EN_CHANGE(IDC_EDIT_ENGTITLE, &CSubAddNewPic::OnEnChangeEditEngtitle)
	ON_EN_CHANGE(IDC_EDIT_CHINESE_TITLE, &CSubAddNewPic::OnEnChangeEditChineseTitle)
//	ON_EN_UPDATE(IDC_EDIT_CHINESE_TITLE, &CSubAddNewPic::OnEnUpdateEditChineseTitle)
	ON_EN_CHANGE(IDC_EDIT_OWNER, &CSubAddNewPic::OnEnChangeEditOwner)
//	ON_EN_UPDATE(IDC_EDIT_OWNER, &CSubAddNewPic::OnEnUpdateEditOwner)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubAddNewPic, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubAddNewPic 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {2D222094-DF36-4F51-AE8C-50B3B78A0615}
static const IID IID_ISubAddNewPic =
{ 0x2D222094, 0xDF36, 0x4F51, { 0xAE, 0x8C, 0x50, 0xB3, 0xB7, 0x8A, 0x6, 0x15 } };

BEGIN_INTERFACE_MAP(CSubAddNewPic, CDialogEx)
	INTERFACE_PART(CSubAddNewPic, IID_ISubAddNewPic, Dispatch)
END_INTERFACE_MAP()


// CSubAddNewPic 消息处理程序


void CSubAddNewPic::OnBnClickedButtonOpenfile()
{
	// TODO:  在此添加控件通知处理程序代码
	//设置过滤器
	TCHAR szFilter[] = _T("JPEG文件(*.jpg)|*.jpg|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);
	//true 表示打開一個文件，過濾jpg，this指文件框父窗口

	CString strFilePath;

	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();					//獲取選擇的文檔路徑
		SetDlgItemText(IDC_EDIT_NAME_TO_OPEN, strFilePath);		//将其显示在文本框

		SetDlgItemText(IDC_EDIT_NAME, fileDlg.GetFileName());	//将文件名显示在文本框
		string fileName = (CStringA)strFilePath;				//存儲好路徑
		char tmpname[100];
		strcpy_s(tmpname, fileName.c_str());
		PdfJpeg jepg(tmpname);
		int readResult = jepg.ReadImage();
		if (readResult == -1)
		{
			MessageBox(_T("Warning: Fail in reading file: "));	return;
		}

		hasOpened = true;

		//先存儲部分信息
		width = jepg.GetWidth();
		height = jepg.GetHeight();
		size = int((jepg.GetDataLength()) / 1024.0 + 1); //上取整数
		key = fileDlg.GetFileName();
		sourcePath = strFilePath;
		
		SetDlgItemInt(IDC_EDIT_HIGH, width);
		SetDlgItemInt(IDC_EDIT_WIDTH, height);
		SetDlgItemInt(IDC_EDIT_SIZE, size);

	}


}

//用來存入添加的圖片到圖片庫的。
void FileCopyTo(CString source, CString destination, CString searchStr, BOOL cover = TRUE)
{
	CString strSourcePath = source;
	CString strDesPath = destination;
	CString strFileName = searchStr;
	CFileFind filefinder;
	CString strSearchPath = source;
	CString filename;
	BOOL bfind = filefinder.FindFile(strSearchPath);
	CString SourcePath, DisPath;
	while (bfind)
	{
		bfind = filefinder.FindNextFile();
		filename = strFileName;
		SourcePath = strSourcePath;
		DisPath = strDesPath + "//" + filename;
		CopyFile(SourcePath, DisPath, cover);
	}
	filefinder.Close();
}

//更新
void CSubAddNewPic::OnEnChangeEditName()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditHigh()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditWidth()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditSize()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditPos()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditEngtitle()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditChineseTitle()
{
	UpdateData(TRUE);
}


void CSubAddNewPic::OnEnChangeEditOwner()
{
	UpdateData(TRUE);
}


//添加
void CSubAddNewPic::OnBnClickedButtonInsert()
{
	if (hasOpened)
	{

		//判斷是否選擇了地圖，以及哪個地圖
		if (m_ECNU == 0 && m_CHINA == 0)
		{
			MessageBox(_T("請選擇一張地圖。"));	return;
		}
		else if (m_ECNU == 0 && m_CHINA == 1)
		{
			map = "中国";
			hmap = "null";
			hlocation = "null";
		}
		else
		{
			map = "华师大";
			hmap = "中国";
			hlocation = "上海";
		}

		//判斷是否寫了title
		if (m_titleEn == "")
			m_titleEn = key;			//默認用文件名作標題

		//判斷是否寫了owner
		if (m_owner == "")
			m_owner = "Administrator";	//默認用管理員作爲圖片所有者

		//判斷所屬地點是否在表中
		if (m_ECNU == 1 && m_CHINA == 0)//華師大
		{
			LocationGraph<200> mapECNU;
			int pos; VertexRecord vr;		//dummy
			string l = (CStringA)m_location;//location

			//允許""作爲地點名表匿名，不會顯示與足跡
			if (mapECNU.SearchByLocation(l, pos, vr) == notPresent && l != "")
			{
				MessageBox(_T("很抱歉，地點名不在地圖裏，請查看ecnu目錄下的introduction.txt。"));
				return;
			}
		}
		//else (m_ECNU == 1 && m_CHINA == 0)//中國

		OthersType insertone;
		CStringW strw = m_detail;
		CStringA stra(strw.GetBuffer(0));
		strw.ReleaseBuffer();
		std::string imgpath = stra.GetBuffer(0);

		CStringW strw0 = m_titleEn;
		CStringA stra0(strw0.GetBuffer(0));
		strw0.ReleaseBuffer();
		std::string imgpath0 = stra0.GetBuffer(0);

		CStringW strw1 = m_location;
		CStringA stra1(strw1.GetBuffer(0));
		strw1.ReleaseBuffer();
		std::string imgpath1 = stra1.GetBuffer(0);

		CStringW strw2 = (CString)hlocation.c_str();
		CStringA stra2(strw2.GetBuffer(0));
		strw2.ReleaseBuffer();
		std::string imgpath2 = stra2.GetBuffer(0);

		insertone.height = height;
		insertone.width = width;
		insertone.size = size;
		insertone.detail = imgpath;
		insertone.time = time;
		insertone.titleEn = imgpath0;
		insertone.location = imgpath1;
		insertone.hlocation = imgpath2;
		insertone.map = map;
		insertone.hmap = hmap;
		insertone.owner = (CStringA)m_owner;
		string aa = (CStringA)key;
		PictureRecord mycc = PictureRecord(aa, insertone);

		picListptr->insert(mycc);
		CString des("D:\\picLibrary");
		BOOL ccc = TRUE;
		FileCopyTo(sourcePath, des, key, ccc);
		MessageBox(_T("插入成功！"));
		picListptr->print();

		//把信息輸入info
		/*fstream fout;
		fout.open("info.txt", ios::app);
		PictureRecord tmp((string)(CStringA) key, insertone);
		fout << picListptr->size()+1 << "," << tmp;
		fout.close();*/
		picListptr->print();	//print一遍刷新

		//清空三個edit
		m_titleEn = "";
		m_detail = "";
		m_owner = "";
		UpdateData(FALSE); //将变量值的改变更新到界面。
		SetDlgItemText(IDC_EDIT_ENGTITLE, m_titleEn);
		SetDlgItemText(IDC_EDIT_CHINESE_TITLE, m_detail);
		SetDlgItemText(IDC_EDIT_OWNER, m_owner);
	}
}


//地圖控制
void CSubAddNewPic::OnBnClickedRadioEcnu()
{
	m_ECNU = 1; m_CHINA = 0;
}


void CSubAddNewPic::OnBnClickedRadioChina()
{
	m_ECNU = 0; m_CHINA = 1;
}

//更新輸入框
//void CSubAddNewPic::OnEnUpdateEditEngtitle()
//{
//	m_titleEn = "";
//}


//void CSubAddNewPic::OnEnUpdateEditChineseTitle()
//{
//	m_detail = "";
//}


//void CSubAddNewPic::OnEnUpdateEditOwner()
//{
//	m_owner = "";
//}
