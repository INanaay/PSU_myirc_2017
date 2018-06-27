/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include "../../../../inc/server/entities/entities.h"

int irc_channel_join(irc_channel_t *channel, irc_client_t *client)
{
	if (channel == NULL || client == NULL)
		return (EXIT_FAILURE);
	if (linkedlist_append(&channel->clients, client) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	printf("[+] %s added to %s\n", client->nickname, channel->name);
	return (EXIT_SUCCESS);
}

int irc_channel_left(irc_channel_t *channel, irc_client_t *client)
{
	linkedlist_t *list;
	size_t size = sizeof(irc_client_t);

	if (channel == NULL || client == NULL)
		return (EXIT_FAILURE);
	list = &channel->clients;
	if (linkedlist_remove(list, client, size) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	printf("[-] %s removed from %s\n", client->nickname, channel->name);
	return (EXIT_SUCCESS);
}
