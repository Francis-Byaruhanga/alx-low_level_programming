#include "main.h"

/**
 * main - This is the entry point of the program.
 * Description - prints all alphabet, in lowercase, followed by a new line
 * Return: Always 0 (Success)
 */

void print_alphabet(void)
{
	char chr;

	chr = 'a';

	while (chr <= 'z')
	{
		_putchar(chr);
		chr++;
	}

	_putchar('\n');
}
