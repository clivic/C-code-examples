// SubReview.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubReview.h"
#include "afxdialogex.h"
#include "SubGetOnePic.h"


// CSubReview �Ի���

IMPLEMENT_DYNAMIC(CSubReview, CDialogEx)

CSubReview::CSubReview(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubReview::IDD, pParent)
	, m_filename(_T(""))
{

}

CSubReview::CSubReview(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubReview::IDD, pParent)
, m_filename(_T(""))
{
	picListptr = ptr;
}

CSubReview::~CSubReview()
{
}

void CSubReview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_filename);
	DDX_Control(pDX, IDC_STATIC_PIC1, m_pic1);
	DDX_Control(pDX, IDC_STATIC_PIC2, m_pic2);
	DDX_Control(pDX, IDC_STATIC_PIC3, m_pic3);
	DDX_Control(pDX, IDC_STATIC_PIC4, m_pic4);
	DDX_Control(pDX, IDC_STATIC_PIC5, m_pic5);
	DDX_Control(pDX, IDC_STATIC_PIC6, m_pic6);
	DDX_Control(pDX, IDC_STATIC_PIC7, m_pic7);
	DDX_Control(pDX, IDC_STATIC_PIC8, m_pic8);
	DDX_Control(pDX, IDC_STATIC_PIC9, m_pic9);
	DDX_Control(pDX, IDC_STATIC_PIC10, m_pic10);
	DDX_Control(pDX, IDC_STATIC_PIC11, m_pic11);
	DDX_Control(pDX, IDC_STATIC_PIC12, m_pic12);
	DDX_Control(pDX, IDC_STATIC_PIC13, m_pic13);
	DDX_Control(pDX, IDC_STATIC_PIC14, m_pic14);
	DDX_Control(pDX, IDC_STATIC_PIC15, m_pic15);
	DDX_Control(pDX, IDC_STATIC_PIC16, m_pic16);
	DDX_Control(pDX, IDC_STATIC_PIC17, m_pic17);
	DDX_Control(pDX, IDC_STATIC_PIC18, m_pic18);
	DDX_Control(pDX, IDC_STATIC_PIC19, m_pic19);
	DDX_Control(pDX, IDC_STATIC_PIC20, m_pic20);
	DDX_Control(pDX, IDC_STATIC_PIC21, m_pic21);
	DDX_Control(pDX, IDC_STATIC_PIC22, m_pic22);
	DDX_Control(pDX, IDC_STATIC_PIC23, m_pic23);
	DDX_Control(pDX, IDC_STATIC_PIC24, m_pic24);
	DDX_Control(pDX, IDC_STATIC_PIC25, m_pic25);

}


