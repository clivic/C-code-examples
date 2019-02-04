
// DrawingTestDoc.cpp : CDrawingTestDoc e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
#ifndef SHARED_HANDLERS
#include "DrawingTest.h"
#endif

#include "DrawingTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawingTestDoc

IMPLEMENT_DYNCREATE(CDrawingTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawingTestDoc, CDocument)
END_MESSAGE_MAP()


// CDrawingTestDoc ����/�☋

CDrawingTestDoc::CDrawingTestDoc()
{
	// TODO:  �ڴ˼���һ�ν�����ʽ�a

}

CDrawingTestDoc::~CDrawingTestDoc()
{
}

BOOL CDrawingTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ˼������³�ʼ����ʽ�a
	// (SDI �ļ������ô��ļ�)

	return TRUE;
}




// CDrawingTestDoc ���л�

void CDrawingTestDoc::Serialize(CArchive& ar)
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
void CDrawingTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CDrawingTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// �O�������ļ��Y�ϵ��ь����ݡ�
	// ���ݲ��֑�ԓ�� ";" ���_

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawingTestDoc::SetSearchContent(const CString& value)
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

// CDrawingTestDoc �\��

#ifdef _DEBUG
void CDrawingTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawingTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawingTestDoc ����
