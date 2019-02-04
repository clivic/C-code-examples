// SubGetOnePic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubGetOnePic.h"
#include "afxdialogex.h"
#include <atlimage.h>


// CSubGetOnePic �Ի���

IMPLEMENT_DYNAMIC(CSubGetOnePic, CDialogEx)

CSubGetOnePic::CSubGetOnePic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubGetOnePic::IDD, pParent)
	, m_name(_T(""))
	, m_titleEn(_T(""))
	, m_owner(_T(""))
	, m_height(0)
	, m_width(0)
	, m_size(0)
	, m_detail(_T(""))
	, m_location(_T(""))
{

	EnableAutomation();
}

// ���DƬ�ļ����Դ��_,1.0�湦��,�F���ò�����
//CSubGetOnePic::CSubGetOnePic(CWnd* pParent /*=NULL*/,
//	PictureRecord *rec)
//: CDialogEx(CSubGetOnePic::IDD, pParent)
//{
//
//	EnableAutomation();
//	title = rec->the_key().c_str();//filename
//	m_titleEn = rec->the_titleEn().c_str();
//	m_detail = rec->the_detail().c_str();
//	m_owner = rec->the_owner().c_str();
//	m_height = rec->the_height();
//	m_width = rec->the_width();
//	m_size = rec->the_size();
//	m_location = rec->the_location().c_str();
//}

//���DƬlist��ԓ�DƬ��num
CSubGetOnePic::CSubGetOnePic(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr, const int &no)
	: CDialogEx(CSubGetOnePic::IDD, pParent)
	, m_name(_T(""))
	, m_titleEn(_T(""))
	, m_owner(_T(""))
	, m_height(0)
	, m_width(0)
	, m_size(0)
	, m_detail(_T(""))
	, m_location(_T(""))
{
	picListptr = ptr;
	currentNum = no;
	count = ptr->size();
	PictureRecord rec;	//��ӛ�
	picListptr->retrieve(currentNum, rec);
	title = rec.the_key().c_str();//filename
	m_titleEn = rec.the_titleEn().c_str();
	m_detail = rec.the_detail().c_str();
	m_owner = rec.the_owner().c_str();
	m_height = rec.the_height();
	m_width = rec.the_width();
	m_size = rec.the_size();
	m_location = rec.the_location().c_str();
}

CSubGetOnePic::~CSubGetOnePic()
{
}

void CSubGetOnePic::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CSubGetOnePic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ONE_BIG_PIC, m_bigPic);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_TITLEEN, m_titleEn);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_owner);
	DDX_Text(pDX, IDC_EDIT_H, m_height);
	DDX_Text(pDX, IDC_EDIT_W, m_width);
	DDX_Text(pDX, IDC_EDIT_S, m_size);
	DDX_Text(pDX, IDC_EDIT_TITLECH, m_detail);
	DDX_Text(pDX, IDC_EDIT_PLACE, m_location);
}


BEGIN_MESSAGE_MAP(CSubGetOnePic, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSubGetOnePic::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSubGetOnePic::OnBnClickedButtonPrevious)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubGetOnePic, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_ISubGetOnePic ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {C6A05288-1BE8-4C9A-828E-54DB7B879E45}
static const IID IID_ISubGetOnePic =
{ 0xC6A05288, 0x1BE8, 0x4C9A, { 0x82, 0x8E, 0x54, 0xDB, 0x7B, 0x87, 0x9E, 0x45 } };

BEGIN_INTERFACE_MAP(CSubGetOnePic, CDialogEx)
	INTERFACE_PART(CSubGetOnePic, IID_ISubGetOnePic, Dispatch)
END_INTERFACE_MAP()


// CSubGetOnePic ��Ϣ�������


void CSubGetOnePic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect rectPic;
	m_bigPic.GetClientRect(&rectPic);   //m_pictureΪPicture Control�ؼ���������ÿؼ����������
	CDC* pDC = m_bigPic.GetWindowDC();  //�����ʾ�ؼ���DC

	CImage *pImage = new CImage();		//װ��ͼ�����

	CString basePath;
	basePath = "d:\\picLibrary\\";
	pImage->Load(basePath + title);		//�Ӵ���װ��ͼƬ

	int width = rectPic.Width();		//��ʾ����Ŀ�͸�
	int height = rectPic.Height();

	int picW = pImage->GetWidth();		//ͼƬ�Ŀ�͸�
	int picH = pImage->GetHeight();

	//��ֹ���ź�ͼƬʧ��
	SetStretchBltMode(pDC->m_hDC, HALFTONE);
	SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
	pImage->StretchBlt(pDC->m_hDC, 5, 5, width - 5, height - 5);

	//��ʾͼƬ
	pImage->Draw(pDC->m_hDC, 0, 0, width, height);

	m_name = title;
	UpdateData(FALSE); //������ֵ�ĸı���µ����档
	
}


void CSubGetOnePic::OnBnClickedButtonNext()
{
	if (currentNum < count - 1)
	{
		currentNum += 1;

		//��ӛ�
		PictureRecord rec;	
		picListptr->retrieve(currentNum, rec);
		title = rec.the_key().c_str();//filename
		m_titleEn = rec.the_titleEn().c_str();
		m_detail = rec.the_detail().c_str();
		m_owner = rec.the_owner().c_str();
		m_height = rec.the_height();
		m_width = rec.the_width();
		m_size = rec.the_size();
		m_location = rec.the_location().c_str();
		InvalidateRect(CRect(0, 0, 1000, 800), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ�������һ����Ŷ~"));
}


void CSubGetOnePic::OnBnClickedButtonPrevious()
{
	if (currentNum > 0)
	{
		currentNum -= 1;

		//��ӛ�
		PictureRecord rec;	
		picListptr->retrieve(currentNum, rec);
		title = rec.the_key().c_str();//filename
		m_titleEn = rec.the_titleEn().c_str();
		m_detail = rec.the_detail().c_str();
		m_owner = rec.the_owner().c_str();
		m_height = rec.the_height();
		m_width = rec.the_width();
		m_size = rec.the_size();
		m_location = rec.the_location().c_str();
		InvalidateRect(CRect(0, 0, 1000, 800), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ��ǵ�һ����Ŷ~"));
}