BEGIN_MESSAGE_MAP(CSubReview, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_SURF_NEXT, &CSubReview::OnBnClickedButtonSurfNext)
	ON_BN_CLICKED(IDC_BUTTON_SURF_PREVIOUS, &CSubReview::OnBnClickedButtonSurfPrevious)
	ON_STN_CLICKED(IDC_STATIC_PIC1, &CSubReview::OnStnClickedStaticPic1)
	ON_STN_CLICKED(IDC_STATIC_PIC2, &CSubReview::OnStnClickedStaticPic2)
	ON_STN_CLICKED(IDC_STATIC_PIC3, &CSubReview::OnStnClickedStaticPic3)
	ON_STN_CLICKED(IDC_STATIC_PIC4, &CSubReview::OnStnClickedStaticPic4)
	ON_STN_CLICKED(IDC_STATIC_PIC5, &CSubReview::OnStnClickedStaticPic5)
	ON_STN_CLICKED(IDC_STATIC_PIC6, &CSubReview::OnStnClickedStaticPic6)
	ON_STN_CLICKED(IDC_STATIC_PIC7, &CSubReview::OnStnClickedStaticPic7)
	ON_STN_CLICKED(IDC_STATIC_PIC8, &CSubReview::OnStnClickedStaticPic8)
	ON_STN_CLICKED(IDC_STATIC_PIC9, &CSubReview::OnStnClickedStaticPic9)
	ON_STN_CLICKED(IDC_STATIC_PIC10, &CSubReview::OnStnClickedStaticPic10)
	ON_STN_CLICKED(IDC_STATIC_PIC11, &CSubReview::OnStnClickedStaticPic11)
	ON_STN_CLICKED(IDC_STATIC_PIC12, &CSubReview::OnStnClickedStaticPic12)
	ON_STN_CLICKED(IDC_STATIC_PIC13, &CSubReview::OnStnClickedStaticPic13)
	ON_STN_CLICKED(IDC_STATIC_PIC14, &CSubReview::OnStnClickedStaticPic14)
	ON_STN_CLICKED(IDC_STATIC_PIC15, &CSubReview::OnStnClickedStaticPic15)
	ON_STN_CLICKED(IDC_STATIC_PIC16, &CSubReview::OnStnClickedStaticPic16)
	ON_STN_CLICKED(IDC_STATIC_PIC17, &CSubReview::OnStnClickedStaticPic17)
	ON_STN_CLICKED(IDC_STATIC_PIC18, &CSubReview::OnStnClickedStaticPic18)
	ON_STN_CLICKED(IDC_STATIC_PIC19, &CSubReview::OnStnClickedStaticPic19)
	ON_STN_CLICKED(IDC_STATIC_PIC20, &CSubReview::OnStnClickedStaticPic20)
	ON_STN_CLICKED(IDC_STATIC_PIC21, &CSubReview::OnStnClickedStaticPic21)
	ON_STN_CLICKED(IDC_STATIC_PIC22, &CSubReview::OnStnClickedStaticPic22)
	ON_STN_CLICKED(IDC_STATIC_PIC23, &CSubReview::OnStnClickedStaticPic23)
	ON_STN_CLICKED(IDC_STATIC_PIC24, &CSubReview::OnStnClickedStaticPic24)
	ON_STN_CLICKED(IDC_STATIC_PIC25, &CSubReview::OnStnClickedStaticPic25)
END_MESSAGE_MAP()


// CSubReview ��Ϣ�������


void CSubReview::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	
	DrawPicture(&m_pic1,0);
	DrawPicture(&m_pic2, 1);
	DrawPicture(&m_pic3, 2);
	DrawPicture(&m_pic4, 3);
	DrawPicture(&m_pic5, 4);
	DrawPicture(&m_pic6, 5);
	DrawPicture(&m_pic7, 6);
	DrawPicture(&m_pic8, 7);
	DrawPicture(&m_pic9, 8);
	DrawPicture(&m_pic10, 9);
	DrawPicture(&m_pic11, 10);
	DrawPicture(&m_pic12, 11);
	DrawPicture(&m_pic13, 12);
	DrawPicture(&m_pic14, 13);
	DrawPicture(&m_pic15, 14);
	DrawPicture(&m_pic16, 15);
	DrawPicture(&m_pic17, 16);
	DrawPicture(&m_pic18, 17);
	DrawPicture(&m_pic19, 18);
	DrawPicture(&m_pic20, 19);
	DrawPicture(&m_pic21, 20);
	DrawPicture(&m_pic22, 21);
	DrawPicture(&m_pic23, 22);
	DrawPicture(&m_pic24, 23);
	DrawPicture(&m_pic25, 24);
}

