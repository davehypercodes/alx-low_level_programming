#include "main.h"

int print_last_digit(int n)
{
	int not_last_digit = 1;
	while (not_last_digit)
	{
		n = n / 10;
		if (n < 10)
		{
			return n;
		}
	}
	return (0);
}