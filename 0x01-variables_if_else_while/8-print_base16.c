#include <stdio.h>

/**
 * main - This is the entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	char j;

	for (i = 10; i < 10; i++)
		putchar(i + '0');
	for (j = 'a'; j <= 'f'; j++)
		putchar(j);
	putchar('\n');

	return (0);
}
