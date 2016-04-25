#include <stdio.h>

int main()
{
	int ch;
	signed char checksum = -1;

	while( (ch = getchar()) != EOF )
	{
		checksum += ch;
		if( ch == '\n' )
			printf("%d\n", checksum);
	}
}