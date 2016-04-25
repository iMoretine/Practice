#include <stdio.h>

int main()
{
	float edge01;
	float edge02;
	float edge03;
	printf("Enter the edge of triangles:\n");
	scanf("%f%f%f",&edge01,&edge02,&edge03);
	if(edge01<=0 ||edge02<=0 ||edge02<=0)
	{
		printf("Cannot input a negative numbers.\n");
		return 0;
	}

	if((edge01+edge02) <= edge03 ||
		(edge01+edge03) <= edge02 ||
		(edge03+edge02) <= edge01)
	{
		printf("It can't be a triangle.\n");
		return 0;
	}

	if(edge01 == edge02 ||
		edge02 == edge03 ||
		edge01 == edge03)
	{
		if(edge01 == edge02 == edge03)
		{
			printf("It's a equilateral triangle.\n");
		}
		else
			printf("It's a isosceles triangle.\n");
	}
		
}

	