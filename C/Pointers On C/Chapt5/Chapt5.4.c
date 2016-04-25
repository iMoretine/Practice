#include <stdio.h>
#include <limits.h>

unsigned character_offset( unsigned bit_number)
{
	return bit_number / CHAR_BIT;
}

unsigned bit_offset( unsigned bit_number )
{
	return bit_number % CHAR_BIT;
}

void set_bit(char bit_array[] , unsigned bit_number)
{
	bit_array[ character_offset (bit_number) ]  |= ( 1<< bit_offset( bit_number) );
}

void clear_bit(char bit_array[] , unsigned bit_number)
{
	bit_array[ character_offset (bit_number) ]  &= ~( 1<< bit_offset( bit_number) );
}

void assign_bit(char bit_array[] , unsigned bit_number, int value)
{
	if(value == 0)
		set_bit(bit_array,bit_number);
	else
		clear_bit(bit_array,bit_number);
}

int test_bit( char bit_array[], unsigned bit_number)
{
	return (
		bit_array[ character_offset (bit_number) ]  
		& ( 1<< bit_offset( bit_number) )
		) !=0;
}

int main()
{
	char bit_array[] = "Hello world!";
	printf("%X\n", bit_array[2]);

	set_bit(bit_array,16);
	printf("%X\n", bit_array[2]);

	clear_bit(bit_array,16);
	printf("%X\n", bit_array[2]);

	assign_bit(bit_array,16,1);
	printf("%X\n", bit_array[2]);

	assign_bit(bit_array,16,0);
	printf("%X\n", bit_array[2]);

	printf("%X\n", test_bit(bit_array,16));
	return 0;
}