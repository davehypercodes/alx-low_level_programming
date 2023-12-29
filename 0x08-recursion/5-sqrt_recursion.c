#include "main.h"

/**
* _sqrt_recursion - Returns the natural square root of a number.
* @n: The number to find the square root of.
*
* Return: The square root of n, or -1 if n does not have a natural square root.
*/
int _sqrt_recursion(int n)
{
	unsigned int k;

	k = n;
	if (k == 0 || k == 1)
		return (k);
	return (sqrt_helper(k, 1, k));
}

/**
* sqrt_helper - Recursive helper function to find the square root.
* @n: The number to find the square root of.
* @start: The starting point for the search.
* @end: The ending point for the search.
*
* Return: The square root of n,
* or -1 if n does not have a natural square root.
*/

unsigned int sqrt_helper(unsigned int n, int start, unsigned int end)
{
	int mid;

	if (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid < n)
			return (sqrt_helper(n, mid + 1, end));
		return (sqrt_helper(n, start, mid - 1));
	}
	return (-1);
}
