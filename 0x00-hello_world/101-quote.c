#include <unistd.h>
#include <string.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on successful program execution
 */

int main(void)
{
	char *msg = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, msg, strlen(msg));
	return (1);
}
