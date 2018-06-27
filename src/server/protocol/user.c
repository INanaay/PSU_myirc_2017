/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <memory.h>
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/user.h"
#include "../../../inc/server/entities/entities.h"
#include "../../../inc/server/protocol/ping.h"

static bool is_well_formated(char **tokens)
{
	const char *header;
	const char *realname;
	size_t tlength = tablen(tokens);

	if (tlength < USER_PACKET_INFORMATIONS_COUNT + 1)
		return (false);
	header = tokens[0];
	if (strcmp(header, USER_PACKET_HEADER) != 0)
		return (false);
	realname = tokens[4];
	if (!str_contains(realname, ":"))
		return (false);
	return (true);
}

void user_handler(irc_server_t *irc, irc_client_t *client, char **tokens)
{
	(void)irc;
	if (!is_well_formated(tokens))
	{
		return;
	}
	client->registering = true;
	client->username = strdup(tokens[1]);
	client->host = strdup(tokens[2]);
	client->servername = strdup(tokens[3]);
	client->realname = strdup(tokens[4]);
	ping_packet(client);
}
