#include <stdio.h>

int gcd( int m, int n )
{
	int r;

	if( m <= 0|| n <= 0)
		return 0;
	do
	{
		r = m % n;
		m = n;
		n = r;
	} while( r > 0 );
	return m;
}

int main()
{
	// test value : 10
	printf("%d\n", gcd(30,20));
	return 0;
}