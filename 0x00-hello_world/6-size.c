#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on successful program execution
 */

int main(void)
{
	printf("Size of int: %lu\n", sizeof(int));
	printf("Size of char: %lu\n", sizeof(char));
	printf("Size of long int: %lu\n", sizeof(long int));
	printf("Size of long long int: %lu\n", sizeof(long long int));
	printf("Size of float: %lu\n", sizeof(float));
	return (0);
}
