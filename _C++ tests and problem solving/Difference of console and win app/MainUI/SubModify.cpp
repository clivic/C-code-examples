// SubModify.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubModify.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"


// CSubModify 对话框

IMPLEMENT_DYNAMIC(CSubModify, CDialogEx)

CSubModify::CSubModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubModify::IDD, pParent)
	, m_owner(_T(""))
	, m_detail(_T(""))
	, m_titleEn(_T(""))
	, m_location(_T(""))
	, m_ECNU(false)
	, m_CHINA(false)
{

}

CSubModify::CSubModify(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubModify::IDD, pParent)
, m_owner(_T(""))
, m_detail(_T(""))
, m_titleEn(_T(""))
, m_location(_T(""))
{
	picListptr = ptr;
}

CSubModify::~CSubModify()
{
}

void CSubModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_owner);
	DDX_Text(pDX, IDC_EDIT_DETAIL, m_detail);
	DDX_Text(pDX, IDC_EDIT_TITLEEN, m_titleEn);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_location);
}


BEGIN_MESSAGE_MAP(CSubModify, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CSubModify::OnBnClickedButtonOpenfile)
	ON_EN_CHANGE(IDC_EDIT_PATH, &CSubModify::OnEnChangeEditPath)
	ON_EN_CHANGE(IDC_EDIT_TITLEEN, &CSubModify::OnEnChangeEditTitleen)
	ON_EN_CHANGE(IDC_EDIT_DETAIL, &CSubModify::OnEnChangeEditDetail)
	ON_EN_CHANGE(IDC_EDIT_OWNER, &CSubModify::OnEnChangeEditOwner)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CSubModify::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_HEIGHT, &CSubModify::OnEnChangeEditHeight)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CSubModify::OnEnChangeEditWidth)
	ON_EN_CHANGE(IDC_EDIT_SIZE, &CSubModify::OnEnChangeEditSize)
	ON_EN_CHANGE(IDC_EDIT_LOCATION, &CSubModify::OnEnChangeEditLocation)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CSubModify::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_RADIO_ECNU, &CSubModify::OnBnClickedRadioEcnu)
	ON_BN_CLICKED(IDC_RADIO_CHINA, &CSubModify::OnBnClickedRadioChina)
END_MESSAGE_MAP()


// CSubModify 消息处理程序


void CSubModify::OnBnClickedButtonOpenfile()
{
	//设置过滤器
	TCHAR szFilter[] = _T("JPEG文件(*.jpg)|*.jpg|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);
	//true 表示打開一個文件，過濾jpg，this指文件框父窗口

	CString strFilePath;

	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();					//獲取選擇的文檔路徑
		SetDlgItemText(IDC_EDIT_PATH, strFilePath);		//将其显示在文本框

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

		//查詢是否存在,並倒入
		PictureRecord temp;
		bool found = false;
		for (int i = 0; i < picListptr->size(); i++)
		{
			picListptr->retrieve(i, temp);
			if (temp.the_key().c_str() == fileDlg.GetFileName())
			{
				found = true;

				//導入
				m_detail = temp.the_detail().c_str();
				m_titleEn = temp.the_titleEn().c_str();
				m_location = temp.the_location().c_str();
				m_owner = temp.the_owner().c_str();
				map = temp.the_map();
				break;
			}
		}
		if (found == false)
		{
			MessageBox(_T("抱歉，所需修改之圖片不在圖片庫裏。"));
			return;		//不改值，還是原來的樣子
		}

		//先存儲部分信息
		width = jepg.GetWidth();
		height = jepg.GetHeight();
		size = int((jepg.GetDataLength()) / 1024.0 + 1); //上取整数
		key = fileDlg.GetFileName();

		ShowDefault();
	}
}

	//更新
	void CSubModify::OnEnChangeEditPath()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditTitleen()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditDetail()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditOwner()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditName()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditHeight()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditWidth()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditSize()
	{
		UpdateData(TRUE);
	}


	void CSubModify::OnEnChangeEditLocation()
	{
		UpdateData(TRUE);
	}

	//初值化
	void CSubModify::SetDefault()
	{
		m_detail = "";
		m_titleEn = "";
		m_location = "";
		m_owner = "";
	}

	//show到控件裏
	void CSubModify::ShowDefault()
	{
		
		UpdateData(FALSE);
		SetDlgItemText(IDC_EDIT_TITLEEN, m_titleEn);
		SetDlgItemText(IDC_EDIT_DETAIL, m_detail);
		SetDlgItemText(IDC_EDIT_LOCATION, m_location);
		SetDlgItemText(IDC_EDIT_OWNER, m_owner);
		SetDlgItemInt(IDC_EDIT_HEIGHT, height);
		SetDlgItemInt(IDC_EDIT_WIDTH, width);
		SetDlgItemInt(IDC_EDIT_SIZE, size);
	}

	void CSubModify::OnBnClickedButtonModify()
	{
		OthersType other;
		other.height = height;
		other.size = size;
		other.width = width;
		other.detail = (CStringA)m_detail;
		
		other.owner = (CStringA)m_owner;
		other.time = 1;
		other.titleEn = (CStringA)m_titleEn;
		other.location = (CStringA)m_location;
		PictureRecord item((string)(CStringA)key, other);

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

		if (picListptr->replace(item) == success)
		{
			MessageBox(TEXT("成功修改圖片" + key));
			picListptr->print();	//保存修改
		}
		else
			MessageBox(TEXT("抱歉，修改圖片失敗。"));
	}


	void CSubModify::OnBnClickedRadioEcnu()
	{
		m_ECNU = 1; m_CHINA = 0;
	}


	void CSubModify::OnBnClickedRadioChina()
	{
		m_ECNU = 0; m_CHINA = 1;
	}
