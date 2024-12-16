#include "sort.h"

/**
 * swap - Intercambia dos elementos en un arreglo
 * @array: El arreglo
 * @i: Índice del primer elemento
 * @j: Índice del segundo elemento
 * @size: Tamaño del arreglo (para impresión)
 */

void swap(int *array, size_t i, size_t j, size_t size)
{
	if (i != j)
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * partition - Divide el arreglo utilizando el esquema de Lomuto
 * @array: El arreglo a ordenar
 * @low: Índice inicial de la partición
 * @high: Índice final de la partición (pivote)
 * @size: Tamaño del arreglo
 * Return: Índice del pivote después de particionar
 */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j, size);
			i++;
		}
	}
	swap(array, i, high, size);
	return (i);
}

/**
 * quick_sort_recursive - Ordena recursivamente las particiones
 * @array: El arreglo a ordenar
 * @low: Índice inicial de la partición actual
 * @high: Índice final de la partición actual
 * @size: Tamaño del arreglo
 */

void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = partition(array, low, high, size);

		if (pivot_index > 0) /* Evitar desbordamiento por debajo */
			quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Ordena un arreglo de enteros en orden ascendente
 *              utilizando el algoritmo de Quick Sort
 * @array: El arreglo a ordenar
 * @size: Tamaño del arreglo
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

