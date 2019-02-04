//*******************************************************************
// This is the class of the calculation of Hold and Attack AI.
// Author: Clivic
//*******************************************************************
#ifndef HnACAL
#define HnACAL

#include "Random.h"
#include "utility.h"
#include "Node.h"
#include "Linked_List.h"
#include <windows.h>
#include <cstdlib>

enum Operation { HOLD, DEFENSE, ATTACK, ATTACK_FAIL, ERROR_CODE, INPUT_FAIL };
//enum Difficulty{ EASY, NORMAL, DEFAULT };
enum Personality{ DEFAULT, NORMAL };

class Player
{
public:
	Player();
	Operation Act(const Operation &op);
	Operation AI_Decide(const Player &rival, const Personality &pnty);

	int GetNumHold() const;
	int GetNumDefense() const;
	void Clear();
	void Traverse(void(*visit)(Operation &op));
	void SetPlName(const string &str);
	string GetPlName();

protected:
	// data members
	List<Operation> storage;
	int numHold = 0;
	int numDefense = 0;
	string plName = "Player";
	Random random;			// should assure that the default pesudo in Constructor in Random.h is false! 

	//protected tool function
	Operation ActIfHold();
	Operation ActIfDef();
	Operation ActIfAttk();
};


#endif