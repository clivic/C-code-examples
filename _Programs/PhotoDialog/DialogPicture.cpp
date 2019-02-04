// DialogPicture.cpp : 实现文件
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "DialogPicture.h"
#include  "afxdialogex.h"


// CDialogPicture 对话框

IMPLEMENT_DYNAMIC(CDialogPicture, CDialogEx)

CDialogPicture::CDialogPicture(CWnd*pParent /*=NULL*/)
	: CDialogEx(CDialogPicture::IDD, pParent)
{
	//initial
	filenames[0] = "d:\\picLibrary\\127#01.jpg";
	filenames[1] = "d:\\picLibrary\\127#02.jpg";
	filenames[2] = "d:\\picLibrary\\127#03.jpg";
	filenames[3] = "d:\\picLibrary\\127#04.jpg";
	filenames[4] = "d:\\picLibrary\\127#05.jpg";
	filenames[5] = "d:\\picLibrary\\127#06.jpg";
	filenames[6] = "d:\\picLibrary\\127#07.jpg";
	filenames[7] = "d:\\picLibrary\\127#08.jpg";
	filenames[8] = "d:\\picLibrary\\127#09.jpg";
	filenames[9] = "d:\\picLibrary\\127#10.jpg";
	currentPage = 0;
	numInPages = 4;
	count = 10;
}

CDialogPicture::~CDialogPicture()
{
}

void CDialogPicture::DoDataExchange(CDataExchange*pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC1, m_pic1);
	DDX_Control(pDX, IDC_STATIC_PIC2, m_pic2);
	DDX_Control(pDX, IDC_STATIC_PIC3, m_pic3);
	DDX_Control(pDX, IDC_STATIC_PIC4, m_pic4);
}


BEGIN_MESSAGE_MAP(CDialogPicture, CDialogEx)
//	ON_STN_CLICKED(IDC_STATIC_PIC4, &CDialogPicture::OnStnClickedStaticPic4)
	ON_BN_CLICKED(IDC_NEXT, &CDialogPicture::OnBnClickedNext)
	ON_BN_CLICKED(IDC_PREVIOUS, &CDialogPicture::OnBnClickedPrevious)
	ON_WM_PAINT()
//	ON_STN_CLICKED(IDC_STATIC_PIC1, &CDialogPicture::OnStnClickedStaticPic1)
//	ON_STN_DBLCLK(IDC_STATIC_PIC2, &CDialogPicture::OnStnDblclickStaticPic2)
//	ON_STN_DBLCLK(IDC_STATIC_PIC1, &CDialogPicture::OnStnDblclickStaticPic1)
//	ON_STN_DBLCLK(IDC_STATIC_PIC3, &CDialogPicture::OnStnDblclickStaticPic3)
//	ON_STN_DBLCLK(IDC_STATIC_PIC4, &CDialogPicture::OnStnDblclickStaticPic4)
	ON_STN_CLICKED(IDC_STATIC_PIC1, &CDialogPicture::OnStnClickedStaticPic1)
	ON_STN_CLICKED(IDC_STATIC_PIC2, &CDialogPicture::OnStnClickedStaticPic2)
	ON_STN_CLICKED(IDC_STATIC_PIC3, &CDialogPicture::OnStnClickedStaticPic3)
	ON_STN_CLICKED(IDC_STATIC_PIC4, &CDialogPicture::OnStnClickedStaticPic4)
END_MESSAGE_MAP()


// CDialogPicture 消息处理程序


//void CDialogPicture::OnStnClickedStaticPic4()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}


void CDialogPicture::OnBnClickedNext()
{
	// TODO:  在此添加控件通知处理程序代码
	if (currentPage < count / numInPages)
	{
		currentPage++;
		InvalidateRect(CRect(109, 14, 165, 75), true);//强制刷新
	}
	else
		MessageBox(_T("已经是最后第一张了！"));
}


void CDialogPicture::OnBnClickedPrevious()
{
	// TODO:  在此添加控件通知处理程序代码
	if (currentPage > 0)
	{
		currentPage--;
		if (m_pic1.IsWindowVisible() == false)
			m_pic1.ShowWindow(SW_SHOW);
		if (m_pic2.IsWindowVisible() == false)
			m_pic2.ShowWindow(SW_SHOW);
		if (m_pic3.IsWindowVisible() == false)
			m_pic3.ShowWindow(SW_SHOW);
		if (m_pic4.IsWindowVisible() == false)
			m_pic4.ShowWindow(SW_SHOW);
		InvalidateRect(CRect(109, 14, 165, 75), true);//强制刷新}
	}
	else
			MessageBox(_T("已经是第一张了！"));
	
}


void CDialogPicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	drawPicture(&m_pic1, 0);
	drawPicture(&m_pic2, 1);
	drawPicture(&m_pic3, 2);
	drawPicture(&m_pic4, 3);
}

void CDialogPicture::drawPicture(CStatic*m_Pic/*控件名称*/, int no/*控件编号0-n-1*/)
{

	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);		//m_picture为Picture Control控件变量，获得控件的区域对象
	CDC*pDC = m_Pic->GetWindowDC();		//获得显示控件的DC

	CImage *pImage = new CImage();			//装载图像的类

	int pos = currentPage*numInPages + no;
	if (pos< count)							//还有图片可以显示
	{
		pImage->Load(filenames[pos]);		//从磁盘装载图片,根据页面计算得到的图片下标
		int width = rectPic.Width();		//显示区域的宽和高
		int height = rectPic.Height();

		int picW = pImage->GetWidth();		//图片的宽和高
		int picH = pImage->GetHeight();

		//计算缩放比
		double r1 = double(picW) / double(width);
		double r2 = double(picH) / double(height);
		//r为最优缩放比例
		double r = (r1 >= r2 ? r1 : r2);

		//防止缩放后失真
		SetStretchBltMode(pDC->m_hDC, HALFTONE);
		SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
		pImage->StretchBlt(pDC->m_hDC, 0, 0, int(picW / r), int(picH / r));
		//显示图片
		pImage->Draw(pDC->m_hDC, 0, 0, int(picW / r), int(picH / r));

		ReleaseDC(pDC);
		delete pImage;
	}
	else
	{
		m_Pic->ShowWindow(SW_HIDE);
	}
}


void CDialogPicture::OnStnClickedStaticPic1()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic2()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic3()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic4()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("图片名称为" + filenames[currentPage*numInPages + 0]));
}
