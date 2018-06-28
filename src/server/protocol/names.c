/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <string.h>
#include "../../../inc/server/protocol/names.h"
#include "../../../inc/server/entities/entities.h"
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/welcome.h"
#include "../../../inc/server/entities/irc_server.h"

static void empty_names(irc_client_t *client)
{
	int fd = client->tcpclient->sockfd;
	const char *nick = client->nickname;

	dprintf(fd, "%s 366 %s *: End of /NAMES list.\r\n", IRC_SOURCE, nick);
}

static void no_channel_found(irc_client_t *client, const char *target)
{
	int fd = client->tcpclient->sockfd;
	const char *nick = client->nickname;

	dprintf(fd, "%s 401 %s %s :No suck nick/channel\r\n",
		IRC_SOURCE, nick, target);
}

static char *get_channel_names(irc_server_t *server, const char *channel_name)
{
	size_t len = 1;
	char *result = NULL;
	linkedlist_t *list = NULL;
	irc_client_t *client = NULL;
	irc_channel_t *channel = irc_server_get_channel(server, channel_name);

	if (channel == NULL)
		return (NULL);
	list = &channel->clients;
	len = get_clients_nicknames_len(list) + list->length + 1;
	result = calloc(len, 1);
	for (node_t *node = list->begin; node != NULL; node = node->next) {
		client = node->value;
		strcat(result, client->nickname);
		if (node->next != NULL)
			strcat(result, " ");
	}
	return (result);
}

static void channel_names(irc_server_t *server, irc_client_t *client,
			const char *channel)
{
	int fd = client->tcpclient->sockfd;
	const char *nick = client->nickname;
	char *names = get_channel_names(server, channel);

	if (names == NULL)
	{
		no_channel_found(client, channel);
		return;
	}
	dprintf(fd, "%s 353 %s = %s :%s\r\n", IRC_SOURCE, nick, channel, names);
	dprintf(fd, "%s 366 %s %s: End of /NAMES list.\r\n",
		IRC_SOURCE, channel, nick);
	free(names);
}

void names_handler(irc_server_t *server, irc_client_t *client, char **tokens)
{
	char *channel_name = NULL;
	size_t tokenslen = tablen(tokens);

	if (tokenslen == 1)
		empty_names(client);
	channel_name = tokens[1];
	if (channel_name != NULL)
		channel_names(server, client, channel_name);
}
