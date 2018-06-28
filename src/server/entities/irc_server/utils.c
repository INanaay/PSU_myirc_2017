/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "../../../../inc/server/entities/irc_server.h"
#include "../../../../inc/server/entities/irc_client.h"

irc_client_t *irc_server_find_client(irc_server_t *irc, int sockfd)
{
	irc_client_t *irc_client;
	linkedlist_t *list = &irc->members;

	for (node_t *node = list->begin; node != NULL; node = node->next)
	{
		irc_client = node->value;
		if (irc_client->tcpclient->sockfd == sockfd)
			return (irc_client);
	}
	return (NULL);
}

irc_client_t *irc_server_get_client(irc_server_t *irc, const char *nickname)
{
	irc_client_t *irc_client;
	linkedlist_t *list = &irc->members;

	for (node_t *node = list->begin; node != NULL; node = node->next)
	{
		irc_client = node->value;
		if (strcmp(irc_client->nickname, nickname) == 0)
			return (irc_client);
	}
	return (NULL);
}

int irc_server_contains_nickname(irc_server_t *irc, const char *nickname)
{
	irc_client_t *client;
	linkedlist_t *list = &irc->members;

	for (node_t *node = list->begin; node != NULL; node = node->next)
	{
		client = node->value;
		if (strcmp(nickname, client->nickname) == 0)
			return (1);
	}
	return (0);
}

int irc_server_disconnect_client(irc_server_t *irc, irc_client_t *client)
{
	linkedlist_t *clients;
	irc_channel_t *channel;
	linkedlist_t *channels = &client->channels;

	tcpclient_destroy(client->tcpclient);
	irc_client_destroy(client);
	linkedlist_remove(&irc->members, client, sizeof(irc_client_t));
	for (node_t *node = channels->begin; node != NULL; node = node->next)
	{
		channel = node->value;
		clients = &channel->clients;
		linkedlist_remove(clients, client, sizeof(irc_client_t));
	}
	linkedlist_destroy(channels);
	tcpclient_destroy(client->tcpclient);

	printf("[-] client disconnected.\n");
	printf("[-] remaining client on the server: %ld\n",
		irc->members.length);
	return (EXIT_SUCCESS);
}

irc_channel_t *irc_server_get_channel(irc_server_t *irc_server,
				const char *channel_name)
{
	irc_channel_t *channel;
	linkedlist_t *channels = &irc_server->channels;

	for (node_t *node = channels->begin; node != NULL; node = node->next)
	{
		channel = node->value;
		if (strcmp(channel->name, channel_name) == 0)
			return (channel);
	}
	return (NULL);
}
