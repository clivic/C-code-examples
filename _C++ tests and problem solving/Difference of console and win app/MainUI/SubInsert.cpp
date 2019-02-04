// SubInsert.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubInsert.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"
#include "Node.h"				//Error_code


// CSubInsert �Ի���

IMPLEMENT_DYNAMIC(CSubInsert, CDialogEx)

CSubInsert::CSubInsert(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubInsert::IDD, pParent)
	, m_titleEn(_T(""))
	, m_detail(_T(""))
	, m_owner(_T(""))
	, m_ECNU(false)
	, m_CHINA(false)
	, m_location(_T(""))
{
	EnableAutomation();

}

CSubInsert::CSubInsert(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubInsert::IDD, pParent)
, m_titleEn(_T(""))
, m_detail(_T(""))
, m_owner(_T(""))
, m_ECNU(false)
, m_CHINA(false)
, m_location(_T(""))
{
	EnableAutomation();
	picListptr = ptr;
	//Ĭ�J��ʼ��ֵ
	height = size = width = 0;	time = 0;
	key = m_detail = m_titleEn = m_location = m_owner = "";
	map = hmap = hlocation = "";
	hasOpened = false;	//��ʼֵ�������ѣ����_֮����Ҳ������false
}

CSubInsert::~CSubInsert()
{
}

void CSubInsert::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CSubInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ENGTITLE, m_titleEn);
	DDX_Text(pDX, IDC_EDIT_CHINESE_TITLE, m_detail);
	DDX_Text(pDX, IDC_EDIT_OWNER, m_owner);
	DDX_Text(pDX, IDC_EDIT_POS, m_location);
}


BEGIN_MESSAGE_MAP(CSubInsert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CSubInsert::OnBnClickedButtonOpenfile)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CSubInsert::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_HIGH, &CSubInsert::OnEnChangeEditHigh)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CSubInsert::OnEnChangeEditWidth)
	ON_EN_CHANGE(IDC_EDIT_SIZE, &CSubInsert::OnEnChangeEditSize)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CSubInsert::OnBnClickedButtonInsert)
	ON_EN_CHANGE(IDC_EDIT_POS, &CSubInsert::OnEnChangeEditPos)
	ON_BN_CLICKED(IDC_RADIO_ECNU, &CSubInsert::OnBnClickedRadioEcnu)
	ON_BN_CLICKED(IDC_RADIO_CHINA, &CSubInsert::OnBnClickedRadioChina)
//	ON_EN_UPDATE(IDC_EDIT_ENGTITLE, &CSubInsert::OnEnUpdateEditEngtitle)
	ON_EN_CHANGE(IDC_EDIT_ENGTITLE, &CSubInsert::OnEnChangeEditEngtitle)
	ON_EN_CHANGE(IDC_EDIT_CHINESE_TITLE, &CSubInsert::OnEnChangeEditChineseTitle)
//	ON_EN_UPDATE(IDC_EDIT_CHINESE_TITLE, &CSubInsert::OnEnUpdateEditChineseTitle)
	ON_EN_CHANGE(IDC_EDIT_OWNER, &CSubInsert::OnEnChangeEditOwner)
//	ON_EN_UPDATE(IDC_EDIT_OWNER, &CSubInsert::OnEnUpdateEditOwner)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubInsert, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_ISubInsert ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {2D222094-DF36-4F51-AE8C-50B3B78A0615}
static const IID IID_ISubInsert =
{ 0x2D222094, 0xDF36, 0x4F51, { 0xAE, 0x8C, 0x50, 0xB3, 0xB7, 0x8A, 0x6, 0x15 } };

BEGIN_INTERFACE_MAP(CSubInsert, CDialogEx)
	INTERFACE_PART(CSubInsert, IID_ISubInsert, Dispatch)
END_INTERFACE_MAP()


// CSubInsert ��Ϣ�������


