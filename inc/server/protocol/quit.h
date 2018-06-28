/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_QUIT_H
#define PSU_MYIRC_2017_QUIT_H

#include "../entities/entities.h"

void quit_handler(irc_server_t *irc_server,
		irc_client_t *irc_client, char **tokens);

#endif //PSU_MYIRC_2017_QUIT_H