void CSubReview::DrawPicture(CStatic *m_Pic/*�ؼ����Q*/, int no/*�ؼ���̖0 .. numInPages-1*/)
{
	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);   //m_pictureΪPicture Control�ؼ���������ÿؼ����������
	CDC *pDC = m_Pic->GetWindowDC();    //�����ʾ�ؼ���DC

	CImage *pImage = new CImage();		//װ��ͼ�����

	int pos = currentPage * numInPages + no;
	if (pos < count)
	{
		pImage->Load(filenames[pos]);	//�Ӵ���װ��ͼƬ,����ҳ�����õ���ͼƬ�±�
		int width = rectPic.Width();	//��ʾ����Ŀ�͸�
		int height = rectPic.Height();

		int picW = pImage->GetWidth();	//ͼƬ�Ŀ�͸�
		int picH = pImage->GetHeight();

		//��ֹ���ź�ͼƬʧ��
		SetStretchBltMode(pDC->m_hDC, HALFTONE);
		SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
		pImage->StretchBlt(pDC->m_hDC, 5, 5, width - 5, height - 5);

		//��ʾͼƬ
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



BOOL CSubReview::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CString basePath;
	basePath = "d:\\picLibrary\\";
	//������Ƭ
	PictureRecord temp;
	for (int i = 0; i < picListptr->size(); i++)
	{
		picListptr->retrieve(i, temp);
		filenames[i] = basePath + (CString)temp.the_key().c_str();
	}
	
	currentPage = 0;
	numInPages = 25;
	count = picListptr->size();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSubReview::OnBnClickedButtonSurfNext()
{
	if (currentPage < count / numInPages)
	{
		currentPage += 1;
		InvalidateRect(CRect(0, 0, 1000, 800), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ�������һ�M��Ŷ~"));
}


void CSubReview::OnBnClickedButtonSurfPrevious()
{
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
		if (m_pic5.IsWindowVisible() == false)
			m_pic5.ShowWindow(SW_SHOW);
		if (m_pic6.IsWindowVisible() == false)
			m_pic6.ShowWindow(SW_SHOW);
		if (m_pic7.IsWindowVisible() == false)
			m_pic7.ShowWindow(SW_SHOW);
		if (m_pic8.IsWindowVisible() == false)
			m_pic8.ShowWindow(SW_SHOW);
		if (m_pic9.IsWindowVisible() == false)
			m_pic9.ShowWindow(SW_SHOW);
		if (m_pic10.IsWindowVisible() == false)
			m_pic10.ShowWindow(SW_SHOW);
		if (m_pic11.IsWindowVisible() == false)
			m_pic11.ShowWindow(SW_SHOW);
		if (m_pic12.IsWindowVisible() == false)
			m_pic12.ShowWindow(SW_SHOW);
		if (m_pic13.IsWindowVisible() == false)
			m_pic13.ShowWindow(SW_SHOW);
		if (m_pic14.IsWindowVisible() == false)
			m_pic14.ShowWindow(SW_SHOW);
		if (m_pic15.IsWindowVisible() == false)
			m_pic15.ShowWindow(SW_SHOW);
		if (m_pic16.IsWindowVisible() == false)
			m_pic16.ShowWindow(SW_SHOW);
		if (m_pic17.IsWindowVisible() == false)
			m_pic17.ShowWindow(SW_SHOW);
		if (m_pic18.IsWindowVisible() == false)
			m_pic18.ShowWindow(SW_SHOW);
		if (m_pic19.IsWindowVisible() == false)
			m_pic19.ShowWindow(SW_SHOW);
		if (m_pic20.IsWindowVisible() == false)
			m_pic20.ShowWindow(SW_SHOW);
		if (m_pic21.IsWindowVisible() == false)
			m_pic21.ShowWindow(SW_SHOW);
		if (m_pic22.IsWindowVisible() == false)
			m_pic22.ShowWindow(SW_SHOW);
		if (m_pic23.IsWindowVisible() == false)
			m_pic23.ShowWindow(SW_SHOW);
		if (m_pic24.IsWindowVisible() == false)
			m_pic24.ShowWindow(SW_SHOW);
		if (m_pic25.IsWindowVisible() == false)
			m_pic25.ShowWindow(SW_SHOW);

		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ��ǵ�һ�M��Ŷ~"));
}


void CSubReview::OnStnClickedStaticPic1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 0, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 1, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 2, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 3, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 4, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 5, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 6, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 7, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 8, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 9, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 10, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 11, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 12, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 13, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic15()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 14, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 15, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic17()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 16, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic18()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 17, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic19()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 18, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic20()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 19, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic21()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 20, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic22()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 21, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic23()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 22, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic24()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 23, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubReview::OnStnClickedStaticPic25()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	picListptr->retrieve(currentPage*numInPages + 24, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}
