//*******************************************************************
//	找尋兩個數的最大公約數，用輾轉相除的迴圈(iteration)方法
//*******************************************************************

int CdevidorI(
	/* in */ int num1,
	/* in */ int num2)
	//	find the largest common devidor of two numbers
	//	using iteration
	//	Precondition:	num1 >= 0 && num2 >= 0
	//	Postcondition:	return value = common devidor
{
	int i;

	//find minimum
	int min = num1;
	if (num2 < min)
		min = num2;

	for (i = min; i >0; i--)
	{
		if (num1 % i == 0 && num2 % i == 0)
			return i;
	}
}