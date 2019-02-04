// ChoiceButton.cpp : 实现文件
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



// CChoiceButton 消息处理程序




void CChoiceButton::OnBnClicked()
{
	// TODO:  在此添加控件通知处理程序代码
	GetParent()->Invalidate();		//清空按鈕	
}
