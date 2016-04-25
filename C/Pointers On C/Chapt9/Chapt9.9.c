#include <stdio.h>
#include <string.h>

int count_chars( const char * str, const char * chars )
{
	int count = 0;

	while( (str = strpbrk( str, chars)) != NULL )
	{
		count += 1;
		str++;
	}
	return count ;
}

int main()
{
	char str[] = "Hello world!";
	int count = count_chars(str,"o");
	printf("%d\n",count);
}