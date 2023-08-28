#include "sort.h"
/**
 * quick_sort - A function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: an input arrray
 * @low: an index for the first element
 * @high: an index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int low, int high, int size)
{
	int j, k, l;
	int tmp;

	if (low < high)
	{
		j = high;
		k = low;
		for (l = low; l < high; l++)
		{
			if (a[l] < a[j])
			{
				if (l != k)
				{
					tmp = a[l];
					a[l] = a[k];
					a[k] = tmp;
					print_array(a, size);
				}
				k++;
			}
		}
		if (k != j && a[k] != a[j])
		{
			tmp = a[k];
			a[k] = a[j];
			a[j] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, k - 1, size);
		_qsort(a, k + 1, high, size);
	}
}
