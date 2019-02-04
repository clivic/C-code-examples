void Swap(
/* inout */ int* ptA,
/* inout */ int* ptB)
{
	int temp;
	temp = *ptA;
	*ptA = *ptB;
	*ptB = temp;
}