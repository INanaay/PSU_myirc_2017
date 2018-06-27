/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/list.h"
#include "../../../inc/server/protocol/welcome.h"

static void list_all_channels(irc_server_t *irc_server,
			      irc_client_t *irc_client)
{
	size_t count = 0;
	irc_channel_t *channel;
	int fd = irc_client->tcpclient->sockfd;
	const char *nick = irc_client->nickname;
	linkedlist_t *channels = &irc_server->channels;

	dprintf(fd, ":%s 321 %s Channel :Users Name\r\n",
		IRC_SOURCE, irc_client->nickname);
	for (node_t *node = channels->begin; node != NULL; node = node->next)
	{
		channel = node->value;
		count = channel->clients.length;
		dprintf(fd, ":%s 322 %s %s %ld : [+nrt] %s\r\n", IRC_SOURCE,
			nick, channel->name, count, channel->subject);
	}
	dprintf(fd, ":%s 323 %s :End of channel list.\r\n", IRC_SOURCE, nick);
}

void list_handler(irc_server_t *irc, irc_client_t *client, char **tokens)
{
	size_t len = tablen(tokens);

	if (len == 1)
	{
		list_all_channels(irc, client);
	}
}
