/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <printf.h>
#include <string.h>
#include <stdlib.h>
#include "../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../inc/utils/Utils.hpp"

const t_commands commands_array_g[NB_COMMANDS] = {{"/server", &try_connect},
						{"/nick", &nick_command},
						{"/list", &list_command},
						{"/join", &join_command},
						{"/part", &part_command},
						{"/users", &users_command},
						{"/names", &names_command}};

void try_connect(char **command, t_client_info *client_info)
{
	char **infos;
	int size = 0;

	if (command[1] == NULL)
	{
		return;
	}
	infos = split_string(command[1], ":");

	while (infos[size])
		size++;
	if (size == 1) {
		connect_to_server(infos[0], DEFAULT_PORT, client_info);
	}
	else {
		connect_to_server(infos[0], atoi(infos[1]), client_info);
	}
	free(infos);
}

static void handle_commmand(char *input, t_client_info *client_info)
{
	char **command = split_string(input, " \n");
	int i;

	if (strcasecmp(command[0], "/MSG") == 0) {
		msg_command(command, input, client_info);
		return;
	}
	for (i = 0; i < NB_COMMANDS; i++) {
		if (strcasecmp(command[0], commands_array_g[i].command) == 0) {
			commands_array_g[i].fptr(command, client_info);
			break;
		}
	}
}

void handle_input(char *input, t_client_info *client_info)
{
	if (input[0] == '/')
	{
		handle_commmand(input, client_info);
	}
	else
	{
		msg_to_channel_command(input, client_info);
	}
}
