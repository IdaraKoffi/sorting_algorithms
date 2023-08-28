#include "sort.h"
/**
 * counting_sort -To sort an arrayof integers
 * in ascending order using the
 * Counting sort algorithm
 * @array: array
 * @size: sizeto be sorted
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int n, p;
	int *buff, *a;

	if (size < 2)
		return;

	for (n = p = 0; p < (int)size; p++)
		if (array[p] > n)
			n = array[p];

	buff = malloc(sizeof(int) * (n + 1));
	if (!buff)
		return;

	for (p = 0; p <= n; p++)
		buff[p] = 0;
	for (p = 0; p < (int)size; p++)
		buff[array[p]] += 1;
	for (p = 1; p <= n; p++)
		buff[p] += buff[p - 1];

	print_array(buff, (n + 1));
	a = malloc(sizeof(int) * (size + 1));

	if (!a)
	{
		free(buff);
		return;
	}
	for (p = 0; p < (int)size; p++)
	{
		a[buff[array[p]] - 1] = array[p];
		buff[array[p]] -= 1;
	}

	for (p = 0; p < (int)size; p++)
		array[p] = a[p];

	free(buff);
	free(a);
}
