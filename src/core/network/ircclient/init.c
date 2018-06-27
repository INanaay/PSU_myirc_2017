/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include <arpa/inet.h>
#include <netdb.h>
#include "../../../../inc/core/network/ircclient/ircclient.hpp"
#include "../../../../inc/core/network/ircclient/GUI.hpp"

void init_client_info(t_client_info *client_info)
{
	linkedlist_init(&client_info->channels_list);
	client_info->nickname = NULL;
	client_info->host = NULL;
	client_info->current_channel = NULL;
	client_info->connected = NOT_CONNECTED;
	memset(client_info->input, 0, 2048);
}

void connect_to_server(char *ip, int port, t_client_info *client_info)
{
	struct sockaddr_in addr;
	struct hostent *he = gethostbyname(ip);
	char *new_ip;
	struct in_addr **addr_list;

	if (he == NULL)
		return;
	addr_list = (struct in_addr **) he->h_addr_list;
	new_ip = inet_ntoa(*addr_list[0]);
	client_info->sd = socket(PF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(inet_network(new_ip));
	addr.sin_port = htons(port);
	if (connect(client_info->sd, (struct sockaddr *) &addr,
			sizeof(addr)) < 0)
		return;
	printf("Connection successful.\n");
	client_info->connected = NO_LOGIN;
}
