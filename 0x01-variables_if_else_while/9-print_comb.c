#include <stdio.h>

/**
 * main - This is the entry point of the program.
 *
 * Return: Always O (Success)
 */

int main(void)
{
	int i, j;

	for (i = 48; i <= 57; i++)
	{
		for (j = i; j <= 57; j++)
		{
	
			putchar(i);
			if (i != j)
			{
				putchar(j);
			}

			if (i != 56 || j != 57)
			{
				putchar(44);
				putchar(32);
			}
		}
	}
	return (0);
}
