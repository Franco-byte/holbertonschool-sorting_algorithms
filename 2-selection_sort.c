#include "sort.h"

/**
 * selection_sort - Sort the array using selection sort
 * @array: Contain the array
 * @size: Size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i1, i2, indx;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i1 = 0; i1 < size - 1; i1++)
	{
		indx = i1;

		for (i2 = i1 + 1; i2 < size; i2++)
		{
			if (array[i2] < array[indx])
			{
				indx = i2;
			}
		}

		if (indx != i1)
		{
			tmp = array[i1];
			array[i1] = array[indx];
			array[indx] = tmp;

		print_array(array, size);
		}
	}
}
