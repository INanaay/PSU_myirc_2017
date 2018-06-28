/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_JOIN_H
#define PSU_MYIRC_2017_JOIN_H

#include "../entities/entities.h"

void join_handler(irc_server_t *irc_server, irc_client_t *client,
			char **tokens);

#endif //PSU_MYIRC_2017_JOIN_H
