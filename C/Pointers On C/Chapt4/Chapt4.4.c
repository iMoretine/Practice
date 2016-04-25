#include <stdio.h>

void copy_n(char dst[],char src[],int n)
{
	int dst_index, src_index;
	src_index = 0;
	for(dst_index=0;dst_index<n;dst_index += 1)
	{
		
		if(src[src_index] != '\0')
		{
			dst[dst_index] = src[src_index];
			src_index += 1;
		}
		else
		{
			dst[dst_index] = '\0';
		}
	}
}
int main()
{
	char dst[20];
	char * src = "Hello world.";
	printf("%s\n",src);
	copy_n(dst,src,10);
	printf("%s\n",dst);	
}

	