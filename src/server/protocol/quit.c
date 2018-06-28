/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <unistd.h>
#include "../../../inc/server/protocol/quit.h"
#include "../../../inc/server/entities/irc_server.h"

void quit_handler(irc_server_t *irc_server,
		irc_client_t *irc_client, char **tokens)
{
	(void)tokens;
	irc_server_disconnect_client(irc_server, irc_client);
}
