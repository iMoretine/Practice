#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

int main()
{
	char buf[BUFSIZE];

	while( fgets( buf,BUFSIZE,stdin )  != NULL )
		fputs( buf, stdout );

	return EXIT_SUCCESS;
}