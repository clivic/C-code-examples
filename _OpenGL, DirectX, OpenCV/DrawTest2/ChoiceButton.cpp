// ChoiceButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawTest2.h"
#include "ChoiceButton.h"


// CChoiceButton

IMPLEMENT_DYNAMIC(CChoiceButton, CButton)

CChoiceButton::CChoiceButton()
{
	m_func = LINE;
}

CChoiceButton::CChoiceButton(const WayToDraw &way)
{
	m_func = way;
}

CChoiceButton::~CChoiceButton()
{
}


BEGIN_MESSAGE_MAP(CChoiceButton, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &CChoiceButton::OnBnClicked)
END_MESSAGE_MAP()



// CChoiceButton ��Ϣ�������




void CChoiceButton::OnBnClicked()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetParent()->Invalidate();		//��հ��o	
}
