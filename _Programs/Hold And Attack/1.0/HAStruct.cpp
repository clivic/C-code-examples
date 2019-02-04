//*******************************************************************
//HAstruct Class Implementation of the structure of the H&A game.
//*******************************************************************
#include "HAStruct.h"

HAstruct::HAstruct()
{
	Initialize();
	mode = PVE;
	difyAI = HARD;
}

void HAstruct::Initialize()
{
	left.Clear();	
	right.Clear();	
	if (mode == PVE)
	{
		// retrive system username as player's name
		LPSTR username = "Player";
		//GetUserNameA(username, nullptr);
		left.SetPlName(username);

		right.SetPlName("Computer");
	}
	else
	{
		left.SetPlName("Player1"); 
		right.SetPlName("Player2");
	}

}

void HAstruct::PrintRevCmd()
{
	switch (lang)
	{
	case ENG:
		cout << endl << "Review battle:" << endl;
		break;
	case CNT:
		cout << endl << "×÷‘ð»Øî™:" << endl;
		break;
	case CNS:
		cout << endl << "Õ½³¡»Ø·Å:" << endl;
		break;
	default:
		break;
	}
	cout << left.GetPlName() << ":\t\t" << flush;
	PrintRevPCmd(left);
	cout << right.GetPlName()<< ":\t" << flush;
	PrintRevPCmd(right);
}

void HAstruct::PrintRevPCmd(Player &p)
//	post:	directly print one line of the whole fight of one player
{
	switch (lang)
	{
	case ENG:
		p.Traverse(PrintPlayerEng);	break;
	case CNT:
		p.Traverse(PrintPlayerCnt);	break;
	case CNS:
		p.Traverse(PrintPlayerCns);	break;
	default:
		break;
	}
	PrintEndCmd();
}

void PrintPlayerEng(Operation &op)
{
	switch (op)
	{
	case HOLD:
		cout << "H ";	break;
	case DEFENSE:
		cout << "D ";	break;
	case ATTACK:
		cout << "A ";	break;
	}
}

void PrintPlayerCnt(Operation &op)
{
	switch (op)
	{
	case HOLD:
		cout << "ÆÁ ";	break;
	case DEFENSE:
		cout << "çM ";	break;
	case ATTACK:
		cout << "²¨ ";	break;
	}
}

void PrintPlayerCns(Operation &op)
{
	switch (op)
	{
	case HOLD:
		cout << "ÆÁ ";	break;
	case DEFENSE:
		cout << "ïÛ ";	break;
	case ATTACK:
		cout << "²¨ ";	break;
	}
}

void PrintEndCmd()
{
	cout << endl;
}

void HAstruct::SetMode(const Mode &m)
{
	mode = m;
}

void HAstruct::SetDifyAI(const Difficulty &d)
{
	difyAI = d;
}

void HAstruct::SetLang(const Language &l)
{
	lang = l;
}

Language HAstruct::GetLang()
{
	return lang;
}

Operation HAstruct::P_InputCmd()
{
	char opInput;
	bool ifNoHOLDs = false;		// whether the player hasn't HOLDs
	bool ifCantDef = false;		// whether the player has 5 DEFENSEs in a row

	switch (lang)
	{
	case ENG:
		cout << "Please enter your choice";	// j Hold, l Attack, k Defend
		break;
	case CNT:
		cout << "ÕˆæIÈëÄãµÄßx“ñ";	// j Hold, l Attack, k Defend
		break;
	case CNS:
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ";	// j Hold, l Attack, k Defend
		break;
	default:
		break;
	}

	// judge if player have HOLDs to ATTACK
	if (!left.GetNumHold())		// no HOLDs
		ifNoHOLDs = true;
	else
		ifNoHOLDs = false;

	// judge if player can't continue to DEFENSE
	if (left.GetNumDefense() >= 5)	// has defended 5 times in a row
		ifCantDef = true;
	else
		ifCantDef = false;

	// input
	if (ifNoHOLDs && !ifCantDef)
	{
		switch (lang)
		{
		case ENG:
			cout << "([J]-Hold, [K]-Defend): " << flush;	break;
		case CNT:
			cout << "([J]-ÆÁ, [K]-çM): " << flush;	break;
		case CNS:
			cout << "([J]-ÆÁ, [K]-ïÛ): " << flush;	break;
		default:
			break;
		}

		do
		{
			Cin(opInput);
		} while (opInput != 'j' && opInput != 'k');
	}
	else if (!ifNoHOLDs && !ifCantDef)
	{
		switch (lang)
		{
		case ENG:
			cout << "([J]-Hold, [K]-Defend, [L]-Attack): " << flush;	break;
		case CNT:
			cout << "([J]-ÆÁ, [K]-çM, [L]-²¨): " << flush;	break;
		case CNS:
			cout << "([J]-ÆÁ, [K]-ïÛ, [L]-²¨): " << flush;	break;
		default:
			break;
		}

		do
		{
			Cin(opInput);
		} while (opInput != 'j' && opInput != 'k' && opInput != 'l');
	}
	else if (ifNoHOLDs && ifCantDef)
	{
		switch (lang)
		{
		case ENG:
			cout << "([J]-Hold): " << flush;	break;
		case CNT:
			cout << "([J]-ÆÁ): " << flush;	break;
		case CNS:
			cout << "([J]-ÆÁ): " << flush;	break;
		default:
			break;
		}

		do
		{
			Cin(opInput);
		} while (opInput != 'j');
	}
	else
	{
		switch (lang)
		{
		case ENG:
			cout << "([J]-Hold, [L]-Attack): " << flush;	break;
		case CNT:
			cout << "([J]-ÆÁ, [L]-²¨): " << flush;	break;
		case CNS:
			cout << "([J]-ÆÁ, [L]-²¨): " << flush;	break;
		default:
			break;
		}

		do
		{
			Cin(opInput);
		} while (opInput != 'j' && opInput != 'l');
	}// input finished

	// pass the choice to Judge() (return the choice)
	switch (opInput)
	{
	case 'j':
		return HOLD;
		break;

	case 'k':
		return DEFENSE;
		break;

	case 'l':
		return ATTACK;
		break;

	default:	// other improper input
		return INPUT_FAIL;
		break;
	}

}

