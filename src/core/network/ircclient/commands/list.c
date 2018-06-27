/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include "../../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../../inc/utils/Utils.hpp"

void list_command(char **command, t_client_info *client_info)
{
	int nb_tokens = get_double_array_size(command);

	if (client_info->connected == NOT_CONNECTED)
	{
		printf("Not Connected to any server.\n");
		return;
	}
	if (nb_tokens == 1)
	{
		dprintf(client_info->sd, "LIST\r\n");
	}
	else if (nb_tokens == 2)
	{
		dprintf(client_info->sd, "LIST #%s\r\n", command[1]);
	}
}
