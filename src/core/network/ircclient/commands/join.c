/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include "../../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../../inc/utils/Utils.hpp"

static void join_channel(char **command, t_client_info *client_info)
{
	dprintf(client_info->sd, "JOIN #%s\r\n", command[1]);

	linkedlist_append(&client_info->channels_list, command[1]);
	client_info->current_channel = command[1];
}

void join_command(char **command, t_client_info *client_info)
{
	int nb_tokens = get_double_array_size(command);

	if (client_info->connected == NOT_CONNECTED)
	{
		printf("Not Connected to any server.\n");
		return;
	}
	if (nb_tokens == 2)
	{
		join_channel(command, client_info);
	}
	else
		printf("Missing parameter.\n");
}
