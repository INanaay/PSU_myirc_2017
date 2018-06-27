/*
** EPITECH PROJECT, 2018
** linkedlist
** File description:
** init
*/

#include "../../../inc/core/linkedlist/linkedlist.h"

int linkedlist_init(linkedlist_t *list)
{
	list->length = 0;
	list->begin = NULL;
	list->end = NULL;
	return (EXIT_SUCCESS);
}