void CSubInsert::OnBnClickedButtonOpenfile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//���ù�����
	TCHAR szFilter[] = _T("JPEG�ļ�(*.jpg)|*.jpg|�����ļ�(*.*)|*.*||");
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);
	//true ��ʾ���_һ���ļ����^�Vjpg��thisָ�ļ��򸸴���

	CString strFilePath;

	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();					//�@ȡ�x����ęn·��
		SetDlgItemText(IDC_EDIT_NAME_TO_OPEN, strFilePath);		//������ʾ���ı���

		SetDlgItemText(IDC_EDIT_NAME, fileDlg.GetFileName());	//���ļ�����ʾ���ı���
		string fileName = (CStringA)strFilePath;				//�惦��·��
		char tmpname[100];
		strcpy_s(tmpname, fileName.c_str());
		PdfJpeg jepg(tmpname);
		int readResult = jepg.ReadImage();
		if (readResult == -1)
		{
			MessageBox(_T("Warning: Fail in reading file: "));	return;
		}

		hasOpened = true;

		//�ȴ惦������Ϣ
		width = jepg.GetWidth();
		height = jepg.GetHeight();
		size = int((jepg.GetDataLength()) / 1024.0 + 1); //��ȡ����
		key = fileDlg.GetFileName();
		sourcePath = strFilePath;
		
		SetDlgItemInt(IDC_EDIT_HIGH, width);
		SetDlgItemInt(IDC_EDIT_WIDTH, height);
		SetDlgItemInt(IDC_EDIT_SIZE, size);

	}


}

//�Á������ӵĈDƬ���DƬ��ġ�
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

//����
void CSubInsert::OnEnChangeEditName()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditHigh()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditWidth()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditSize()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditPos()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditEngtitle()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditChineseTitle()
{
	UpdateData(TRUE);
}


void CSubInsert::OnEnChangeEditOwner()
{
	UpdateData(TRUE);
}


//���
void CSubInsert::OnBnClickedButtonInsert()
{
	if (hasOpened)
	{

		//�Д��Ƿ��x���˵؈D���Լ��Ă��؈D
		if (m_ECNU == 0 && m_CHINA == 0)
		{
			MessageBox(_T("Ո�x��һ���؈D��"));	return;
		}
		else if (m_ECNU == 0 && m_CHINA == 1)
		{
			map = "�й�";
			hmap = "null";
			hlocation = "null";
		}
		else
		{
			map = "��ʦ��";
			hmap = "�й�";
			hlocation = "�Ϻ�";
		}

		//�Д��Ƿ���title
		if (m_titleEn == "")
			m_titleEn = key;			//Ĭ�J���ļ��������}

		//�Д��Ƿ���owner
		if (m_owner == "")
			m_owner = "Administrator";	//Ĭ�J�ù���T�����DƬ������

		//�Д����ٵ��c�Ƿ��ڱ���
		if (m_ECNU == 1 && m_CHINA == 0)//�A����
		{
			LocationGraph<200> mapECNU;
			int pos; VertexRecord vr;		//dummy
			string l = (CStringA)m_location;//location

			//���S""�������c���������������@ʾ�c���E
			if (mapECNU.SearchByLocation(l, pos, vr) == notPresent && l != "")
			{
				MessageBox(_T("�ܱ�Ǹ�����c�����ڵ؈D�Y��Ո�鿴ecnuĿ��µ�introduction.txt��"));
				return;
			}
		}
		//else (m_ECNU == 1 && m_CHINA == 0)//�Ї�

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
		MessageBox(_T("����ɹ���"));
		picListptr->print();

		//����Ϣݔ��info
		/*fstream fout;
		fout.open("info.txt", ios::app);
		PictureRecord tmp((string)(CStringA) key, insertone);
		fout << picListptr->size()+1 << "," << tmp;
		fout.close();*/
		picListptr->print();	//printһ��ˢ��

		//�������edit
		m_titleEn = "";
		m_detail = "";
		m_owner = "";
		UpdateData(FALSE); //������ֵ�ĸı���µ����档
		SetDlgItemText(IDC_EDIT_ENGTITLE, m_titleEn);
		SetDlgItemText(IDC_EDIT_CHINESE_TITLE, m_detail);
		SetDlgItemText(IDC_EDIT_OWNER, m_owner);
	}
}


//�؈D����
void CSubInsert::OnBnClickedRadioEcnu()
{
	m_ECNU = 1; m_CHINA = 0;
}


void CSubInsert::OnBnClickedRadioChina()
{
	m_ECNU = 0; m_CHINA = 1;
}

//����ݔ���
//void CSubInsert::OnEnUpdateEditEngtitle()
//{
//	m_titleEn = "";
//}


//void CSubInsert::OnEnUpdateEditChineseTitle()
//{
//	m_detail = "";
//}


//void CSubInsert::OnEnUpdateEditOwner()
//{
//	m_owner = "";
//}
