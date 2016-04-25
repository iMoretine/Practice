#include <string.h>
#include <stdio.h>

char * my_strnchr( const char *str, int ch, int which)
{
	char *answer = NULL;

	while( -- which >=0 && ( answer = strchr( str, ch) ) != NULL )
		str = answer + 1;

	return answer;
}

int main()
{
	char str[] = "Hello world!";
	char *ch = my_strnchr(str,'o',2);
	printf("%d\n", *ch);
	return 0;
}