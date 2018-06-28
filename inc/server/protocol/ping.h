/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_PING_H
#define PSU_MYIRC_2017_PING_H

#include "../entities/entities.h"

#define PING_SERIAL_LENGTH (5 + 0)
#define PONG_PACKET_INFORMATIONS_COUNT (1 + 0)

void ping_packet(irc_client_t *irc_client);
void pong_handler(irc_server_t *server, irc_client_t *irc_client,
		char **tokens);

#endif //PSU_MYIRC_2017_PING_H
