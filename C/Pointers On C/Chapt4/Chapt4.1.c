#include <stdio.h>

int main()
{
	float new_guess;
	float last_guess;
	float number;

	printf("Enter a number :");
	scanf("%f",&number );

	if( number < 0 )
	{
		printf("Cannot compute the square root of a negative number!\n");
		return 0;
	}

	new_guess = 1;
	while(new_guess != last_guess)
	{
		last_guess = new_guess;
		new_guess = ( last_guess + number/last_guess ) /2; 
		printf("%.15e\n",new_guess );
	}

	printf("Square root of %f is %f \n",number, new_guess );
	return 0;
}