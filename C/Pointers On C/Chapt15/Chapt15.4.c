#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

FILE* openfile( char *prompt, char *mode)
{
	char buf[BUFSIZE];
	FILE *file;

	printf( "%s filename? ", prompt );
	if( gets( buf ) == NULL )
	{
		fprintf(stderr, "Missing %s file name.\n", prompt);
		exit( EXIT_FAILURE );
	}

	if( (file = fopen( buf, mode )) == NULL )
	{
		perror( buf );
		exit( EXIT_FAILURE );
	}

	return file;
}

int main()
{
	char buf[BUFSIZE];
	FILE *input;
	FILE *output;
	FILE *openfile();

	input = openfile("Input","r");
	output = openfile("Output","w");

	while( fgets( buf , BUFSIZE , input ) != NULL )
		fputs(buf,output);

	fclose(input);
	fclose(output);

	return EXIT_SUCCESS;
}