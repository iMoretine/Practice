#include <stdio.h>
#include <string.h>

size_t my_strlen( const char *string, int size)
{
	register size_t length;

	for( length = 0; length < size; length ++ )
	{
		if( *string++ == '\0')
			break;
	}

	return length;
}


char * my_strcat( char *dst , const char *src , int size)
{
	int length;

	size -= 1;
	length = size - (int)my_strlen( dst,size );
	if( length > 0)
	{
		strncat(dst,src,length);
		dst[size] = '\0';
	}

	return dst;
}

int main()
{
	char str01[] = "Hello ";
	char str02[] = "World!";
	my_strcat(str01,str02,13);
	printf("%s\n",str01);
	return 0;
}