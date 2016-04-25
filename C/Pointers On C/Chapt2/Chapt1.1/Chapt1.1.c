#include <stdio.h>
#include "negate.h"
#include "increaments.h"

int main()
{
	printf("%d %d %d\n",negate(10),negate(0),negate(-10));
	printf("%d %d %d\n",increaments(10),increaments(0),increaments(-10));
	return 0;
}