#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t my_strnlen( const char *string, int size)
{
	register size_t length;

	for( length = 0; length < size; length ++ )
	{
		if( *string++ == '\0')
			break;
	}

	return length;
}

int main()
{
	char str01[] = "Hello world!";
	char str02[] = "Hello!";
	
	int size = strlen(str01);
	
	printf("%d\n",(int)strlen(str01));
	strcpy(str01,str02);
	printf("%d\n",(int)strlen(str01));
	
	int length = my_strnlen(str01,size);
	printf("%d\n",length);
	return 0;
}
