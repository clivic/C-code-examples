// SubMapECNU.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MainUI.h"
#include "SubMapECNU.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include "SubReview.h"


// CSubMapECNU �Ի���

IMPLEMENT_DYNAMIC(CSubMapECNU, CDialogEx)

CSubMapECNU::CSubMapECNU(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubMapECNU::IDD, pParent)
{

	EnableAutomation();

}

CSubMapECNU::CSubMapECNU(CWnd* pParent /*=NULL*/,
	PictureInfoList *pLPtr)
: CDialogEx(CSubMapECNU::IDD, pParent)
{

	EnableAutomation();
	picLibraryPtr = pLPtr;

}

CSubMapECNU::~CSubMapECNU()
{
}

void CSubMapECNU::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ������������
	// ��������ĸ����������롣

	CDialogEx::OnFinalRelease();
}

void CSubMapECNU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubMapECNU, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSubMapECNU, CDialogEx)
END_DISPATCH_MAP()

// ע��: �������� IID_ISubMapECNU ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {AD9EC178-95AC-4A49-B1F2-15DD03905F22}
static const IID IID_ISubMapECNU =
{ 0xAD9EC178, 0x95AC, 0x4A49, { 0xB1, 0xF2, 0x15, 0xDD, 0x3, 0x90, 0x5F, 0x22 } };

BEGIN_INTERFACE_MAP(CSubMapECNU, CDialogEx)
	INTERFACE_PART(CSubMapECNU, IID_ISubMapECNU, Dispatch)
END_INTERFACE_MAP()


// CSubMapECNU ��Ϣ��������


void CSubMapECNU::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴�������Ϣ�����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	//�@ʾ�����D
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_ECNU);

	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	//�����㼣��Ϣ    
	int count = ecnuMap.get_verterxCount();
	VertexRecord vr; //ͼ�нڵ��¼
	const List <const Node<PictureRecord >  *>* trackListPtr = NULL;//ͼ�е��Ӧ����Ƭ����
	for (int i = 0; i<count; i++)
	{
		ecnuMap.get_trackByIndex(i, vr, trackListPtr);
		if (trackListPtr != NULL&&trackListPtr->size()>0)
		{
			CBrush * pBrushOld;//��ˢ
			CBrush brushTmp;
			brushTmp.CreateSolidBrush(RGB(255, 223, 0));//RGB(�죬�̣���)
			pBrushOld = dc.SelectObject(&brushTmp);

			dc.Ellipse(vr.the_x() - 9, vr.the_y() - 9, vr.the_x() + 9, vr.the_y() + 9);//Χ�����ĵ㻭��Բ�Σ�
			dc.SetTextColor(RGB(255, 0, 0));

			CString tmp;
			tmp.Format(_T("%d"), trackListPtr->size());
			dc.TextOut(vr.the_x() - 8, vr.the_y(), tmp);
		}
	}


}


BOOL CSubMapECNU::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	//�������˜ʴ_����ͼ�������ʾͼ�Ρ�
	CRect   temprect(0, 0, 877, 740);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	if (ecnuMap.Initialize("��ʦ��", "ecnu") == success)
	{
		MessageBox(_T("OK,Now map is initialized."));
	}
	else
	{
		MessageBox(_T("error,map load failed."));

	}
	//�����㼣
	picLibraryPtr->searchByFootmark(ecnuMap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CSubMapECNU::OnLButtonDown(UINT nFlags, CPoint point)
//�I�P���c��һ���c
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialogEx::OnLButtonDown(nFlags, point);

	int no, index;

	ecnuMap.positionToNum(point.x, point.y, index, no);

	VertexRecord vr; //ͼ�нڵ��¼
	const List <const Node<PictureRecord >  *>*     trackListPtr = NULL;//ͼ�е��Ӧ����Ƭ����

	ecnuMap.get_trackByIndex(index, vr, trackListPtr);
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

	for (int i = 0; i < trackListPtr->size(); i++)
	{
		trackListPtr->retrieve(i, cptr);
		//����PictureInfoList
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
	CDialog::OnLButtonDown(nFlags, point);

}