// SubSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubSearch.h"
#include "afxdialogex.h"
#include <atlimage.h>	//圖像處理


// CSubSearch 对话框

IMPLEMENT_DYNAMIC(CSubSearch, CDialogEx)

CSubSearch::CSubSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubSearch::IDD, pParent)
	, m_search(_T(""))//bug修正
	, m_way(_T(""))
{

	EnableAutomation();

}

CSubSearch::CSubSearch(CWnd* pParent, PictureInfoList *ptr, bool isN)
: CDialogEx(CSubSearch::IDD, pParent)
, m_search(_T(""))
{
	picListptr = ptr;
	isByName = isN;
	hasSearched = false;

	EnableAutomation();
}

CSubSearch::~CSubSearch()
{
}

void CSubSearch::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CSubSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1, m_pic1);
	DDX_Control(pDX, IDC_PIC2, m_pic2);
	DDX_Control(pDX, IDC_PIC3, m_pic3);
	DDX_Control(pDX, IDC_PIC4, m_pic4);
	DDX_Text(pDX, IDC_EDIT_SEARCH_BY_NAME, m_search);
	DDX_Text(pDX, IDC_SHOW_WAY, m_way);
}


BEGIN_MESSAGE_MAP(CSubSearch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_MLTPIC, &CSubSearch::OnBnClickedButtonSearchMltpic)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSubSearch::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSubSearch::OnBnClickedButtonPrevious)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDIT_SEARCH_BY_NAME, &CSubSearch::OnEnChangeEditSearchByName)
	ON_STN_CLICKED(IDC_PIC1, &CSubSearch::OnStnClickedPic1)
	ON_STN_CLICKED(IDC_PIC2, &CSubSearch::OnStnClickedPic2)
	ON_STN_CLICKED(IDC_PIC3, &CSubSearch::OnStnClickedPic3)
	ON_STN_CLICKED(IDC_PIC4, &CSubSearch::OnStnClickedPic4)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubSearch, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ISubSearch 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {06999DF4-A175-421B-BD02-B11743FDD4E4}
static const IID IID_ISubSearch =
{ 0x6999DF4, 0xA175, 0x421B, { 0xBD, 0x2, 0xB1, 0x17, 0x43, 0xFD, 0xD4, 0xE4 } };

BEGIN_INTERFACE_MAP(CSubSearch, CDialogEx)
	INTERFACE_PART(CSubSearch, IID_ISubSearch, Dispatch)
END_INTERFACE_MAP()


// CSubSearch 消息处理程序


void CSubSearch::OnBnClickedButtonSearchMltpic()
{
	// TODO:  在此添加控件通知处理程序代码
	string forSearch = (CStringA)m_search; //CString -> string
	CString basepath("D:\\picLibrary\\");
	int n;
	//const Node<PictureRecord>* items[30];

	//searchByTitle(string title, int& n , Node<PictureRecord >*   items[]);
	if (isByName)	//按名字查找
	{
		if (forSearch == "")	return;	//throw這個搜尋消息
		if (picListptr->searchByTitle(forSearch, n, items) == success)
		{
			for (int k = 0; k < n; k++)
			{
				PictureRecord pr = items[k]->entry;
				filenames[k] = pr.the_key().c_str(); //string->CString
				filenames[k] = basepath + filenames[k];
			}
			currentPage = 0;
			count = n;
			InvalidateRect(CRect(109, 14, 165, 75), true);
			hasSearched = true;
		}
		else	MessageBox(_T("Sorry, can't find the word."));
	}
	else
	{
		if (forSearch == "")	return;	//throw這個搜尋消息
		if (picListptr->searchByLocation(forSearch, n, items) == success)
		{
			for (int k = 0; k < n; k++)
			{
				PictureRecord pr = items[k]->entry;
				filenames[k] = pr.the_key().c_str(); //string->CString
				filenames[k] = basepath + filenames[k];
			}
			currentPage = 0;
			count = n;
			InvalidateRect(CRect(109, 14, 165, 75), true);
			hasSearched = true;
		}
		else	MessageBox(_T("Sorry, can't find the word."));
	}
}


