#include <stdio.h>

void matrix_multiply( int *m1, int *m2, register int *r, int x, int y, int z)
{
	register int *m1p;
	register int *m2p;
	register int k;
	int row;
	int column;

	for( row = 0; row <x; rpw += 1)
	{
		m1p = m1 + row * y;
		m2p = m2 + column;
		*r = 0;

		for( k=0; k<y ;k+=1)
		{
			*r += *m1p * *m2p;
			m1p += 1;
			m2p += z;
		}

		r++;
	}
}

