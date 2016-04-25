#include <stdio.h>

#define CPU_VAX 1
#define CPU_68000 2
#define CPU_68020 3
#define CPU_80386 4
#define CPU_6809 5
#define CPU_6502 6
#define CPU_3B2 7 
#define CPU_UNKNOWN 0

#define X6809

int cpu_type()
{
#if defined( VAX )
	return CPU_VAX;
#elif defined( M68000 )
	return CPU_68000;
#elif defined( M68020 )
	return CPU_68020;
#elif defined( I80386 )
	return CPU_80386;
#elif defined( X6809 )
	return CPU_6809;
#elif defined( X6502 )
	return CPU_6502;
#elif defined( U3B2 )
	return CPU_3B2;
#else
	return CPU_UNKNOWN;
#endif
}

int main()
{
	printf("%d\n",cpu_type());
	return 0;
}