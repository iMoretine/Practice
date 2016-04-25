#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int format( char *pattern, const char *digits)
{
	char *patternp, *digitp;

	if( pattern == NULL || digits == NULL )
	{
		return FALSE;
	}

	patternp = pattern + strlen( pattern ) - 1;
	digitp = digits + strlen(digits) - 1;

	if( digitp < digits )
	{
		return FALSE;
	}

	while(patternp >= pattern && digitp >= digits )
	{
		if( *patternp == '#')
		{
			*patternp-- = *digitp--;
			continue;
		}
		patternp--;
	}

	while( patternp >= pattern )
	{
		if( *patternp == '.' )
		{
			char *p0;

			for( p0 = patternp + 1; *p0 == ' '; *p0++ = '0' )
				;
			*--patternp = '0';
			--patternp;
			continue;
		}
		*patternp-- = ' ' ;
	}
	return digitp < digits;
}

int main()
{
	char pattern[] = "#,###,###.##";
	char digits[] = "123456789";
	format(pattern,digits);
	printf("%s\n",pattern);
	return 0;
}