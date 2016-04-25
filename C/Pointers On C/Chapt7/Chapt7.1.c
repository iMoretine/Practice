#include <stdio.h>

int hermite( int n, int x)
{
	if( n <= 0)
		return 1;
	if( n == 1)
		return 2*x;
	if( n >=2 )
		return 2 * x * hermite(n-1,x) - 
		2 * (n-1) * hermite(n-2,x); 
	
}

int main()
{
	printf("H3(2) = %d\n",hermite(3,2));
}