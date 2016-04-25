#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int n_cntrl;
int n_space;
int n_digit;
int n_lower;
int n_upper;
int n_punct;
int n_nprint;
int total;

int main()
{
	int ch;
	int category;

	while( (ch = getchar()) != EOF )
	{
		total  += 1;

		if( iscntrl( ch ) )
			n_cntrl ++;
		if( isspace( ch ) )
			n_space ++;
		if( isdigit( ch ) )
			n_digit ++;
		if( islower( ch ) )
			n_lower ++;
		if( isupper( ch ) )
			n_upper ++;
		if( ispunct( ch ) )
			n_punct ++;
		if( isprint( ch ) )
			n_nprint ++;
	}

	if( total == 0 )
		printf( "No characters in the input!\n" );
	else
	{
		printf("%3.0f control characters\n", n_cntrl * 100.0 / total );
		printf("%3.0f whitespace characters\n", n_space * 100.0 / total );
		printf("%3.0f digit characters\n", n_digit * 100.0 / total );
		printf("%3.0f lower case characters\n", n_lower * 100.0 / total );
		printf("%3.0f upper case characters\n", n_upper * 100.0 / total );
		printf("%3.0f punctuation characters\n", n_punct * 100.0 / total );
		printf("%3.0f non-printable characters\n", n_nprint * 100.0 / total );
	}
	return EXIT_SUCCESS;
}