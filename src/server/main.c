/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <signal.h>
#include "../../inc/core/network/tcpserver/tcpserver.h"
#include "../../inc/server/entities/irc_server.h"

bool interrupted = false;

void signal_handler(int signum)
{
	(void)signum;
	interrupted = true;
}

int main(int ac, char **argv)
{
	irc_server_t server;

	if (ac < 2)
		return (84);
	signal(SIGINT, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGTERM, signal_handler);
	irc_server_init(&server, "127.0.0.1", atoi(argv[1]));
	irc_server_start(&server);
	irc_server_destroy(&server);
}
