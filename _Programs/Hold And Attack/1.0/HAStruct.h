//*******************************************************************
//	This is the class to drive the H&A game.
//	It defines the structure of the H&A game.
// Author: Clivic
//*******************************************************************
#ifndef HASTRUCT
#define HASTRUCT
#include "HoldAttackCal.h"

enum Mode{ PVP, PVE };
enum Language{ ENG, CNT, CNS };

class HAstruct
{
public:
	HAstruct();
	void Initialize();
	void SetMode(const Mode &m);
	void SetDifyAI(const Difficulty &d);
	void SetLang(const Language &l);
	Language GetLang();
	void Fight();			// Thread the whole operations
	
protected:
	// data members
	Player left;			// Player 1, in PVE, it represents the person
	Player right;			// Player 2, in PVE, it represents the computer
	Mode mode = PVE;
	Difficulty difyAI = HARD;
	Language lang = ENG;		// default language

	//protected tool function
	void PrintRevPCmd(Player &p);
	Operation P_InputCmd();
	Operation E_Decide();	// used in PVE mode
	bool JudgeCmd(Operation rp, Operation lp);
	void ErrorDetecterCmd(Operation &op, Player &player);// Deal with ATTACK_FAIL, ERROR_CODE and INPUT_FAIL
	void AnnounceWinnerCmd(const LPSTR &str);
	void PrintRevCmd();
};


void PrintPlayerEng(Operation &op);
void PrintPlayerCnt(Operation &op);
void PrintPlayerCns(Operation &op);
void PrintEndCmd();


#endif