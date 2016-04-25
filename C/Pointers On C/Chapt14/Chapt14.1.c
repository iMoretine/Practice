#include <stdio.h>
#define OPTION_LONG
#define OPTION_DETAILED

void print_ledger_long( int x )
{
	printf("long : %d\n",x);
}

void print_ledger_detailed( int x )
{
	printf("detailed : %d\n",x);
}

void print_ledger_default( int x )
{
	printf("default : %d\n",x);
}

void print_ledger( int x )
{
#ifdef OPTION_LONG
	#define	 OK 1
	print_ledger_long( x );
#endif

#ifdef OPTION_DETAILED
	#define	 OK 1
	print_ledger_detailed( x );
#endif

#ifndef OK
	print_ledger_defailt( x );
#endif
}

int main()
{
	print_ledger(20);
	return 0;
}