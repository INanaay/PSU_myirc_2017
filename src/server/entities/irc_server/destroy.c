/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include "../../../../inc/server/entities/irc_server.h"
#include "../../../../inc/server/entities/irc_channel.h"
#include "../../../../inc/server/entities/irc_parser.h"
#include "../../../../inc/server/entities/irc_client.h"

static void irc_server_destroy_members(irc_server_t *irc)
{
	irc_client_t *client;
	linkedlist_t *members = &irc->members;

	for (node_t *node = members->begin; node != NULL; node = node->next)
	{
		client = node->value;
		irc_client_destroy(client);
		free(node->value);
	}
	linkedlist_destroy(members);
}

static void irc_server_destroy_channels(irc_server_t *irc)
{
	irc_channel_t *channel;
	linkedlist_t *channels = &irc->channels;

	for (node_t *node = channels->begin; node != NULL; node = node->next)
	{
		channel = node->value;
		irc_channel_destroy(channel);
		free(node->value);
	}
	linkedlist_destroy(channels);
}

void irc_server_destroy(irc_server_t *irc)
{
	if (irc == NULL)
		return;
	if (irc->date != NULL)
		free(irc->date);
	tcpserver_destroy(&irc->server);
	irc_server_destroy_members(irc);
	irc_server_destroy_channels(irc);
	irc_parser_destroy(&irc->parser);
	printf("[-] irc server stopped.\n");
}