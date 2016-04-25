#include <stdio.h>

int main()
{
	int prime[101];
	memset(prime,1,sizeof(prime));
	prime[0] = 0;
	prime[1] = 0;
	int  i,k;
	for(i=2;i<101;i++)
	{
		if(prime[i])
		{
			for(k = i*i;k<101;k+=i)
				prime[k] = 0;
		}
	}

	for(i=1;i<101;i++)
	{
		if(prime[i])
			printf("%d\n",i);
	}
	return 0;
}