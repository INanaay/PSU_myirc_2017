/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include "../../../../inc/core/network/tcpclient/tcpclient.h"
#include "../../../../inc/core/network/tcpserver/tcpserver.h"

tcpclient_t *tcpserver_find_client(tcpserver_t *server, int clientfd)
{
	tcpclient_t *client;
	linkedlist_t *clients = &server->clients;

	for (node_t *node = clients->begin; node != NULL; node = node->next)
	{
		client = node->value;
		if (client->sockfd == clientfd)
			return (client);
	}
	return (NULL);
}