// CSubDel.cpp : 实现文件
//

#include "stdafx.h"
#include "Picture Manager.h"
#include "SubDel.h"
#include "afxdialogex.h"
#include "PdfJpeg.h"
#include "Node.h"				//Error_code


// CSubDel 对话框

IMPLEMENT_DYNAMIC(CSubDel, CDialogEx)

CSubDel::CSubDel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubDel::IDD, pParent)
{

}

CSubDel::CSubDel(CWnd* pParent /*=NULL*/,
	PictureInfoList *ptr)
: CDialogEx(CSubDel::IDD, pParent)
{
	picListptr = ptr;
	hasOpened = false;	//初始值，不刷圖，打開之后再也不能是false
	num = -1;			//初始化時的非法值,不能進行打開圖片
}

CSubDel::~CSubDel()
{
}

void CSubDel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC, m_pic);
}


BEGIN_MESSAGE_MAP(CSubDel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CSubDel::OnBnClickedButtonOpen)
	ON_WM_PAINT()
	ON_STN_CLICKED(IDC_STATIC_PIC, &CSubDel::OnStnClickedStaticPic)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CSubDel::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// CSubDel 消息处理程序


void CSubDel::OnBnClickedButtonOpen()
{
	//设置过滤器 
	TCHAR szFilter[] = _T("JPEG文件(*.jpg)|*.jpg|所有文件(*.*)|*.*||");
	//构造贷款文件对话框
	CFileDialog fileDlg(true, _T("*.jpg"), NULL, 0, szFilter, this);

	CString strFilePath;
	//显示文件对话框
	if (IDOK == fileDlg.DoModal())
	{
		//如果点击了文件对话框的“打开”按钮，则将选则的文件路径显示在编辑框
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_PATH, strFilePath);  //显示值到编辑框

		SetDlgItemText(IDC_EDIT_NAME, fileDlg.GetFileName());


		string fileName = (CStringA)strFilePath;
		char tmpname[100];
		strcpy_s(tmpname, fileName.c_str());
		PdfJpeg jepg(tmpname);//打开文件，以获取文件大小和尺寸信息
		int readResult = jepg.ReadImage();

		if (readResult == -1)
		{
			MessageBox(_T("Error in read file: "));
			return;
		}
		
		//查詢是否存在,並倒入
		PictureRecord temp;
		bool found = false;
		for (int i = 0; i < picListptr->size(); i++)
		{
			picListptr->retrieve(i, temp);
			if (temp.the_key().c_str() == fileDlg.GetFileName())
			{
				found = true;	num = i;
				info = temp;	break;
			}
		}
		if (found == false)
		{
			MessageBox(_T("抱歉，所需刪除之圖片不在圖片庫裏。"));
			num = -1;	//沒找到,設為非法值
			return;		//不改值，還是原來的樣子
		}

		hasOpened = true;

		//先存儲部分信息
		int width = jepg.GetWidth();
		int height = jepg.GetHeight();
		int size = int((jepg.GetDataLength()) / 1024.0 + 1); //上取整数

		SetDlgItemInt(IDC_EDIT_HEIGHT, height);
		SetDlgItemInt(IDC_EDIT_WIDTH, width);
		SetDlgItemInt(IDC_EDIT_SIZE, size);

		InvalidateRect(CRect(100, 100, 500, 400), true);//强制刷新
	}
}



void CSubDel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	if (hasOpened)
		DrawPicture(&m_pic);
}


void CSubDel::DrawPicture(CStatic *m_Pic/*控件名稱*/)
{
	CRect rectPic;
	(*m_Pic).GetClientRect(&rectPic);   //m_picture为Picture Control控件变量，获得控件的区域对象
	CDC *pDC = m_Pic->GetWindowDC();    //获得显示控件的DC

	CImage *pImage = new CImage();		//装载图像的类

	CString basePath;
	basePath = "d:\\picLibrary\\";
	pImage->Load(basePath+info.the_key().c_str());	//从磁盘装载图片,根据页面计算得到的图片下标
	int width = rectPic.Width();			//显示区域的宽和高
	int height = rectPic.Height();

	int picW = pImage->GetWidth();	//图片的宽和高
	int picH = pImage->GetHeight();

	//防止缩放后图片失真
	SetStretchBltMode(pDC->m_hDC, HALFTONE);
	SetBrushOrgEx(pDC->m_hDC, 0, 0, NULL);
	pImage->StretchBlt(pDC->m_hDC, 0, 0, width, height);

	//显示图片
	//pImage->Draw(pDC->m_hDC, 5, 5, width - 5, height - 5);
	pImage->Draw(pDC->m_hDC, 0, 0, width, height);

	ReleaseDC(pDC);
	delete pImage;
}


void CSubDel::OnStnClickedStaticPic()
{
	if (hasOpened)
	{
		if (num >= 0)
		{
			CSubGetOnePic getOnePic(NULL, picListptr, num);
			getOnePic.DoModal();
		}
	}
}


void CSubDel::OnBnClickedButtonDel()
{
	// TODO:  在此添加控件通知处理程序代码
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
			picListptr->print();	//刷新數據
			DeleteFileInDirectory(basePath + filename);	//刪除對應文件
			MessageBox(_T("成功刪除圖片" + filename));

			//清空三個edit
			UpdateData(FALSE); //将变量值的改变更新到界面。
			SetDlgItemInt(IDC_EDIT_HEIGHT, 0);
			SetDlgItemInt(IDC_EDIT_WIDTH, 0);
			SetDlgItemInt(IDC_EDIT_SIZE, 0);
		}
	}
}


//用來刪除文件
void DeleteFileInDirectory(CString strDir)
{
	CFileFind ff;

	BOOL bFound = ff.FindFile(strDir,0);

	while (bFound)
	{
		bFound = ff.FindNextFile();
		if (ff.GetFileName() == _T(".") || ff.GetFileName() == _T(".."))
			continue;
		//去掉文件(夹)只读等属性  
		SetFileAttributes(ff.GetFilePath(), FILE_ATTRIBUTE_NORMAL); 
		if (!ff.IsDirectory())	//不是文件夾是文件
		{
			DeleteFile(ff.GetFilePath());   //删除文件  
		}
	}
	ff.Close();
}