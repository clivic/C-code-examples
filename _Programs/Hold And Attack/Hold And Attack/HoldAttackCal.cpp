//*******************************************************************
//Player Class Implementation of the calculation of Hold and Attack AI.
//*******************************************************************
#include "HoldAttackCal.h"

Player::Player()
{
	Clear();
	plName = "Player";
	random.RandomInt(1, 100);// this is dummy£¬ then will be effective
}

Operation Player::Act(const Operation &op)
//	Pre:	op should only be HOLD, DEFENSE, or ATTACK.
//	Post:	Act according to the direction given, like if it is HOLD,
//			then storage is changed according to this deriction. Simutanously,
//			give out a result that "HOLD".
{
	switch (op)
	{
	case HOLD:
		return ActIfHold();	break;
	case DEFENSE:
		return ActIfDef();	break;
	case ATTACK:
		return ActIfAttk();	break;
	default:
		return ERROR_CODE;	break;
	}
}

Operation Player::ActIfHold()
{
	storage.Insert(storage.Size(), HOLD);
	numHold++;
	numDefense = 0;
	return HOLD;
}

Operation Player::ActIfDef()
{
	storage.Insert(storage.Size(), DEFENSE);
	numDefense++;
	return DEFENSE;
}

Operation Player::ActIfAttk()
{
	if (!numHold)
		return ATTACK_FAIL;
	else if (numHold < 0)
		return ERROR_CODE;
	else
	{
		storage.Insert(storage.Size(), ATTACK);
		numHold--;
		numDefense = 0;
		return ATTACK;
	}
}

Operation Player::AI_Decide(const Player &rival, const Personality &pnty)
//	Post:	return the option AI will choose. There'll be no possibility
//			of ATTACK_FAIL, but will be able to be EEROR_CODE which can
//			be induced by resNum being out of range(1--100£©or numHold < 0.
{
	/**	How to decide?
	*	using resNum(1 to 100), and Random() Function,
	*	and a threshold, then we can acquire a decision.
	*/
	int resNum;			// result number according to random()
	int numRivalHold = rival.GetNumHold();
	int thresholdL = 60;	// in default, <= it will "HOLD", else "ATTACK"
	int thresholdH = 100;	// in default, <= it && > thresholdL will ""ATTACK", else "DEFENSE"

	switch (pnty)	// !!currently hard only
	{
	case DEFAULT:
		if (!numRivalHold)	// no holds
		{
			// Won't defend
			thresholdH = 100;
			thresholdL = 60;
			if (!numHold)			// no holds, no chance to attck
				return HOLD;
			else if (numHold > 0 && numHold <= 3)
				thresholdL -= numHold * 5;
			else if (numHold > 3)	// There are too many HOLDs, then tend to attack
				thresholdL = 10;
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold == 1)
		{
			// Will do all three actions
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 50;
			}
			else if (numHold > 0 && numHold <= 3)
			{
				thresholdL = 20;
				thresholdH = 60;
			}
			else if (numHold > 3)	// more holds than rival, tend to attack
			{
				thresholdL = 5;
				thresholdH = 70;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold == 2)
		{
			// Will do all three actions, but not tend to HOLD
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 30;
			}
			else if (numHold > 0 && numHold <= 3) //tend to defense
			{
				thresholdL = 15;
				thresholdH = 45;
			}
			else if (numHold > 3)	// more holds than rival, tend to attack
			{
				thresholdL = 10;
				thresholdH = 75;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold > 2)
		{
			// Will do all three actions, but go into defense state
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 5;
			}
			else if (numHold > 0 && numHold <= 3)	// more tend to defense 
			{
				thresholdL = 15;
				thresholdH = 45;
			}
			else if (numHold > 3)	// same that have many HOLDs, tend to defense
			{
				thresholdL = 10;
				thresholdH = 40;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}
		break;

	case NORMAL:
		if (!numRivalHold)	// no holds
		{
			// Won't defend
			thresholdH = 100;
			if (!numHold)			// no holds, no chance to attck
				return HOLD;
			else if (numHold == 1)
				thresholdL = 50;
			else if (numHold == 2)
				thresholdL = 30;
			else if (numHold >= 3)	// There are too many HOLDs, then tend to attack
				thresholdL = 10;
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold == 1)
		{
			// Will do all three actions
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 50;
			}
			else if (numHold == 1)
			{
				thresholdL = 33;
				thresholdH = 66;
			}
			else if (numHold == 2)
			{
				thresholdL = 20;
				thresholdH = 80;
			}
			else if (numHold >= 3)	// more holds than rival, tend to attack
			{
				thresholdL = 10;
				thresholdH = 90;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold == 2)
		{
			// Will do all three actions, but not tend to HOLD
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 30;
			}
			else if (numHold == 1) //tend to defense
			{
				thresholdL = 20;
				thresholdH = 40;
			}
			else if (numHold == 2)
			{
				thresholdL = 15;
				thresholdH = 57;
			}
			else if (numHold >= 3)	// more holds than rival, tend to attack
			{
				thresholdL = 10;
				thresholdH = 70;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}

		else if (numRivalHold > 2)
		{
			// Will do all three actions, but go into defense state
			if (!numHold)			// no holds, defend or hold
			{
				thresholdH = thresholdL = 10;
			}
			else if (numHold == 1)	// more tend to defense 
			{
				thresholdL = 10;
				thresholdH = 20;
			}
			else if (numHold == 2)
			{
				thresholdL = 10;
				thresholdH = 40;
			}
			else if (numHold >= 3)	// same that have many HOLDs, tend to defense
			{
				thresholdL = 10;
				thresholdH = 60;
			}
			else					// numHold < 0
				return ERROR_CODE;
		}
		break;
	}

	resNum = random.RandomInt(1, 100);						// effective	

	// check if has 5 DEFENSEs in a row
	if (numDefense >= 5)									// can't continue to defend
	{
		thresholdL += (100 - thresholdH) / 2;
		thresholdH = 100;
	}
	else if (numDefense<0)									// ERROR_CODE happens
	{
		return ERROR_CODE;
	}

	if (resNum > 0 && resNum <= thresholdL)					// hold
		return HOLD;
	else if (resNum > thresholdL && resNum <= thresholdH)	// attack
		return ATTACK;
	else if (resNum > thresholdH && resNum <= 100)			// defend
		return DEFENSE;
	else													// error
		return ERROR_CODE;
}

int Player::GetNumHold() const
{
	return numHold;
}

int Player::GetNumDefense() const
{
	return numDefense;
}

void Player::Clear()
{
	storage.Clear();
	numHold = 0;
	numDefense = 0;
}

void Player::Traverse(void(*visit)(Operation &op))
//	Post:	The action specified by function(*visit) has been performed on every entry of
//			the Players list, beginning at position 0 and doing each in turn. 
{
	storage.Traverse(visit);
}

void Player::SetPlName(const string &str)
{
	plName = str;
}

string Player::GetPlName()
{
	return plName;
}