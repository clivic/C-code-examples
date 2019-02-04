// SubSearchByName.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubSearchByName.h"
#include "afxdialogex.h"
#include <atlimage.h>	//�D��̎��


// CSubSearchByName �Ի���

IMPLEMENT_DYNAMIC(CSubSearchByName, CDialogEx)

CSubSearchByName::CSubSearchByName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubSearchByName::IDD, pParent)
	, m_search(_T(""))//bug����
	, m_way(_T(""))
{

	EnableAutomation();

}

CSubSearchByName::CSubSearchByName(CWnd* pParent, PictureInfoList *ptr, bool isN)
: CDialogEx(CSubSearchByName::IDD, pParent)
, m_search(_T(""))
{
	picListptr = ptr;
	isByName = isN;
	hasSearched = false;

	EnableAutomation();
}

CSubSearchByName::~CSubSearchByName()
{
}

void CSubSearchByName::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ������������
	// ��������ĸ����������롣

	CDialogEx::OnFinalRelease();
}

void CSubSearchByName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1, m_pic1);
	DDX_Control(pDX, IDC_PIC2, m_pic2);
	DDX_Control(pDX, IDC_PIC3, m_pic3);
	DDX_Control(pDX, IDC_PIC4, m_pic4);
	DDX_Text(pDX, IDC_EDIT_SEARCH_BY_NAME, m_search);
	DDX_Text(pDX, IDC_SHOW_WAY, m_way);
}


BEGIN_MESSAGE_MAP(CSubSearchByName, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_MLTPIC, &CSubSearchByName::OnBnClickedButtonSearchMltpic)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CSubSearchByName::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, &CSubSearchByName::OnBnClickedButtonPrevious)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDIT_SEARCH_BY_NAME, &CSubSearchByName::OnEnChangeEditSearchByName)
	ON_STN_CLICKED(IDC_PIC1, &CSubSearchByName::OnStnClickedPic1)
	ON_STN_CLICKED(IDC_PIC2, &CSubSearchByName::OnStnClickedPic2)
	ON_STN_CLICKED(IDC_PIC3, &CSubSearchByName::OnStnClickedPic3)
	ON_STN_CLICKED(IDC_PIC4, &CSubSearchByName::OnStnClickedPic4)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubSearchByName, CDialogEx)
END_DISPATCH_MAP()

// ע��: �������� IID_ISubSearchByName ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {06999DF4-A175-421B-BD02-B11743FDD4E4}
static const IID IID_ISubSearchByName =
{ 0x6999DF4, 0xA175, 0x421B, { 0xBD, 0x2, 0xB1, 0x17, 0x43, 0xFD, 0xD4, 0xE4 } };

BEGIN_INTERFACE_MAP(CSubSearchByName, CDialogEx)
	INTERFACE_PART(CSubSearchByName, IID_ISubSearchByName, Dispatch)
END_INTERFACE_MAP()


// CSubSearchByName ��Ϣ��������


