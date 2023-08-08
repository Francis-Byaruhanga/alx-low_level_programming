#include "main.h"
#include <stdlib.h>

/**
 * *create_array - creates an array of chars, and initializses
 * it with a specific char
 * @size: sizes of the array to create
 * @c: char to initialize the array c
 *
 * Return: pointer to the array (Success), NULL (Error)
 */

char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);

	arr = (char *) malloc(sizeof(char) * size);

	if (arr == NULL)
		return (0);

	while (i < size)
	{
		*(arr + i) = c;
		i++;
	}

	*(arr + i) = '\0';

	return (arr);
}
