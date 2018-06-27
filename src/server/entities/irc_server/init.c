/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include <time.h>
#include "../../../../inc/server/entities/irc_server.h"
#include "../../../../inc/server/entities/irc_parser.h"
#include "../../../../inc/server/entities/irc_channel.h"

static int irc_server_init_tcpserver(irc_server_t *irc,
				     const char *host, int port)
{
	tcpserver_informations_t informations;

	informations.port = port;
	informations.host = host;
	informations.capacity = 100;
	informations.ip_type = AF_INET;
	informations.protocol_type = SOCK_STREAM;
	return (tcpserver_init(&irc->server, irc, &informations));
}

static int irc_server_init_date(irc_server_t *irc_server)
{
	char tmp[512] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	sprintf(tmp, "%02d/%02d/%04d %02d:%02d:%02d",
		tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
		tm.tm_hour, tm.tm_min, tm.tm_sec);
	irc_server->date = strdup(tmp);
	if (irc_server->date == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int irc_server_init(irc_server_t *irc, const char *host, int port)
{
	if (irc == NULL)
		return (EXIT_FAILURE);
	memset(irc, 0, sizeof(irc_server_t));
	if (linkedlist_init(&irc->members) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (linkedlist_init(&irc->channels) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (irc_server_init_date(irc) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (irc_parser_init(&irc->parser, 10) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (irc_server_init_tcpserver(irc, host, port) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
