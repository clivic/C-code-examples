#pragma once


// CChoiceButton

enum WayToDraw { LINE, ELLIPSE, RECTANGLE};

class CChoiceButton : public CButton
{
	DECLARE_DYNAMIC(CChoiceButton)

public:
	CChoiceButton();
	CChoiceButton(const WayToDraw &way);
	virtual ~CChoiceButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked();

protected:
	WayToDraw m_func;
};


