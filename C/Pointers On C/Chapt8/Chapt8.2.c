#include <stdio.h>
#include <float.h>

static double income_limits[]
	= { 0, 23350, 56550, 117950, 256500, DBL_MAX};
static float base_tax[]
	= { 0, 3502.5, 12798.7, 31832.5, 81710.5};
static float percentage[]
	= {.15, .28, .31, .36, .396};

double single_tax( double income )
{
	int category;

	for( category = 1;
		income >= income_limits[ category ];
		category += 1 )
		;
	category -=1;

	return base_tax[ category ] + percentage[ category ] * ( income - income_limits[ category ] );	
}

int main()
{
	float tax;
	scanf("%f",&tax);
	printf("%f\n",single_tax(tax));
	return 0;
}