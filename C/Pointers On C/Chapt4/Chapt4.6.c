#include <stdio.h>

int substr( char dst[] , char src[] , int start , int len)
{
	int srcindex;
	int dstindex;

	dstindex = 0;

	if( start >= 0 && len > 0)
	{
		srcindex = start ;
		while( len > 0 && src[srcindex] != '\0')
		{
			dst[dstindex] = src[srcindex];
			dstindex += 1;
			srcindex += 1;
			len -= 1;
		}
	}

	dst[dstindex] = '\0';
	return dstindex;
}

int main()
{
	char src[20] = "Hello world!";
	char dst[20];
	printf("%s\n",src );
	substr(dst,src,5,5);
	printf("%s\n",dst );
}