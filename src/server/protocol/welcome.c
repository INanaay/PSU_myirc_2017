/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <unistd.h>
#include "../../../inc/server/protocol/welcome.h"
#include "../../../inc/server/entities/entities.h"

void welcome_packet(irc_server_t *irc_server, irc_client_t *irc_client)
{
	int sockfd = irc_client->tcpclient->sockfd;
	const char *nickname = irc_client->nickname;
	const char *username = irc_client->username;

	dprintf(sockfd, ":%s :%s\r\n", IRC_SOURCE, WELCOME_PACKET);
	usleep(1000);
	dprintf(sockfd, ":%s 001 %s :%s@%s\r\n", IRC_SOURCE, nickname, username,
		irc_client->tcpclient->ip);
	usleep(1000);
	dprintf(sockfd, ":%s 002 %s :Your host is %s\r\n", IRC_SOURCE, nickname,
		IRC_SOURCE);
	usleep(1000);
	dprintf(sockfd, ":%s 003 %s :This server was created %s.\r\n",
		IRC_SOURCE, nickname, irc_server->date);
}
