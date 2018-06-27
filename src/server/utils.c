/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdlib.h>
#include <memory.h>
#include "../../inc/core/linkedlist/linkedlist.h"
#include "../../inc/server/entities/entities.h"

size_t get_clients_nicknames_len(linkedlist_t *list)
{
	size_t result = 0;
	irc_client_t *client = NULL;

	for (node_t *node = list->begin; node != NULL; node = node->next)
	{
		client = node->value;
		result += strlen(client->nickname);
	}
	return (result);
}