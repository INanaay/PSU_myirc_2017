/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_ENTITIES_H
#define PSU_MYIRC_2017_ENTITIES_H

#include "../../core/linkedlist/linkedlist.h"
#include "../../core/network/tcpclient/tcpclient.h"
#include "../../core/network/tcpserver/tcpserver.h"

struct irc_channel_s
{
	char *name;
	char *subject;
	char *password;
	size_t client_count;
	linkedlist_t clients;
	linkedlist_t messages;
};
typedef struct irc_channel_s irc_channel_t;

struct irc_client_s
{
	char *host;
	char *realname;
	char *nickname;
	char *username;
	char *servername;
	char *last_serial_ping;
	bool registered;
	bool registering;

	tcpclient_t *tcpclient;
	linkedlist_t channels;
};
typedef struct irc_client_s irc_client_t;

struct key_value_s
{
	const void *key;
	void *value;
};
typedef struct key_value_s key_value_t;

struct irc_parser_s
{
	size_t index;
	size_t handler_count;
	key_value_t *handlers;
};
typedef struct irc_parser_s irc_parser_t;

struct irc_server_s
{
	char *date;
	tcpserver_t server;
	irc_parser_t parser;
	linkedlist_t members;
	linkedlist_t channels;
};

typedef struct irc_server_s irc_server_t;
#endif //PSU_MYIRC_2017_ENTITIES_H
