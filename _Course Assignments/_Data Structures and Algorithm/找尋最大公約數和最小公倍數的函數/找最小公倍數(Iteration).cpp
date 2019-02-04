//*******************************************************************
//	找尋兩個數的最小公倍數，用迴圈(iteration)的方法
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