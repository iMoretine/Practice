#include <stdio.h>

char * find_char(char const *str, char const *chars )
{
	char *cp;
	char *sp;
	if(str != NULL && chars != NULL )
	{
		for(sp = str ; *sp != '\0';sp++)
		{
			for( cp = chars; *cp != '\0'; cp++)
			{
				if( *sp == *cp)
					return cp;
			}
		}
	}
	return NULL;
}

int main()
{
	char *str = "ABCDEF";
	char *chars = "XRCQEF";
	char *f = find_char(str,chars);
	printf("%c\n",*f);
}