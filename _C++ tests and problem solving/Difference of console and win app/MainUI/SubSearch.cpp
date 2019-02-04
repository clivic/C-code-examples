// SubSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubSearch.h"
#include "afxdialogex.h"
#include <atlimage.h>	//�D��̎��


// CSubSearch �Ի���

IMPLEMENT_DYNAMIC(CSubSearch, CDialogEx)

CSubSearch::CSubSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubSearch::IDD, pParent)
	, m_search(_T(""))//bug����
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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_ISubSearch ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {06999DF4-A175-421B-BD02-B11743FDD4E4}
static const IID IID_ISubSearch =
{ 0x6999DF4, 0xA175, 0x421B, { 0xBD, 0x2, 0xB1, 0x17, 0x43, 0xFD, 0xD4, 0xE4 } };

BEGIN_INTERFACE_MAP(CSubSearch, CDialogEx)
	INTERFACE_PART(CSubSearch, IID_ISubSearch, Dispatch)
END_INTERFACE_MAP()


// CSubSearch ��Ϣ�������


void CSubSearch::OnBnClickedButtonSearchMltpic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	string forSearch = (CStringA)m_search; //CString -> string
	CString basepath("D:\\picLibrary\\");
	int n;
	//const Node<PictureRecord>* items[30];

	//searchByTitle(string title, int& n , Node<PictureRecord >*   items[]);
	if (isByName)	//�����ֲ���
	{
		if (forSearch == "")	return;	//throw�@���ь���Ϣ
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
		if (forSearch == "")	return;	//throw�@���ь���Ϣ
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
	numInPages = 4;
	count = picListptr->size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSubSearch::DrawPicture(CStatic *m_Pic/*�ؼ����Q*/, int no/*�ؼ���̖0 .. numInPages-1*/)
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


void CSubSearch::OnBnClickedButtonNext()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (currentPage < count / numInPages)
	{
		currentPage += 1;
		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ�������һ����Ŷ~"));

}


void CSubSearch::OnBnClickedButtonPrevious()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��
	}
		else
			MessageBox(_T("�Ѿ��ǵ�һ����Ŷ~"));
}


void CSubSearch::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//ˢ�D,�ஔ�OnPaint����Ҳ�S
	DrawPicture(&m_pic1, 0);
	DrawPicture(&m_pic2, 1);
	DrawPicture(&m_pic3, 2);
	DrawPicture(&m_pic4, 3);

	//�@ʾ��β���
	if (isByName)	m_way = "�����}����";
	else			m_way = "���Ĕz��ַ����";

	UpdateData(FALSE); //������ֵ�ĸı���µ����档
}


void CSubSearch::OnEnChangeEditSearchByName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);//���ڴ�
}


void CSubSearch::OnStnClickedPic1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
	if (hasSearched)
		info = items[currentPage*numInPages + 0]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 0, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 1]));
	if (hasSearched)
		info = items[currentPage*numInPages + 1]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 1, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 2]));
	if (hasSearched)
		info = items[currentPage*numInPages + 2]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 2, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


void CSubSearch::OnStnClickedPic4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 3]));
	if (hasSearched)
		info = items[currentPage*numInPages + 3]->entry;
	else
		picListptr->retrieve(currentPage*numInPages + 3, info);	//��������ĈD�ó���info Record
	CSubGetOnePic getOnePic(NULL, &info);
	getOnePic.DoModal();
}


BOOL CSubSearch::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)

	{

		if (pMsg->wParam == VK_RETURN)//�����¼�Ϊ�س���ʱ

		{

			OnBnClickedButtonSearchMltpic();//���ð�ť����

			return TRUE;

		}

	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
