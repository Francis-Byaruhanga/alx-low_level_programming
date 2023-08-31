#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian.
 *
 * Return: returns 0 for big, 1 for little.
 */
int get_endianness(void)
{
	int n = 1;
	int result = 0;

	char *byte_order = (char *)&n;

	if (byte_order[0] == 1)
	{
		result = 1;
	}

	return (result);
}
