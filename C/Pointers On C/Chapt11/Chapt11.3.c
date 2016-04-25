#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define DELTA 256

char * readstring()
{
	static char *buffer = NULL;
	static int buffer_size = 0;
	int ch;
	int len;
	char *bp;

	bp = buffer;
	len = 0;

	do
	{
		ch = getchar();
		if( ch == '\n' || ch == EOF )
			ch = '\0';

		if( len >= buffer_size )
		{
			buffer_size += DELTA;
			buffer = realloc( buffer , buffer_size );
			assert ( buffer != NULL );
			bp = buffer + len;
		}

		*bp++ = ch;
		len += 1;
	}while( ch != '\0' );
	
	bp = malloc( len );
	assert( bp != 0 );
	strcpy( bp ,buffer);
	return bp;
}

int main()
{
	char * str = readstring();
	printf("%s\n",str );
	return 0;
}