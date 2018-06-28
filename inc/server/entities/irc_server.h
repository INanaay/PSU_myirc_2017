/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_IRC_H
#define PSU_MYIRC_2017_IRC_H

#include "entities.h"

int irc_server_init(irc_server_t *irc, const char *host, int port);
void irc_server_start(irc_server_t *irc);
void irc_server_destroy(irc_server_t *irc);
irc_client_t *irc_server_find_client(irc_server_t *irc_server, int sockfd);
irc_client_t *irc_server_get_client(irc_server_t *irc_server,
				const char *nickname);
irc_channel_t *irc_server_create_channel(irc_server_t *irc, const char *name,
					const char *subject,
					const char *pwd);
void irc_server_shutdown(irc_server_t *irc);
int irc_server_disconnect_client(irc_server_t *irc, irc_client_t *client);
int irc_server_contains_nickname(irc_server_t *irc, const char *nickname);
irc_channel_t *irc_server_get_channel(irc_server_t *irc_server,
				const char *channel_name);

size_t get_clients_nicknames_len(linkedlist_t *list);

#endif //PSU_MYIRC_2017_IRC_H
