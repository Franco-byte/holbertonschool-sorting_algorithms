#include "sort.h"

/**
 * swap_nodes - Intercambia dos nodos en una lista doblemente enlazada
 * @list: Doble puntero al inicio de la lista
 * @left: Puntero al nodo izquierdo
 * @right: Puntero al nodo derecho
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - Ordena una lista doblemente enlazada utilizando
 * el algoritmo de ordenación por inserción
 * @list: Doble puntero al inicio de la lista
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;
		while (insert && insert->n > current->n)
		{
			swap_nodes(list, insert, current);
			print_list(*list);
			insert = current->prev;
		}
		current = current->next;
	}
}
