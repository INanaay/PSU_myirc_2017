/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/join.h"
#include "../../../inc/server/entities/entities.h"
#include "../../../inc/server/entities/irc_server.h"
#include "../../../inc/server/entities/irc_channel.h"
#include "../../../inc/server/protocol/names.h"

static char **get_names_tokens(const char *channel)
{
	char **tokens = malloc(sizeof(char *) * 3);

	tokens[0] = strdup("NAMES");
	tokens[1] = strdup(channel);
	tokens[2] = NULL;
	return (tokens);
}

static void on_client_joined(irc_channel_t *channel, irc_client_t *irc_client)
{
	irc_client_t *client;
	linkedlist_t *clients;

	if (channel->clients.length == 0)
		return;
	clients = &channel->clients;
	for (node_t *node = clients->begin; node != NULL; node = node->next)
	{
		client = node->value;
		dprintf(client->tcpclient->sockfd, ":%s!%s@%s JOIN %s\r\n",
		irc_client->nickname, irc_client->username,
		irc_client->host, channel->name);
	}
}

static irc_channel_t *create_channel(irc_server_t *server,
				     const char *channel_name)
{
	return (irc_server_create_channel(server, channel_name, NULL, NULL));
}

void join_handler(irc_server_t *irc_server, irc_client_t *client,
		  char **tokens)
{
	char **names_tokens;
	irc_channel_t *channel;
	const char *channel_name;

	if (tablen(tokens) < 2) {
		return;
	}
	channel_name = tokens[1];
	channel = irc_server_get_channel(irc_server, channel_name);
	if (channel == NULL)
		channel = create_channel(irc_server, channel_name);
	if (channel == NULL) {
		return;
	}
	irc_channel_join(channel, client);
	on_client_joined(channel, client);
	names_tokens = get_names_tokens(channel_name);
	names_handler(irc_server, client, names_tokens);
	free_strtab(names_tokens);
}
