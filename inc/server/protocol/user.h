/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_USER_H
#define PSU_MYIRC_2017_USER_H

#include "../entities/entities.h"

#define USER_PACKET_HEADER "USER"
#define USER_PACKET_INFORMATIONS_COUNT (4 + 0)

void user_handler(irc_server_t *irc, irc_client_t *client, char **tokens);

#endif //PSU_MYIRC_2017_USER_H
