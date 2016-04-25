#include <stdio.h>
#include <malloc.h>

#define DELTA 100

int * readints()
{
	int *array;
	int count;
	int size;
	int value;

	size = DELTA;
	array = malloc( ( size + 1 ) * sizeof( int ) );
	if( array == NULL )
		return NULL;

	count = 0;
	while( scanf( "%d",&value) == 1)
	{
		count ++;
		if( count > size)
		{
			size += DELTA;
			array = realloc( array, ( size + 1 ) * sizeof (int) );
			if ( array == NULL )
			{
				return NULL;
			}
		}
		array[count] = value;
	}

	if( count < size )
	{
		array = realloc( array, (count + 1) * sizeof( int ));
		if (array == NULL)
			return NULL;
	}
	array[0] = count;
	return array;
}

int main()
{
	int *array = readints();
	int i;
	for(i=0;i<=array[0];i++)
		printf("%d\n",array[i]);
	return 0;
}