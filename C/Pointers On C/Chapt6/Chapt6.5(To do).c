#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
//#include "bitarray.h"

#define MAX_VALUE 10000
#define MAX_BIT_NUMBER ( ( MAX_VALUE - 3 ) / 2 )
#define SIZE ( MAX_BIT_NUMBER / CHAR_BIT + 1 )

int main()
{
	char sieve[ SIZE ];
	int number;
	int bit_number;
	char *sp;

	for( sp = sieve; sp < &sieve[ SIZE ] ;)
		*sp++ = 0xFF;

	for( number = 3; number <= MAX_VALUE ; number += 2)
	{
		bit_number = ( number - 3 ) / 2;
		if( !test_bit(sieve,bit_number) )
			continue;

		while( (bit_number += number ) <= MAX_BIT_NUMBER )
			clear_bit( sieve, bit_number);
	}

	printf( "2\n" );
	for( bit_number = 3, number = 3 ; 
		number < MAX_VALUE; 
		bit_number += 1, number += 2)
	{
		if( test_bit( sieve,bit_number ) )
			printf("%d\n", number );
	}
	return EXIT_SUCCESS;
}