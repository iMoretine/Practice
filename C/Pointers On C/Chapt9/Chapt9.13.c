#include <ctype.h>
#include <stdio.h>

void encrypt( char *data, const char *key)
{
	register int character;

	for( ; (character = *data ) != '\0';data++)
	{
		if( islower(character) )
		{
			*data = key[character - 'a'];
		}
		else if( isupper(character))
		{
			*data = toupper( key[ character - 'A'] );
		}
	}
}

int main()
{
	char key[] = "helowrdabcfgijkmnpqstuvxyz";
	char data[] = "Hello World!";
	encrypt(data,key);
	printf("%s\n",data);
	return 0;
}