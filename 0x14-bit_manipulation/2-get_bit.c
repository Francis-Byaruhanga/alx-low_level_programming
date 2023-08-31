#include "main.h"

/**
 * get_bit - returns the value of the bit at an index in a decimal
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 31)
	{
		return (-1);
	}

	return ((n >> index) & 1);
}
