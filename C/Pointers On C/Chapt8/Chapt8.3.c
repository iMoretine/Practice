#include <stdio.h>

#define FALSE 0
#define TRUE 1

int identity_matrix( int matrix[10][10] )
{
	int row;
	int column;

	for ( row = 0; row < 10;row ++)
		for(column = 0;column <10;column++)
		{
			if(matrix[row][column] != ( row == column ) )
				return FALSE;
		}

	return TRUE;
}

int main()
{
	int matrix[10][10] = {1,0,0,0,0,  0,0,0,0,0,
				0,1,0,0,0,  0,0,0,0,0,
				0,0,1,0,0,  0,0,0,0,0,
				0,0,0,1,0,  0,0,0,0,0,
				0,0,0,0,1,  0,0,0,0,0,
				0,0,0,0,0,  1,0,0,0,0,
				0,0,0,0,0,  0,1,0,0,0,
				0,0,0,0,0,  0,0,1,0,0,
				0,0,0,0,0,  0,0,0,1,1,
				0,0,0,0,0,  0,0,0,0,1,
			};

	if(identity_matrix(matrix))
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return 0;
}