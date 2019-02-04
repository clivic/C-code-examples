//*******************************************************************
//	�Ҍ��ɂ�������󹫼s������ݚ�D�����ޒȦ(iteration)����
//*******************************************************************

int CdevidorDI(
	/* in */ int num1,
	/* in */ int num2)
	//	find the largest common devidor of two numbers
	//	using iteration and devide in turn
	//	Precondition:	num1 >= 0 && num2 >= 0
	//	Postcondition:	return value = common devidor
{
	static int temp;
	while (num2 > 0)
	{
		temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	return num1;
}