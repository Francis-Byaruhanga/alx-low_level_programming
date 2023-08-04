#include "main.h"

/**
 * _isupper - checks for the uppercase character
 * @c: the character to be checked
 * Return: 1 if c is uppercase, 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'z')
		return (1);
	return (0);
}
