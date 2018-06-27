/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include "../../../inc/core/string/string.h"
#include "../../../inc/server/protocol/ping.h"
#include "../../../inc/server/protocol/welcome.h"

static char *generate_serial(void)
{
	int random = rand() % (99999);
	char *serial = malloc(sizeof(char) * (PING_SERIAL_LENGTH + 1));

	if (serial == NULL)
		return (NULL);
	sprintf(serial, "%05d", random);
	return (serial);
}

void ping_packet(irc_client_t *irc_client)
{
	char *serial = generate_serial();

	if (irc_client->last_serial_ping != NULL)
		free(irc_client->last_serial_ping);
	irc_client->last_serial_ping = serial;
	dprintf(irc_client->tcpclient->sockfd, "PING :%s\r\n", serial);
}

void pong_handler(irc_server_t *irc_server,
		  irc_client_t *irc_client, char **tokens)
{
	const char *serial;

	if (tablen(tokens) < PONG_PACKET_INFORMATIONS_COUNT + 1)
	{
		return;
	}
	serial = tokens[1];
	if (strcmp(serial, irc_client->last_serial_ping) != 0)
	{
		printf("wrong pong response.\n");
		return;
	}
	if (irc_client->registering)
	{
		irc_client->registered = true;
		irc_client->registering = false;
		welcome_packet(irc_server, irc_client);
	}
}
