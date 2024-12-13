#include "sort.h"

/**
 * bubble_sort - bubble sort
 * @array: Contain the elements
 * @size: Size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i1, tmp;
	int swap;

	if (array == NULL || size < 2)
		return;
	do {
		swap = 0;

	for (i1 = 0; i1 < size - 1; i1++)
	{
		if (array[i1] > array[i1 + 1])
		{
			tmp = array[i1];
			array[i1] = array[i1 + 1];
			array[i1 + 1] = tmp;

			swap = 1;
			print_array(array, size);
		}
	}
	} while (swap);
}
