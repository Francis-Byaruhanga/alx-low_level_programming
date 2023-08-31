#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: Pointer to the number to change
 * @index: Index of the bit to clear
 *
 * Return: 1 for sucess, -1 when it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 31)
	{
		return (-1);
	}
	
	{
		unsigned long int mask = ~(1 << index);
		*n = *n & mask;
	}

	return (1);
}
