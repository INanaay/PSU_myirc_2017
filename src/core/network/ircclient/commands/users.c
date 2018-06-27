/*
** EPITECH PROJECT, 2018
** users
** File description:
** users
*/

#include "../../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../../inc/utils/Utils.hpp"

void users_command(char **command, t_client_info *client_info)
{
	int nb_tokens = get_double_array_size(command);

	if (client_info->connected == NOT_CONNECTED)
	{
		printf("Not Connected to any server.\n");
		return;
	}
	if (nb_tokens == 1)
	{
		dprintf(client_info->sd, "USERS %s\r\n", client_info->host);
	}
}
