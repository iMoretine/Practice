#include <stdio.h>
#include <string.h>

void dollars( register char *dst, register const char *src)
{
	int len;

	if( dst == NULL || src == NULL )
		return ;

	*dst ='$';
	dst++;

	len = strlen( src );

	if( len >= 3 )
	{
		int i;

		for( i = len - 2; i > 0; )
		{
			*dst++ = *src++;
			if( --i > 0 && i % 3 == 0)
			{
				*dst++ = ',';
			}
		}
	}
	else
		*dst++ = '0';

	*dst++ = '.';
	*dst++ = len < 2 ? '0' : *src++;
	*dst++ = len < 1 ? '0' : *src++;;
	*dst = 0;
}

int main()
{
	char dst[20];
	char src[] = "123456789";
	dollars(dst,src);
	printf("%s\n", dst);
}