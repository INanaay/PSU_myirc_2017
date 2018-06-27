/*
** EPITECH PROJECT, 2018
** linkedlist
** File description:
** destroy
*/

#include <stdlib.h>
#include "../../../inc/core/linkedlist/linkedlist.h"

int linkedlist_destroy(linkedlist_t *list)
{
	node_t *node;

	if (list == NULL)
		return (EXIT_FAILURE);
	if (list->length == 0)
	{
		list->begin = NULL;
		list->end = NULL;
	}
	node = list->begin;
	while (node != list->end)
	{
		node = node->next;
		free(node->prev);
	}
	free(node);
	return (EXIT_SUCCESS);
}
