
// DrawingTestDoc.h : CDrawingTestDoc e�Ľ���
//


#pragma once


class CDrawingTestDoc : public CDocument
{
protected: // �H�����л�����
	CDrawingTestDoc();
	DECLARE_DYNCREATE(CDrawingTestDoc)

// ����
public:

// ���I
public:

// ����
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ��ʽ�a����
public:
	virtual ~CDrawingTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �a����ӍϢ������ʽ
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ���ь�̎��ʽ�O���ь����ݵ� Helper ��ʽ
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
