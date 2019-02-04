//*******************************************************************
//	�Ҍ��ɂ�������С����������ޒȦ(iteration)�ķ���
//*******************************************************************

int CBaseI(
	/* in */ int num1,
	/* in */ int num2)
//	find the least common base of two numbers
//	using iteration
//	Precondition:	num1 >= 0 && num2 >= 0
//	Postcondition:	return value = common base
{
	static int m;
	for (m = num1; !(m % num1 == 0 && m % num2 == 0); m += num1);
	return m;
}