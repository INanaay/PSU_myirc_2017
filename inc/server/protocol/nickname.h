/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_NICKNAME_H
#define PSU_MYIRC_2017_NICKNAME_H

#include <stdint.h>
#include "../entities/irc_server.h"

# define NICKNAME_ERROR "ERR_NONICKNAMEGIVEN"
# define NICKNAME_COLLISION "ERR_NICKCOLLISION"

void nickname_handler(irc_server_t *irc, irc_client_t *irc_client,
		      char **tokens);

#endif //PSU_MYIRC_2017_NICKNAME_H
