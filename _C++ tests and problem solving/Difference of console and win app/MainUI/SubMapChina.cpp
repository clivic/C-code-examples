// SubMapChina.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubMapChina.h"
#include "afxdialogex.h"
#include "SubReview.h"

// CSubMapChina �Ի���

IMPLEMENT_DYNAMIC(CSubMapChina, CDialogEx)

CSubMapChina::CSubMapChina(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubMapChina::IDD, pParent)
{

}

CSubMapChina::CSubMapChina(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
	: CDialogEx(CSubMapChina::IDD, pParent)
{

	picLibraryPtr = ptr;

}

CSubMapChina::~CSubMapChina()
{
}

void CSubMapChina::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubMapChina, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSubMapChina ��Ϣ�������


void CSubMapChina::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�@ʾ�����D
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_CHINA);

	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	//�����㼣��Ϣ    
	int count = chinaMap.get_verterxCount();
	VertexRecord vr; //ͼ�нڵ��¼
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//ͼ�е��Ӧ����Ƭ����
	for (int i = 0; i<count; i++)
	{
		chinaMap.get_trackByIndex(i, vr, trackListPtr);
		if (trackListPtr != NULL&&trackListPtr->size()>0)
		{
			dc.Ellipse(vr.the_x() - 5, vr.the_y() - 5, vr.the_x() + 5, vr.the_y() + 5);//Χ�����ĵ㻭��Բ�Σ�
			dc.SetTextColor(RGB(255, 0, 0));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}
}


BOOL CSubMapChina::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�������˜ʴ_����ͼ�������ʾͼ�Ρ�
	//�õ��D�Č��ߡ�
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_CHINA);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);

	CRect   temprect(0, 0, bitmap.bmWidth, bitmap.bmHeight);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	if (chinaMap.Initialize("�й�", "china") == success)
	{
		MessageBox(_T("OK,Now map is initialized."));
	}
	else
	{
		MessageBox(_T("error,map load failed."));

	}
	//�����㼣
	picLibraryPtr->searchByFootmark(chinaMap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSubMapChina::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int no, index;

	chinaMap.positionToNum(point.x, point.y, index, no);

	VertexRecord vr; //ͼ�нڵ��¼
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//ͼ�е��Ӧ����Ƭ����

	chinaMap.get_trackByIndex(index, vr, trackListPtr);	//�õ���Ƭ����
	CString tmp(vr.the_location().c_str());				

	CString str_x;//X����
	CString str_y;//Y����
	str_x.Format(_T("%d"), point.x);//ת��point.x��str_x
	str_y.Format(_T("%d"), point.y); //ת��point.y��str_y

	tmp = str_x + _T(",") + str_y + _T(",") + tmp;

	//�õ����ֺ�һ���Á�g�[�K�����g�[��ı�
	CString imageNames("");
	const Node<PictureRecord >* cptr;
	PictureInfoList picList;

	for (int i = 0; i<trackListPtr->size(); i++){
		trackListPtr->retrieve(i, cptr);

		//��PictureInfoList
		picList.insert(cptr->entry);	//avoid the passing by reference

		//�õ�����
		CString tmpName(cptr->entry.the_key().c_str());
		imageNames = imageNames + _T(",") + tmpName;
	}
	MessageBox(tmp + imageNames);

	//�����g�[��
	if (!picList.empty())
	{
		CSubReview dlgSurf(NULL, &picList);
		dlgSurf.DoModal(); //���_�ӿ�
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
