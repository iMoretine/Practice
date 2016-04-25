#include <stdio.h>
#include <string.h>

void deblank (char * string)
{
	int length = strlen(string);
	
	int i;
	int j =0;
	for(i = 0;i<length-1;i++)
	{
		if(string[i] == ' ' && string[i+1] == ' ')
		{
			i++;
		}
		string[j] = string[i];
		j++;
	}
	string[j] = '\0';
}

int main()
{
	char * string = "hello   world!";
	printf("%s\n",string);
	int l = strlen(string) ;
	printf("%d\n",l);
	deblank(string);
	printf("%s\n",string);
}