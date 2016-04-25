#include <stdio.h>
#include <string.h>

void my_strncat( char *dest, char *src, int dest_len)
{
	register int len;
	len = strlen( dest );
	dest_len -= len + 1;
	if( dest_len > 0)
		strncat( dest + len, src, dest_len);
}

int main()
{
	char str01[] = "Hello ";
	char str02[] = "World!";
	my_strncat(str01,str02,13);
	printf("%s\n",str01);
	return 0;
}