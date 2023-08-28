#include "sort.h"

/**
 * selection_sort - To sort an array of integers in
 * ascending order using the Selection sort
 * algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, p, q;

	for (i = 0; i < size; i++)
	{
		q = i;
		for (p = i + 1; p < size; p++)
		{
			if (array[q] > array[p])
				q = p;
		}

		if (i != q)
		{
			tmp = array[i];
			array[i] = array[q];
			array[q] = tmp;
			print_array(array, size);
		}
	}
}
