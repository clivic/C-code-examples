//*******************************************************************
//	�Ҍ��ɂ�������С���������ó�����󹫼s���ķ���
//*******************************************************************
#include "CBaseDev.h"

int CBaseD(
	/* in */ int num1,
	/* in */ int num2)
	//	find the least common base of two numbers
	//	after finding the largest common devidor
	//	Precondition:	num1 >= 0 && num2 >= 0
	//	Postcondition:	return value = common base
{
	return num1 * num2 / CdevidorI(num1, num2);
}