void CSubSearchByName::OnBnClickedButtonSearchMltpic()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
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
			picListSearched.clear();		//��Ҫ����ь����ĈDƬlist
			for (int k = 0; k < n; k++)
			{
				PictureRecord pr = items[k]->entry;
				picListSearched.insert(pr);			//����DƬ,�����g�[������
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
			picListSearched.clear();		//��Ҫ����ь����ĈDƬlist
			for (int k = 0; k < n; k++)
			{
				PictureRecord pr = items[k]->entry;
				picListSearched.insert(pr);			//����DƬ,�����g�[������
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


BOOL CSubSearchByName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	CString basePath;
	basePath = "d:\\picLibrary\\";
	//������Ƭ
	PictureRecord temp;
	for (int i = 0; i < picListptr->size(); i++)
	{
		picListptr->retrieve(i, temp);

		//�z�y�ˈD�Ƿ���picLibrary��Ŀ䛶Y
		CString sourcePath = basePath + (CString)temp.the_key().c_str();
		CFileFind filefinder;
		BOOL bfind = filefinder.FindFile(sourcePath);
		if (bfind)
			filenames[i] = sourcePath;
		else
		{
			i -= 1;	//׌��һ���D߀�ڴ�λ��
			picListptr->remove(temp);	//�hȥ��ӛ�
		}
		filefinder.Close();
	}
	picListptr->print();		//ˢ����
	
	currentPage = 0;
	numInPages = 4;
	count = picListptr->size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSubSearchByName::DrawPicture(CStatic *m_Pic/*�ؼ����Q*/, int no/*�ؼ���̖0 .. numInPages-1*/)
{
	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);   //m_pictureΪPicture Control�ؼ���������ÿؼ����������
	CDC *pDC = m_Pic->GetWindowDC();    //�����ʾ�ؼ���DC

	CImage *pImage = new CImage();		//װ��ͼ�����

	int pos = currentPage * numInPages + no;
	if (pos < count)
	{ 
		pImage->Load(filenames[pos]);	//�Ӵ���װ��ͼƬ,����ҳ�����õ���ͼƬ�±�
		int width = rectPic.Width();	//��ʾ����Ŀ��͸�
		int height = rectPic.Height();

		int picW = pImage->GetWidth();	//ͼƬ�Ŀ��͸�
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


void CSubSearchByName::OnBnClickedButtonNext()
{
	int maxPage = count%numInPages == 0 ? (count / numInPages - 1) : (count / numInPages);
	if (currentPage < maxPage)
	{
		currentPage += 1;
		InvalidateRect(CRect(109, 14, 165, 75), true);//ǿ��ˢ��
	}
	else
		MessageBox(_T("�Ѿ�������һ�M��Ŷ~"));

}


void CSubSearchByName::OnBnClickedButtonPrevious()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
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
			MessageBox(_T("�Ѿ��ǵ�һ�M��Ŷ~"));
}


void CSubSearchByName::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴�������Ϣ�����������
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


void CSubSearchByName::OnEnChangeEditSearchByName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);//���ڴ�
}


void CSubSearchByName::OnStnClickedPic1()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 0]));
	if (hasSearched)
	{
		CSubGetOnePic getOnePic(NULL, &picListSearched, currentPage*numInPages + 0);
		getOnePic.DoModal();
	}
	else
	{
		CSubGetOnePic getOnePic(NULL, picListptr, currentPage*numInPages + 0);	//��������ĈD�ó���info Record
		getOnePic.DoModal();
	}
}


void CSubSearchByName::OnStnClickedPic2()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 1]));
	if (hasSearched)
	{
		CSubGetOnePic getOnePic(NULL, &picListSearched, currentPage*numInPages + 1);
		getOnePic.DoModal();
	}
	else
	{
		CSubGetOnePic getOnePic(NULL, picListptr, currentPage*numInPages + 1);	//��������ĈD�ó���info Record
		getOnePic.DoModal();
	}
}


void CSubSearchByName::OnStnClickedPic3()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 2]));
	if (hasSearched)
	{
		CSubGetOnePic getOnePic(NULL, &picListSearched, currentPage*numInPages + 2);
		getOnePic.DoModal();
	}
	else
	{
		CSubGetOnePic getOnePic(NULL, picListptr, currentPage*numInPages + 2);	//��������ĈD�ó���info Record
		getOnePic.DoModal();
	}
}


void CSubSearchByName::OnStnClickedPic4()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	//MessageBox(_T("ͼƬ����Ϊ" + filenames[currentPage*numInPages + 3]));
	if (hasSearched)
	{
		CSubGetOnePic getOnePic(NULL, &picListSearched, currentPage*numInPages + 3);
		getOnePic.DoModal();
	}
	else
	{
		CSubGetOnePic getOnePic(NULL, picListptr, currentPage*numInPages + 3);	//��������ĈD�ó���info Record
		getOnePic.DoModal();
	}
}


BOOL CSubSearchByName::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ�����ר�ô����/����û���
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