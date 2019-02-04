//*******************************************************************
//CBaseDev (Common Base and devidor)
//This is a selection of functions caculating CBase and CDevidor
//When using them please remember to add all cpps and this file
//*******************************************************************
#ifndef C_BD
#define C_BD

int CdevidorR(
	/* in */ int num1,
	/* in */ int num2);
	//	find the largest common devidor of two numbers
	//	using recursion
	//	Precondition:	they aren't either negative
	//	Postcondition:	return value = common devidor

//*******************************************************************

int CdevidorDI(
	/* in */ int num1,
	/* in */ int num2);
	//	find the largest common devidor of two numbers
	//	using iteration and deviding in turn
	//	Precondition:	
	//	Postcondition:	return value = common devidor

//*******************************************************************

int CBaseD(
	/* in */ int num1,
	/* in */ int num2);
	//	find the least common base of two numbers
	//	after finding the largest common devidor
	//	Precondition:	they aren't either negative
	//	Postcondition:	return value = common base

//*******************************************************************

int CBaseI(
	/* in */ int num1,
	/* in */ int num2);
//	find the least common base of two numbers
//	using iteration
//	Precondition:	they aren't either negative
//	Postcondition:	return value = common base

//*******************************************************************

int CdevidorI(
	/* in */ int num1,
	/* in */ int num2);
//	find the largest common devidor of two numbers
//	using iteration
//	Precondition:	
//	Postcondition:	return value = common devidor

#endif
