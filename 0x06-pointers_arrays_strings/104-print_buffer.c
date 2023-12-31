#include "main.h"
#include <stdio.h>

/**
 * print_line - prints a s bytes of a buffer
 * @c: buffer to print
 * @s: bytes of buffer to print
 * @1: line of buffer to print
 *
 * Return: void
 */

void print_line(char *c, int s, int line_num)
{
	int j, k;
	for (j = 0; j <= 9; j++)
	{
		if (j <= s)
			printf("%02x", c[line_num * 10 + j]);
		else
			printf(" ");
		if (j % 2)
			putchar(' ');
	}
	for (k = 0; k <= s; k++)
	{
		if (c[line_num * 10 + k] > 31 && c[line_num * 10 + k] < 127)
			putchar(c[line_num * 10 + k]);
		else
			putchar('.');
	}
}

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of buffer
 *
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int i;

	for (i = 0; i <= (size - 1) / 10 && size; i++)
	{
		printf("%08x: ", i * 10);
		print_line(b, 9, i);
		putchar('\n');
	}
	
	if (size == 0)
		putchar('\n');
}
