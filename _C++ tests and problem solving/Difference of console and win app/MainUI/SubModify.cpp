// SubModify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubModify.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"


// CSubModify �Ի���

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


// CSubModify ��Ϣ�������


void CSubModify::OnBnClickedButtonOpenfile()
{
	//���ù�����
	TCHAR szFilter[] = _T("JPEG�ļ�(*.jpg)|*.jpg|�����ļ�(*.*)|*.*||");
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);
	//true ��ʾ���_һ���ļ����^�Vjpg��thisָ�ļ��򸸴���

	CString strFilePath;

	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();					//�@ȡ�x����ęn·��
		SetDlgItemText(IDC_EDIT_PATH, strFilePath);		//������ʾ���ı���

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

		//��ԃ�Ƿ����,�K����
		PictureRecord temp;
		bool found = false;
		for (int i = 0; i < picListptr->size(); i++)
		{
			picListptr->retrieve(i, temp);
			if (temp.the_key().c_str() == fileDlg.GetFileName())
			{
				found = true;

				//����
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
			MessageBox(_T("��Ǹ�������޸�֮�DƬ���ڈDƬ���Y��"));
			return;		//����ֵ��߀��ԭ��Ę���
		}

		//�ȴ惦������Ϣ
		width = jepg.GetWidth();
		height = jepg.GetHeight();
		size = int((jepg.GetDataLength()) / 1024.0 + 1); //��ȡ����
		key = fileDlg.GetFileName();

		ShowDefault();
	}
}

	//����
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

	//��ֵ��
	void CSubModify::SetDefault()
	{
		m_detail = "";
		m_titleEn = "";
		m_location = "";
		m_owner = "";
	}

	//show���ؼ��Y
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

		if (picListptr->replace(item) == success)
		{
			MessageBox(TEXT("�ɹ��޸ĈDƬ" + key));
			picListptr->print();	//�����޸�
		}
		else
			MessageBox(TEXT("��Ǹ���޸ĈDƬʧ����"));
	}


	void CSubModify::OnBnClickedRadioEcnu()
	{
		m_ECNU = 1; m_CHINA = 0;
	}


	void CSubModify::OnBnClickedRadioChina()
	{
		m_ECNU = 0; m_CHINA = 1;
	}
