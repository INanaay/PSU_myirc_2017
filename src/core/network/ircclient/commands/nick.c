/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <unistd.h>
#include "../../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../../inc/utils/Utils.hpp"
#include "../../../../../inc/core/network/ircclient/GUI.hpp"
#include "../../../../../inc/core/string/string.h"

static void move_to_ping(char *ping)
{
	while (ping[0] != 'P' && ping[1] != 'I' && ping[2] != 'N'
		&& ping[3] != 'G')
		ping++;
}

void send_pong(char *ping, t_client_info *client)
{
	int i, j;
	char pong[25];

	i = 0;
	j = 0;

	move_to_ping(ping);
	while (ping[i] && ping[i] != ':')
		i++;
	i++;
	while (ping[i] && ping[i] != ' ' && ping[i] != '\t') {
		pong[j] = ping[i];
		i++;
		j++;
	}
	pong[j] = 0;
	printf("PONG %s\n", pong);
	dprintf(client->sd, "PONG %s\r\n", pong);
}

static void connect_first_time(t_client_info *client, char **command)
{
	int sd = client->sd;
	char *response;

	dprintf(sd, "NICK %s\r\n", command[1]);

	dprintf(sd, "USER anon anon anon :%s\r\n", command[1]);
	client->nickname = command[1];
	do {
		response = get_server_response(client);
		if (strstr(response, "433") != NULL)
			return;
	}
	while (strstr(response, "PING") == NULL);
	send_pong(response, client);
	get_server_host(client);
	client->connected = CONNECTED;
}

static void change_nickname(char **command, t_client_info *client_info)
{
	dprintf(client_info->sd, "NICK %s\r\n", command[1]);
	client_info->nickname = command[1];
}

void nick_command(char **command, t_client_info *client_info)
{
	int nb_tokens = get_double_array_size(command);

	if (client_info->connected == NOT_CONNECTED)
	{
		printf("Not Connected to any server.\n");
		return;
	}
	if (nb_tokens == 2) {
		if (client_info->connected == NO_LOGIN)
			connect_first_time(client_info, command);
		else if (client_info->connected == CONNECTED)
			change_nickname(command, client_info);

	}
}
