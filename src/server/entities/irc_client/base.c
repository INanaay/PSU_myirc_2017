/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <memory.h>
#include "../../../../inc/server/entities/entities.h"
#include "../../../../inc/core/network/tcpclient/tcpclient.h"

int irc_client_init(irc_client_t *irc_client, tcpclient_t *tcpclient)
{
	memset(irc_client, 0, sizeof(irc_client_t));
	if (irc_client == NULL || tcpclient == NULL)
		return (EXIT_FAILURE);
	if (linkedlist_init(&irc_client->channels) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	irc_client->registering = 1;
	irc_client->tcpclient = tcpclient;
	return (EXIT_SUCCESS);
}

void irc_client_destroy(irc_client_t *client)
{
	if (client->host != NULL)
		free(client->host);
	if (client->nickname != NULL)
		free(client->nickname);
	if (client->realname != NULL)
		free(client->realname);
	if (client->username != NULL)
		free(client->username);
	if (client->servername != NULL)
		free(client->servername);
	if (client->last_serial_ping != NULL)
		free(client->last_serial_ping);
	client->registered = 0;
	linkedlist_destroy(&client->channels);
}