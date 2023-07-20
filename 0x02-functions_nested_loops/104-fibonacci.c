#include <stdio.h>
#include <string.h>

#define MAX 10000

void add(char *a, char *b, char *p)
{
	int k = 0;

	for (int i = strlen(a) - 1, j = strlen(b) - 1; i >= 0 || j >= 0 || k; i--, j--, k /= 10)
	{
		if 
			(i >= 0) k += a[i] - '0';
		if
			(j >= 0) k += b[j] - '0';
		p[strlen(p)] = (k % 10 + '0');
	}

	for (int i = 0, j = strlen(p) - 1; i < j; i++, j--)
	{
		char temp = p[i];

		p[i] = p[j];
		p[j] = temp;
	}
}

int main(void)
{
	char fib[10000][MAX];

	fib[0][0] = fib[1][0] = '1';
	fib[0][1] = fib[1][1] = '\0';

	int n = 98;

	for (int i = 2; i < n; i++)
	{
		add(fib[i - 1], fib[i - 2], fib[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s", fib[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");

	return (0);
}

