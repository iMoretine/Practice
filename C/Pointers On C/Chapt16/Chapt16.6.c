#include <math.h>
#include <stdio.h>

double	payment( double amount, double interest, int periods )
{
	interest /= 1200;         
	amount = amount * interest / ( 1 - pow( 1 + interest, (double)( -periods ) ) );
	return floor( amount * 100 + 0.5 ) / 100;
}

int main()
{
	printf("Input the amount , interest the periods : \n");
	double amount,interest;
	int periods;
	scanf("%lf%lf%d",&amount,&interest,&periods);
	printf("Payment : %.2lf\n", payment(amount,interest,periods));
	return 0;
}