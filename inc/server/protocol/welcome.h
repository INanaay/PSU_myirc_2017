/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_WELCOME_H
#define PSU_MYIRC_2017_WELCOME_H

#include "../entities/entities.h"

#define IRC_SOURCE "irc.nana-lebovin.com"
#define WELCOME_PACKET "NOTICE Auth :Welcome to myIRC!"

void welcome_packet(irc_server_t *irc_server, irc_client_t *irc_client);

#endif //PSU_MYIRC_2017_WELCOME_H
