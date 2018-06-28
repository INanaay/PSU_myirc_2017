/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/part.h"
#include "../../../inc/server/entities/irc_server.h"
#include "../../../inc/server/entities/irc_channel.h"

static void on_client_left(irc_client_t *irc_client,
			irc_channel_t *channel)
{
	irc_client_t *client;
	linkedlist_t *clients;

	if (channel->clients.length == 0)
		return;
	clients = &channel->clients;
	for (node_t *node = clients->begin; node != NULL; node = node->next)
	{
		client = node->value;
		dprintf(client->tcpclient->sockfd, ":%s!%s@%s PART :%s\r\n",
			irc_client->nickname, irc_client->username,
			irc_client->host, channel->name);
	}
}

void part_handler(irc_server_t *irc_server,
		irc_client_t *irc_client, char **tokens)
{
	irc_channel_t *channel;
	const char *channel_name;
	size_t len = tablen(tokens);

	if (len < 2)
	{
		return;
	}
	channel_name = tokens[1];
	channel = irc_server_get_channel(irc_server, channel_name);
	if (channel == NULL)
	{
		return;
	}
	on_client_left(irc_client, channel);
	irc_channel_left(channel, irc_client);
}
