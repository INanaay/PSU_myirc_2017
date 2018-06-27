/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_IRC_CLIENT_H
#define PSU_MYIRC_2017_IRC_CLIENT_H

#include "entities.h"

int irc_client_init(irc_client_t *client, tcpclient_t *tcpclient);
void irc_client_destroy(irc_client_t *client);
void irc_client_renamed(irc_client_t *irc_client, const char *nickname);

#endif //PSU_MYIRC_2017_IRC_CLIENT_H