Operation HAstruct::E_Decide()
{
	// pass the choice to Judge() (return the choice)
	return right.AI_Decide(left, difyAI);
	
}

void HAstruct::ErrorDetecterCmd(Operation &op, Player &player)
//	Post:	detect error and output them
{
	switch (op)
	{
	case ATTACK_FAIL:
		// force to hold
		// this should not happen in game in general, thus no translation
		cout << "No HOLDs, change ATTACK to HOLD." << endl;
		player.Act(HOLD);
		op = HOLD;
		break;

	case ERROR_CODE:
		// output ERROR INFO and abort the program
		// !!this should not be possible to happen in game instead of debugging!!
		cout << "Error detected during the calculation, game aborted." << endl;
		exit(-1);
		break;

	case INPUT_FAIL:
		// output ERROR INFO and abort the program
		// !!this should not be possible to happen in game instead of debugging!!
		cout << "invalid input, game aborted." << endl;
		exit(-1);
		break;

	default:		// not Error Operation
		return;
	}
}

bool HAstruct::JudgeCmd(Operation rp, Operation lp)
//	Pre:	if PVE, the first parameter should be the computer!
//			if ATTACK_FAIL, ATTACK hasn't be added into the list.
//	Post:	Receive the choices of two players through parameters, 
//			output the choices and judge if there is winner.
{
	// detect error
	ErrorDetecterCmd(rp, right);
	ErrorDetecterCmd(lp, left);

	// now rp, lp should only be HOLD, DEFENSE or ATTACK
	// output results
	
	cout << left.GetPlName() << ":\t\t ";
	switch (lp)
	{
	case HOLD:
		switch (lang)
		{
		case ENG:
			cout << "Hold!" << endl;	break;
		case CNT:
			cout << "ÆÁ!" << endl;	break;
		case CNS:
			cout << "ÆÁ!" << endl;	break;
		default:
			break;
		}
		break;

	case DEFENSE:
		switch (lang)
		{
		case ENG:
			cout << "Defend!" << endl;	break;
		case CNT:
			cout << "çM!" << endl;	break;
		case CNS:
			cout << "ïÛ!" << endl;	break;
		default:
			break;
		}
		break;

	case ATTACK:
		switch (lang)
		{
		case ENG:
			cout << "Attack!" << endl;	break;
		case CNT:
			cout << "²¨!" << endl;	break;
		case CNS:
			cout << "²¨!" << endl;	break;
		default:
			break;
		}
		break;
	}
	left.Act(lp);

	cout << right.GetPlName() << ":\t ";
	switch (rp)
	{
	case HOLD:
		switch (lang)
		{
		case ENG:
			cout << "Hold!" << endl;	break;
		case CNT:
			cout << "ÆÁ!" << endl;	break;
		case CNS:
			cout << "ÆÁ!" << endl;	break;
		default:
			break;
		}
		break;

	case DEFENSE:
		switch (lang)
		{
		case ENG:
			cout << "Defend!" << endl;	break;
		case CNT:
			cout << "çM!" << endl;	break;
		case CNS:
			cout << "ïÛ!" << endl;	break;
		default:
			break;
		}
		break;

	case ATTACK:
		switch (lang)
		{
		case ENG:
			cout << "Attack!" << endl;	break;
		case CNT:
			cout << "²¨!" << endl;	break;
		case CNS:
			cout << "²¨!" << endl;	break;
		default:
			break;
		}
		break;
	}
	right.Act(rp);

	// decide whether their are winner
	if (lp == HOLD && rp == ATTACK)
	{
		AnnounceWinnerCmd(right.GetPlName());
		return false;	// exit the loop in Fight()
	}
	else if (rp == HOLD && lp == ATTACK)
	{
		AnnounceWinnerCmd(left.GetPlName());
		return false;	// exit the loop in Fight()
	}
	else
		return true;	// continue the rounds

}

void HAstruct::AnnounceWinnerCmd(const LPSTR &str)
{
	switch (lang)
	{
	case ENG:
		cout << str << " wins!" << endl;	break;
	case CNT:
		cout << str << " «@µÃ„ÙÀû!" << endl;	break;
	case CNS:
		cout << str << " »ñÊ¤!" << endl;	break;
	default:
		break;
	}
}

void HAstruct::Fight()
{
	Initialize();
	if (mode == PVE)
	{
		while (JudgeCmd(E_Decide(), P_InputCmd()));
	}
	else
	{
		while (JudgeCmd(P_InputCmd(), P_InputCmd()));
	}
	PrintRevCmd();
}
