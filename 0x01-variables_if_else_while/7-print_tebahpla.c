#include <stdio.h>

/**
 * main - This is the entry point for the program.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 122; i >= 97; --i)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
