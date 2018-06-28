/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <memory.h>
#include <stdio.h>
#include "../../../inc/server/protocol/message.h"
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/entities/irc_server.h"

static size_t get_message_length(char **tokens)
{
	char *token;
	size_t result = 0;

	for (size_t index = 0; tokens[index] != 0; index++)
	{
		token = tokens[index];
		result += strlen(token) + 1;
	}

	return (result);
}

static char *get_message(char **tokens)
{
	char *token;
	size_t length = get_message_length(tokens);
	char *result = malloc(sizeof(char) * (length + 1));

	if (result == NULL)
		return (NULL);
	memset(result, 0, length + 1);
	for (size_t index = 0; tokens[index] != 0; index++)
	{
		token = tokens[index];
		strcat(result, token);
		strcat(result, " ");
	}
	return (result);
}

static void message_handler_channel(irc_client_t *sender,
				irc_channel_t *channel,
				const char *message)
{
	int fd = -1;
	irc_client_t *receiver;
	const char *host = sender->host;
	const char *user = sender->username;
	const char *snick = sender->nickname;
	linkedlist_t *list;

	if (channel == NULL)
		return ;
	list = &channel->clients;
	for (node_t *node = list->begin; node != NULL; node = node->next)
	{
		receiver = node->value;
		fd = receiver->tcpclient->sockfd;
		dprintf(fd, ":%s!%s@%s PRIVMSG %s :%s\r\n",
		snick, user, host, channel->name, message);
	}
}

static void message_handler_user(irc_client_t *sender,
				irc_client_t *receiver,
				const char *message)
{
	int fd = receiver->tcpclient->sockfd;
	const char *host = sender->host;
	const char *user = sender->username;
	const char *snick = sender->nickname;
	const char *rnick = receiver->nickname;

	dprintf(fd, ":%s!%s@%s PRIVMSG %s :%s\r\n",
	snick, user, host, rnick, message);
}

void message_handler(irc_server_t *server,
		irc_client_t *sender,
		char **tokens)
{
	char *message, *target;
	irc_client_t *receiver;
	irc_channel_t *channel;
	size_t len = tablen(tokens);

	if (len < 3) {
		return;
	}
	target = tokens[1];
	message = get_message(tokens + 2);
	if (str_contains(target, "#")) {
		channel = irc_server_get_channel(server, target);
		message_handler_channel(sender, channel, message);
	}
	else {
		receiver = irc_server_get_client(server, target);
		message_handler_user(sender, receiver, message);
	}
	free(message);
}
