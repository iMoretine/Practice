#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1001

int main()
{
	char input[MAX_LEN];
	int len;
	char longest[MAX_LEN];
	int longest_len;

	longest_len = -1;

	while( 1 )
	{
		scanf( "%s",input );
		if( input[0] == '\n' )
			break;

		len = strlen(input);
		if( len > longest_len)
		{
			longest_len = len;
			strcpy(longest,input);
		}
	}

	if( longest_len >= 0)
		puts(longest);

	return 0;
}