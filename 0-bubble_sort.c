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
	size_t i1, i2, tmp1, tmp2;

	if (array == NULL || size < 2)
		return;

	for (i1 = 0; i1 < size; i1++)
	{
		for (i2 = i1 + 1; i2 < size; i2++)
		{
			if (array[i1] > array[i2])
			{
				tmp1 = array[i1];
				tmp2 = array[i2];
				array[i1] = tmp2;
				array[i2] = tmp1;

				print_array(array, size);
			}
		}
	}
}
