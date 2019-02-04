char *strcat1(char *to, char *from)
//Pre:	The strings from and to have been initialized.
//Post:	The function copies string from to the end of string to, including ¡®\0¡¯; 
//		it returns a pointer to the beginning of the string to.
{
	int start(0);
	for (; to[start] != '\0'; start++);
	
	int count(0);
	for (; from[count] != '\0'; count++)
	{
		to[start] = from[count];
		start++;
	}
	to[start] = '\0';
	return to;
	
}