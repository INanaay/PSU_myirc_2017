/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include "../../../../inc/server/entities/irc_server.h"
#include "../../../../inc/server/entities/irc_parser.h"
#include "../../../../inc/core/string/string.h"
#include "../../../../inc/server/entities/irc_client.h"

static void on_client_disconnected(void *p_irc_server, tcpclient_t *tcpclient)
{
	int sockfd = tcpclient->sockfd;
	irc_server_t *irc_server = p_irc_server;
	irc_client_t *irc_client = irc_server_find_client(irc_server, sockfd);

	if (irc_client == NULL)
		return;
	irc_server_disconnect_client(irc_server, irc_client);
	free(irc_client);
}

static void on_message_received(void *p_irc_server, tcpclient_t *tcpclient,
				const uint8_t *buffer, size_t n)
{
	char **tokens = NULL;
	int sockfd = tcpclient->sockfd;
	irc_packet_handler handler = NULL;
	irc_server_t *server = p_irc_server;
	irc_client_t *client = irc_server_find_client(server, sockfd);
	char **packets = irc_parser_get_packets(buffer, n);

	for (size_t index = 0; packets[index] != NULL; index++)
	{
		str_trim(packets[index]);
		tokens = irc_parser_get_tokens(packets[index]);
		handler = irc_parser_get_handler(&server->parser, tokens);
		if (handler != NULL)
			handler(server, client, tokens);
		free_strtab(tokens);
	}
	free_strtab(packets);
}

static void on_connection_accepted(void *p_irc_server, tcpclient_t *tcpclient)
{
	irc_server_t *irc_server = p_irc_server;
	irc_client_t *irc_client = malloc(sizeof(irc_client_t));

	if (irc_client_init(irc_client, tcpclient) != EXIT_SUCCESS)
	{
		free(irc_client);
		return;
	}
	linkedlist_append(&irc_server->members, irc_client);

	printf("[+] irc client joined the server\n");
	printf("[+] now, there is: %ld clients on the server.\n",
		irc_server->members.length);
}

void irc_server_shutdown(irc_server_t *irc)
{
	irc->server.connected = false;
}

void irc_server_start(irc_server_t *irc)
{
	printf("[+] irc server started.\n");
	tcpserver_start(&irc->server,
			&on_connection_accepted,
			&on_message_received,
			&on_client_disconnected);
}
