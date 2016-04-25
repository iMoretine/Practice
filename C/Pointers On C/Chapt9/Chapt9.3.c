#include <string.h>
#include <stdio.h>

char * my_strcpy( char *dst, const char *src , int size)
{
	strncpy(dst,src,size);
	dst[size - 1] = '\0';

	return dst;
}

int main()
{
	char str01[] = "hello!";
	char str02[] = "Hello World!";
	strncpy(str01,str02,12);
	printf("%s\n",str01);
	return 0;
}