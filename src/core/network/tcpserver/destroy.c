/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <unistd.h>
#include "../../../../inc/core/network/tcpserver/tcpserver.h"

static void tcpserver_destroy_clients(linkedlist_t *clients)
{
	tcpclient_t *client;

	for (node_t *node = clients->begin; node != NULL; node = node->next)
	{
		client = node->value;
		tcpclient_destroy(client);
		free(client);
	}
	linkedlist_destroy(clients);
}

void tcpserver_destroy(tcpserver_t *server)
{
	if (server == NULL)
		return;
	server->connected = 0;
	tcpserver_destroy_clients(&server->clients);
	if (server->epoll_fd != -1)
		close(server->epoll_fd);
	if (server->epoll_events != NULL)
		free(server->epoll_events);
	if (server->sockfd != -1)
		close(server->sockfd);
}