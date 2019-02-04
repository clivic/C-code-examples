char *strCopy(char *to, char *from)
//Pre: The string from has been initialized.
// Post: The function copies string from to string to, including ¡®\0¡¯; it returns a pointer to the beginning of the string to.
/*{
int i(0);
for (; from[i] != '\0'; i++)
{
to[i] = from[i];
}
to[i] = from[i];
return to;
}*/

{
	char* toS;
	char* fromS;
	char* toP;
	char* fromP;
	toS = to;
	toP = to;
	fromS = from;
	fromP = from;

	while (*fromP != '\0')
	{
		*toP = *fromP;
		toP++;
		fromP++;
	}
	*toP = *fromP;
	return to;
}