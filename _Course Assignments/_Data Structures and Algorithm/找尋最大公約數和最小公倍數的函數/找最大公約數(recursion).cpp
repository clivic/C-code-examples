//*******************************************************************
//	找尋兩個數的最大公約數，用輾轉相除的遞歸(recursion)方法
//*******************************************************************

int CdevidorR(
	/* in */ int num1,
	/* in */ int num2)
	//	find the largest common devidor of two numbers
	//	using recursion
	//	Precondition:	num1 >= 0 && num2 >= 0
	//	Postcondition:	return value = common devidor
{
	if (num2 > 0)
		return CdevidorR(num2, num1 % num2);
	else 
		return num1;
}