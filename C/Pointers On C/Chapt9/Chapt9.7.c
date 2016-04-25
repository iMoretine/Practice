#include <string.h>
#include <stdio.h>

char * my_strrchr( const char *str, int ch)
{
	char *prev_answer = NULL;

	for( ; (str = strchr(str,ch) ) != NULL;str += 1)
		prev_answer = str;

	return prev_answer;
}

int main()
{
	char str[] = "Hello world!";
	char *ch = my_strrchr(str,'o');
	printf("%d\n", *ch);
	return 0;
}