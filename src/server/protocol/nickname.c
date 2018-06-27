/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include "../../../inc/server/protocol/nickname.h"
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/entities/irc_client.h"
#include "../../../inc/server/protocol/welcome.h"

static void nickname_set_handler(irc_client_t *client, char **tokens)
{
	const char *nickname;

	nickname = tokens[1];
	if (nickname == NULL || client->nickname != NULL)
	{
		return;
	}
	client->registering = true;
	client->nickname = strdup(nickname);
}

static void nickname_rename_handler(irc_server_t *irc, irc_client_t *client,
				    char *old_nickname, char *new_nickname)
{
	int contains = irc_server_contains_nickname(irc, old_nickname);
	if (!contains)
	{
		dprintf(client->tcpclient->sockfd,
		"%s 421 %s %s :Unknow command",
		IRC_SOURCE, client->nickname, old_nickname);
		return;
	}
	irc_client_renamed(client, new_nickname);
	if (client->nickname != NULL)
		free(client->nickname);
	client->nickname = strdup(new_nickname);
}

void nickname_handler(irc_server_t *irc, irc_client_t *client, char **tokens)
{
	size_t tokenslen = tablen(tokens);

	if (tokenslen == 2 && client->registering) {
		str_remove(tokens[1], ':');
		nickname_set_handler(client, tokens);
	}
	else if (tokenslen > 2 ||
		(client->registered && tokenslen == 2)) {
		if (tokenslen > 2) {
			str_remove(tokens[2], ':');
			nickname_rename_handler
				(irc, client, tokens[0], tokens[2]);
		}
		else {
			str_remove(tokens[1], ':');
			nickname_rename_handler(irc, client,
						client->nickname, tokens[1]);
		}
	}
}
