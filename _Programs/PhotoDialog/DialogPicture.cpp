// DialogPicture.cpp : ʵ���ļ�
//

#include  "stdafx.h"
#include  "PhotoDialog.h"
#include  "DialogPicture.h"
#include  "afxdialogex.h"


// CDialogPicture �Ի���

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


// CDialogPicture ��Ϣ�������


//void CDialogPicture::OnStnClickedStaticPic4()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


void CDialogPicture::OnBnClickedNext()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (currentPage < count / numInPages)
	{
		currentPage++;
		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ�������һ���ˣ�"));
}


void CDialogPicture::OnBnClickedPrevious()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��}
	}
	else
			MessageBox(_T("�Ѿ��ǵ�һ���ˣ�"));
	
}


void CDialogPicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	drawPicture(&m_pic1, 0);
	drawPicture(&m_pic2, 1);
	drawPicture(&m_pic3, 2);
	drawPicture(&m_pic4, 3);
}

void CDialogPicture::drawPicture(CStatic*m_Pic/*�ؼ�����*/, int no/*�ؼ����0-n-1*/)
{

	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);		//m_pictureΪPicture Control�ؼ���������ÿؼ����������
	CDC*pDC = m_Pic->GetWindowDC();		//�����ʾ�ؼ���DC

	CImage *pImage = new CImage();			//װ��ͼ�����

	int pos = currentPage*numInPages + no;
	if (pos< count)							//����ͼƬ������ʾ
	{
		pImage->Load(filenames[pos]);		//�Ӵ���װ��ͼƬ,����ҳ�����õ���ͼƬ�±�
		int width = rectPic.Width();		//��ʾ����Ŀ�͸�
		int height = rectPic.Height();

		int picW = pImage->GetWidth();		//ͼƬ�Ŀ�͸�
		int picH = pImage->GetHeight();

		//�������ű�
		double r1 = double(picW) / double(width);
		double r2 = double(picH) / double(height);
		//rΪ�������ű���
		double r = (r1 >= r2 ? r1 : r2);

		//��ֹ���ź�ʧ��
		SetStretchBltMode(pDC->m_hDC, HALFTONE);
		SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
		pImage->StretchBlt(pDC->m_hDC, 0, 0, int(picW / r), int(picH / r));
		//��ʾͼƬ
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
}


void CDialogPicture::OnStnClickedStaticPic4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
}
