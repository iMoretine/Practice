#include <stdio.h>

void reverse_string(char * str)
{
	char * last_char;
	char temp;	
	for(last_char = str; *last_char != '\0';last_char++)
		;
	last_char--;

	while( str < last_char)
	{
		temp = *str;
		*str = *last_char;
		*last_char = temp;
		str++;
		last_char--;
	}
}

int main()
{
	char str[] = "Hello world!";
	printf("%s\n",str);
	reverse_string(str);
	printf("%s\n",str);
	return 0;
}