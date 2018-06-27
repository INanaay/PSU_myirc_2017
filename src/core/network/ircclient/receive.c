/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <unistd.h>
#include "../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../inc/core/network/ircclient/GUI.hpp"
#include "../../../../inc/core/string/string.h"

void get_server_host(t_client_info *client_info)
{
	char *response;
	int i = 0;

	response = get_server_response(client_info);
	response++;
	while (response[i]) {
		if (response[i] == ' ')
			response[i] = 0;
		i++;
	}
	client_info->host = response;
}

static void handle_privmsg(t_client_info *client, char *msg)
{
	(void)client;
	char **tokens = split_string(msg, " :");
	char *tmp = strdup(msg);

	(void) client;
	tmp[strlen(tmp - 2)] = 0;
	tmp++;
	while (tmp && *tmp !=  ':')
		tmp++;
	tokens[3][strlen(tokens[3]) - 1] = 0;
	if (strstr(msg, "#") != NULL)
		printf("(%s) <%s> %s", tokens[2], tokens[0], tmp);
	else
		printf("%s sent you a private message : %s\n", tokens[2], tmp);

}

static char *read_data(int fd)
{
	char buffer[MAX_COMMAND_LEN + 1];
	int res;

	memset(buffer, 0, MAX_COMMAND_LEN + 1);
	res = read(fd, buffer, MAX_COMMAND_LEN);
	buffer[res] = 0;
	if (strlen(buffer) == 0 || res <= 0)
		return (NULL);
	return (strdup(buffer));

}

char *get_server_response(t_client_info *client)
{
	char *response = read_data(client->sd);

	if (response == NULL)
	{
		printf("Server stopped\n");
		client->connected = NOT_CONNECTED;
		return (NULL);
	}
	else {
		if (strstr(response, "PRIVMSG") != NULL) {
			handle_privmsg(client, response);
		}
		else {
			printf("%s", response);
		}
	}
	return (response);

}
