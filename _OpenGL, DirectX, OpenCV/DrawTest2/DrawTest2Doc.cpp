
// DrawTest2Doc.cpp : CDrawTest2Doc e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
#ifndef SHARED_HANDLERS
#include "DrawTest2.h"
#endif

#include "DrawTest2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawTest2Doc

IMPLEMENT_DYNCREATE(CDrawTest2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDrawTest2Doc, CDocument)
END_MESSAGE_MAP()


// CDrawTest2Doc ����/�☋

CDrawTest2Doc::CDrawTest2Doc()
{
	// TODO:  �ڴ˼���һ�ν�����ʽ�a

}

CDrawTest2Doc::~CDrawTest2Doc()
{
}

BOOL CDrawTest2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ˼������³�ʼ����ʽ�a
	// (SDI �ļ������ô��ļ�)

	return TRUE;
}




// CDrawTest2Doc ���л�

void CDrawTest2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ˼��냦���ʽ�a
	}
	else
	{
		// TODO:  �ڴ˼����d���ʽ�a
	}
}

#ifdef SHARED_HANDLERS

// �s�D��֧Ԯ
void CDrawTest2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸��@�γ�ʽ�a���L�u�ļ����Y��
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �ь�̎��ʽ��֧Ԯ
void CDrawTest2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �O�������ļ��Y�ϵ��ь����ݡ�
	// ���ݲ��֑�ԓ�� ";" ���_

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawTest2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawTest2Doc �\��

#ifdef _DEBUG
void CDrawTest2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawTest2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawTest2Doc ����
