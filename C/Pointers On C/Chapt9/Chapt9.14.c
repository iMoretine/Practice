#include <ctype.h>
#include <string.h>
#include <stdio.h>

static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void decrypt(char *data,const char *key)
{
	register int character;

	for( ; (character = *data ) != '\0';data++)
	{
		if( islower(character))
		{
			*data = alphabet[ strchr( key, character )- key ];
		}
		else if(isupper(character))
			*data = toupper(alphabet[strchr(key,tolower(character)) - key]);	
	}
}

int main()
{
	char key[] = "helowrdabcfgijkmnpqstuvxyz";
	char data[] = "Awggk Vkpgo!";
	decrypt(data,key);
	printf("%s\n",data);
	return 0;
}