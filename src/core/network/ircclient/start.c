/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../inc/core/network/ircclient/GUI.hpp"
#include "../../../../inc/core/concurrency/threadpool.h"

void *read_server_thread(void *p_client_info)
{
	t_client_info *client_info = (t_client_info *) p_client_info;

	while (1) {
		if (client_info->connected == CONNECTED) {
			get_server_response(client_info);
		}
	}
	return (NULL);
}

void client_run(t_client_info *client_info)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;

	while (read != -1) {
		read = getline(&line, &len, stdin);
		line[strlen(line) - 1] = 0;
		handle_input(line, client_info);
	}
	free(line);
}

void client_start(t_client_info *client_info)
{
	threadpool_t threadpool;

	threadpool_init(&threadpool, 1);
	init_client_info(client_info);
	threadpool_add_task(&threadpool, &read_server_thread, client_info);
	client_run(client_info);
}