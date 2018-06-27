/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <unistd.h>
#include <sys/stat.h>
#include "../../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../../inc/utils/Utils.hpp"

static void send_private_msg_command(char *msg, char *user,
					t_client_info *client_info)
{
	int nb_spaces = 0;

	while (nb_spaces != 2)
	{
		if (*msg == ' ')
			nb_spaces++;
		msg++;
	}
	printf("PRIVMSG %s [%s]\r\n", user, msg);
	dprintf(client_info->sd, "PRIVMSG %s :%s\r\n", user, msg);
}

static void send_file_command(char **command, t_client_info *client_info)
{
	struct stat file_stats;

	if (stat(command[3], &file_stats) == -1)
		printf("could not access file.\n");
	else
	{
		send_file(command[3], client_info, file_stats.st_size, command);
	}
}

void msg_to_channel_command(char *msg, t_client_info *client_info)
{

	if (client_info->channels_list.length == 0 ||
		client_info->current_channel == NULL)
	{
		printf("Not connected to any channel.\n");
		return;
	}
	dprintf(client_info->sd, "PRIVMSG #%s :%s\r\n",
		client_info->current_channel, msg);

}

void msg_command(char **command, char *msg, t_client_info *client_info)
{
	int nb_tokens = get_double_array_size(command);

	if (client_info->connected == NOT_CONNECTED) {
		printf("Not Connected to any server.\n");
		return;
	}
	if (nb_tokens == 4)
	{
		for (node_t *node = client_info->channels_list.begin;
				node != NULL; node = node->next)
		{
			if (strcmp(command[1], node->value) == 0) {
				send_file_command(command, client_info);
				return;
			}
		}

	}
	if (nb_tokens >= 3)
		send_private_msg_command(msg, command[1], client_info);
}
