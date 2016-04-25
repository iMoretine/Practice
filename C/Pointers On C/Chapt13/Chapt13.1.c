#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int is_not_print(int ch)
{
	return !isprint(ch);
}

static int (*test_func[])( int ) = {
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_not_print
};

#define LENGTH \
	( sizeof (test_func ) / sizeof(test_func[0]) )

char *label[] = {
	"control",
	"whiltspace",
	"digit",
	"lower case",
	"upper case",
	"punctuation",
	"non-printable"
};

int count[ LENGTH ];
int total;

int main()
{
	//int count[ LENGTH ];
	int ch;
	int category;

	while( ( ch = getchar() ) != EOF )
	{
		total += 1;

		for( category = 0 ; category < LENGTH ; category += 1)
		{
			if( test_func[category]( ch ) )
				count[category] += 1;
		}
	}
	
	if(total == 0)
		printf("No characters in the input!\n");
	else
	{
		for( category = 0; category < LENGTH; category += 1)
		{
			printf("%3.0f%% %s characters\n", 
				(float)count[category] * 100 /total , label[category]);
		}
	}

	return 0;
}