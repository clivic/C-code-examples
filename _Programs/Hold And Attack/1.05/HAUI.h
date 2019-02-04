//*******************************************************************
//	This is the class to provide the UI for the H&A game. (CMD)
// Author: Clivic
//*******************************************************************
#ifndef HAUSERI
#define HAUSERI
#include "HAStruct.h"

class HAUI
{
public:
	void UIDisplay();
	void Introduction();
	void Instruction();
	void SetLanguage();
	Language GetLanguage();
	void ChangeMode();
	void SetDify();
	void Fight();
	void Quit();

protected:
	// language function
	void IntroductionEng();
	void InstructionEng();
	void IntroductionCnt();
	void InstructionCnt();
	void IntroductionCns();
	void InstructionCns();
	void SetLangPrompt();
	void ChangeModePrompt();
	void SetDifyPrompt();

	// I/O controll
	char GetI(char op1, char op2, char op3, char op4);
	bool DoI_ModeChange(char input);
	bool DoI_LangChange(char input);
	bool DoI_DifyChange(char input);

	// data member
	HAstruct haGame;
};


#endif