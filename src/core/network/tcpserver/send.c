/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <unistd.h>
#include <stdint.h>
#include "../../../../inc/core/network/tcpserver/tcpserver.h"

void tcpserver_sendAll(tcpserver_t *server, const uint8_t *buffer, size_t n)
{
	int sockfd;
	node_t *node;

	if (server == NULL || buffer == NULL)
		return;
	for (node = server->clients.begin; node != NULL; node = node->next)
	{
		sockfd = *((int *)(node->value));
		write(sockfd, buffer, n);
	}
}
