#include "main.h"
/**
 * reverse_array - function that reverse the content of an array of integers
 * @a: array to reverse it
 * @n: the number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i, t;

	for (i = 0; i < n--; i++)
	{
		t = a[i];
		a[i] = a[n];
		a[n] = t;
	}
}
