#include <stdio.h>

#define TRUE 1
#define FALSE 0

char * match(char *str, char *want)
{
	while(*want != '\0')
		if( *str++ != * want++)
			return NULL;

	return str;
}

int del_substr( char *str, char const * substr)
{
	char *next;

	while(*str != '\0')
	{
		next = match(str,substr);
		if( next != NULL)
			break;
		str++;
	}

	if( *str == '\0')
		return FALSE;

	while(*str++ = *next++)
		;

	return TRUE;
}

int main()
{
	char *str = "ABCDEFG";
	char *substr = "CDE";
	del_substr(str,substr);
	printf("%s\n",str);
	return 0;
}