BOOL CSubSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString basePath;
	basePath = "d:\\picLibrary\\";
	//倒入照片
	PictureRecord temp;
	for (int i = 0; i < picListptr->size(); i++)
	{
		picListptr->retrieve(i, temp);
		filenames[i] = basePath + (CString)temp.the_key().c_str();
	}
	
	currentPage = 0;
	numInPages = 4;
	count = picListptr->size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CSubSearch::DrawPicture(CStatic *m_Pic/*控件名稱*/, int no/*控件編號0 .. numInPages-1*/)
{
	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);   //m_picture为Picture Control控件变量，获得控件的区域对象
	CDC *pDC = m_Pic->GetWindowDC();    //获得显示控件的DC

	CImage *pImage = new CImage();		//装载图像的类

	int pos = currentPage * numInPages + no;
	if (pos < count)
	{ 
		pImage->Load(filenames[pos]);	//从磁盘装载图片,根据页面计算得到的图片下标
		int width = rectPic.Width();	//显示区域的宽和高
		int height = rectPic.Height();

		int picW = pImage->GetWidth();	//图片的宽和高
		int picH = pImage->GetHeight();

		//防止缩放后图片失真
		SetStretchBltMode(pDC->m_hDC, HALFTONE);
		SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
		pImage->StretchBlt(pDC->m_hDC, 5, 5, width - 5, height - 5);
		
		//显示图片
		//pImage->Draw(pDC->m_hDC, 5, 5, width - 5, height - 5);
		pImage->Draw(pDC->m_hDC, 0, 0, width, height);

		ReleaseDC(pDC);
		delete pImage;

	}

	else
	{
		m_Pic->ShowWindow(SW_HIDE);
	}
}


void CSubSearch::OnBnClickedButtonNext()
{
	// TODO:  在此添加控件通知处理程序代码
	if (currentPage < count / numInPages)
	{
		currentPage += 1;
		InvalidateRect(CRect(109, 14, 165, 75), true);//强制刷新
	}
	else
		MessageBox(_T("已经是最后第一张了哦~"));

}


void CSubSearch::OnBnClickedButtonPrevious()
{
	// TODO:  在此添加控件通知处理程序代码
	if (currentPage > 0)
	{
		currentPage -= 1;
		if (m_pic1.IsWindowVisible() == false)
			m_pic1.ShowWindow(SW_SHOW);
		if (m_pic2.IsWindowVisible() == false)
			m_pic2.ShowWindow(SW_SHOW);
		if (m_pic3.IsWindowVisible() == false)
			m_pic3.ShowWindow(SW_SHOW);
		if (m_pic4.IsWindowVisible() == false)
			m_pic4.ShowWindow(SW_SHOW);

		InvalidateRect(CRect(109, 14, 165, 75), true);//强制刷新
	}
		else
			MessageBox(_T("已经是第一张了哦~"));
}


void CSubSearch::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	//刷圖,相當於OnPaint函數也許
	DrawPicture(&m_pic1, 0);
	DrawPicture(&m_pic2, 1);
	DrawPicture(&m_pic3, 2);
	DrawPicture(&m_pic4, 3);

	//顯示如何查找
	if (isByName)	m_way = "按標題查找";
	else			m_way = "按拍攝地址查找";

	UpdateData(FALSE); //将变量值的改变更新到界面。
}


void CSubSearch::OnEnChangeEditSearchByName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);//到内存
}


void CSubSearch::OnStnClickedPic1()
{
	// TODO:  在此添加控件通知处理程序代码
	//MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 0]));
	if (hasSearched)
		info = items[currentPage*numInPages + 0]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 0, info);	//將對應框的圖拿出到info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic2()
{
	// TODO:  在此添加控件通知处理程序代码
	//MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 1]));
	if (hasSearched)
		info = items[currentPage*numInPages + 1]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 1, info);	//將對應框的圖拿出到info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic3()
{
	// TODO:  在此添加控件通知处理程序代码
	//MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 2]));
	if (hasSearched)
		info = items[currentPage*numInPages + 2]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 2, info);	//將對應框的圖拿出到info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic4()
{
	// TODO:  在此添加控件通知处理程序代码
	//MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 3]));
	if (hasSearched)
		info = items[currentPage*numInPages + 3]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 3, info);	//將對應框的圖拿出到info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


BOOL CSubSearch::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)

	{

		if (pMsg->wParam == VK_RETURN)//当按下键为回车键时

		{

			OnBnClickedButtonSearchMltpic();//调用按钮函数

			return TRUE;

		}

	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
