#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @n: pointer to the number to change
 * @index: index of thw bit to set to 1
 *
 * Return: 1 for success, -1 when it fails
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 31)
	{
		return (-1);
	}

	{
		unsigned long int mask = 1 << index;
		*n = *n | mask;
	}
	return (1);
}
