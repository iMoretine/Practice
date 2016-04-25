#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int palindrome( char *string )
{
	char *string_end;
	string_end = string + strlen(string) - 1;

	while(TRUE)
	{
		while( !isalpha( *string ) )
			string++;
		while ( !isalpha( *string_end ))
			string_end--;

		if( string_end <= string )
		{
			return TRUE;
		}

		if( tolower( *string ) != tolower( *string_end ) )
			return FALSE;

		string++;
		string_end--;
	}
}

int numeric_palindrome( int value )
{
	char string[50];
	sprintf( string , "%d", value);
	return palindrome(string);
}

int main()
{
	int value = 14741;
	printf("%d\n", numeric_palindrome(value));
	return 0;
}