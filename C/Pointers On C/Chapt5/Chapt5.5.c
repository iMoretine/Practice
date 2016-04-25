#include <stdio.h>
#include <limits.h>

#define INT_BITS (CHAR_BIT * sizeof( int ))

int store_bit_field(int original_value , int value_to_store , unsigned starting_bit ,unsigned ending_bit)
{
	unsigned mask;
	if( starting_bit < INT_BITS && ending_bit < INT_BITS && starting_bit >= ending_bit)
	{
		mask = (unsigned) - 1; // 0xff;
		mask >>= INT_BITS - ( starting_bit - ending_bit + 1);
		mask <<= ending_bit;

		original_value &= ~mask;

		value_to_store <<= ending_bit;

		original_value |= value_to_store & mask;
	}
	return original_value;
}

int main()
{
	printf("%x\n", store_bit_field(0x0,0x1,4,4));
	printf("%x\n", store_bit_field(0xffff,0x123,15,4));
	printf("%x\n", store_bit_field(0xffff,0x123,13,9));
	return 0;
}