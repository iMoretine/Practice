#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OK_RAND\
	(int)( ( ( (long)RAND_MAX + 1 ) / 6 )  * 6 - 1 )

int throw_die()
{
	static int is_seeded = 0;
	int value;

	if( !is_seeded )
	{
		is_seeded = 1;
		srand( (unsigned int)time( NULL ) );
	}

	do
	{
		value = rand();
	}while( value > MAX_OK_RAND );

	return value % 6 + 1;
}

int main()
{
	while(1)
	{
		printf("%d\n", throw_die());
		system("sleep 1");
	}
	return 0;
}