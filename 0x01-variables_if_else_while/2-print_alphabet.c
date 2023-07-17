#include <stdio.h>
/**
 * main - this is the entry point of the program
 *
 * Return: It returns zero when the programme is executed successfully
 */

int main(void)
{
	int c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		++c;
	}
	putchar('\n');
	return (0);
}
