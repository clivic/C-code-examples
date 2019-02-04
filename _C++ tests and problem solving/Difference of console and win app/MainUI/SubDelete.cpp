// CSubDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubDelete.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"
#include "Node.h"				//Error_code


// CSubDelete �Ի���

IMPLEMENT_DYNAMIC(CSubDelete, CDialogEx)

CSubDelete::CSubDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubDelete::IDD, pParent)
{

}

CSubDelete::CSubDelete(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubDelete::IDD, pParent)
{
	picListptr = ptr;
	hasOpened = false;	//��ʼֵ����ˢ�D�����_֮����Ҳ������false
}

CSubDelete::~CSubDelete()
{
}

void CSubDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC, m_pic);
}


BEGIN_MESSAGE_MAP(CSubDelete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CSubDelete::OnBnClickedButtonOpen)
	ON_WM_PAINT()
	ON_STN_CLICKED(IDC_STATIC_PIC, &CSubDelete::OnStnClickedStaticPic)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CSubDelete::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// CSubDelete ��Ϣ�������


void CSubDelete::OnBnClickedButtonOpen()
{
	//���ù����� 
	TCHAR szFilter[] = _T("JPEG�ļ�(*.jpg)|*.jpg|�����ļ�(*.*)|*.*||");
	//��������ļ��Ի���
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);

	CString strFilePath;
	//��ʾ�ļ��Ի���
	if (IDOK == fileDlg.DoModal())
	{
		//���������ļ��Ի���ġ��򿪡���ť����ѡ����ļ�·����ʾ�ڱ༭��
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_PATH, strFilePath);  //��ʾֵ���༭��

		SetDlgItemText(IDC_EDIT_NAME, fileDlg.GetFileName());


		string fileName = (CStringA)strFilePath;
		char tmpname[100];
		strcpy_s(tmpname, fileName.c_str());
		PdfJpeg jepg(tmpname);//���ļ����Ի�ȡ�ļ���С�ͳߴ���Ϣ
		int readResult = jepg.ReadImage();

		if (readResult == -1)
		{
			MessageBox(_T("Error in read file: "));
			return;
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
				info = temp;	break;
			}
		}
		if (found == false)
		{
			MessageBox(_T("��Ǹ������h��֮�DƬ���ڈDƬ���Y��"));
			return;		//����ֵ��߀��ԭ��Ę���
		}

		hasOpened = true;

		//�ȴ惦������Ϣ
		int width = jepg.GetWidth();
		int height = jepg.GetHeight();
		int size = int((jepg.GetDataLength()) / 1024.0 + 1); //��ȡ����

		SetDlgItemInt(IDC_EDIT_HEIGHT, height);
		SetDlgItemInt(IDC_EDIT_WIDTH, width);
		SetDlgItemInt(IDC_EDIT_SIZE, size);

		InvalidateRect(CRect(100, 100, 500, 400), true);//ǿ��ˢ��
	}
}



void CSubDelete::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	if (hasOpened)
		DrawPicture(&m_pic);
}


void CSubDelete::DrawPicture(CStatic *m_Pic/*�ؼ����Q*/)
{
	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);   //m_pictureΪPicture Control�ؼ���������ÿؼ����������
	CDC *pDC = m_Pic->GetWindowDC();    //�����ʾ�ؼ���DC

	CImage *pImage = new CImage();		//װ��ͼ�����

	CString basePath;
	basePath = "d:\\picLibrary\\";
	pImage->Load(basePath+info.the_key().c_str());	//�Ӵ���װ��ͼƬ,����ҳ�����õ���ͼƬ�±�
	int width = rectPic.Width();			//��ʾ����Ŀ�͸�
	int height = rectPic.Height();

	int picW = pImage->GetWidth();	//ͼƬ�Ŀ�͸�
	int picH = pImage->GetHeight();

	//��ֹ���ź�ͼƬʧ��
	SetStretchBltMode(pDC->m_hDC, HALFTONE);
	SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
	pImage->StretchBlt(pDC->m_hDC, 0, 0, width, height);

	//��ʾͼƬ
	//pImage->Draw(pDC->m_hDC, 5, 5, width - 5, height - 5);
	pImage->Draw(pDC->m_hDC, 0, 0, width, height);

	ReleaseDC(pDC);
	delete pImage;
}


void CSubDelete::OnStnClickedStaticPic()
{
	if (hasOpened)
	{
		CSubGetOnePic getOnePic(NULL, &info);
		getOnePic.DoModal();
	}
}


void CSubDelete::OnBnClickedButtonDel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (hasOpened)
	{
		if (picListptr->remove(info) == notPresent)
		{
			MessageBox(_T("Sorry, remove failed."));
		}
		else
		{
			CString basePath;
			basePath = "d:\\picLibrary\\";
			CString filename;
			filename = info.the_key().c_str();
			picListptr->print();	//ˢ����
			DeleteFileInDirectory(basePath + filename);	//�h�������ļ�
			MessageBox(_T("�ɹ��h���DƬ" + filename));

			//�������edit
			UpdateData(FALSE); //������ֵ�ĸı���µ����档
			SetDlgItemInt(IDC_EDIT_HEIGHT, 0);
			SetDlgItemInt(IDC_EDIT_WIDTH, 0);
			SetDlgItemInt(IDC_EDIT_SIZE, 0);
		}
	}
}


//�Á�h���ļ�
void DeleteFileInDirectory(CString strDir)
{
	CFileFind ff;

	BOOL bFound = ff.FindFile(strDir,0);

	while (bFound)
	{
		bFound = ff.FindNextFile();
		if (ff.GetFileName() == _T(".") || ff.GetFileName() == _T(".."))
			continue;
		//ȥ���ļ�(��)ֻ��������  
		SetFileAttributes(ff.GetFilePath(), FILE_ATTRIBUTE_NORMAL); 
		if (!ff.IsDirectory())	//�����ļ��A���ļ�
		{
			DeleteFile(ff.GetFilePath());   //ɾ���ļ�  
		}
	}
	ff.Close();
}