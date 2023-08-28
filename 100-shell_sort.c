#include "sort.h"
/**
 * shell_sort - A function that sorts an array 
 * of integers in ascending order using the
 * Shell sort algorithm
 *
 * @array: An input arrray
 * @size: The size of the array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}
/**
 * _ssort - an auxiliar function for
 * shell_sort function
 * @a: an input arrray
 * @size: the size of the array
 * @n: intervale
 * Return: no return
 */
void _ssort(int *a, int size, int n)
{
	int tmp, b, p;

	for (a = 0; (b + n) < size; b++)
	{
		for (p = b + n; (p - n) >= 0; p = p - n)
		{
			if (a[p] < a[p - n])
			{
				tmp = a[p];
				a[p] = a[p - n];
				a[p - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
