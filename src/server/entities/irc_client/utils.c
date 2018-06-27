/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include "../../../../inc/server/entities/entities.h"

static void send_rename_to_all_clients(irc_client_t *irc_client,
				       irc_channel_t *channel,
				       const char *nickname)
{
	int fd;
	irc_client_t *client = NULL;
	linkedlist_t *clients = &channel->clients;

	if (clients->length == 0)
		return ;
	for (node_t *node = clients->begin; node != NULL; node = node->next)
	{
		client = node->value;
		fd = client->tcpclient->sockfd;
		if (strcmp(irc_client->nickname, client->nickname) == 0)
			continue ;
		dprintf(fd, ":%s!%s@%s NICK %s\r\n",
			irc_client->nickname, irc_client->username,
			irc_client->host, nickname);
	}
}

void irc_client_renamed(irc_client_t *irc_client, const char *nickname)
{
	irc_channel_t *channel = NULL;
	linkedlist_t *channels = &irc_client->channels;

	dprintf(irc_client->tcpclient->sockfd,
		":%s!%s@%s NICK %s\r\n",
		irc_client->nickname, irc_client->username,
		irc_client->host, nickname);
	if (channels->length == 0)
		return;
	for (node_t *node = channels->begin; node != NULL; node = node->next)
	{
		channel = node->value;
		if (channel->clients.length == 0)
			continue ;
		send_rename_to_all_clients(irc_client, channel, nickname);
	}
}