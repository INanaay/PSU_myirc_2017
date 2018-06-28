/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_IRC_PARSER_H
#define PSU_MYIRC_2017_IRC_PARSER_H

#include <stdlib.h>
#include <stdint.h>
#include "entities.h"

typedef void(*irc_packet_handler)(irc_server_t *, irc_client_t *, char **);
int irc_parser_init(irc_parser_t *parser, size_t handler_count);
char **irc_parser_get_packets(const uint8_t *buffer, size_t n);
char **irc_parser_get_tokens(const char *packet);
irc_packet_handler irc_parser_get_handler(irc_parser_t *parser,
					char **tokens);
void irc_parser_destroy(irc_parser_t *parser);

#endif //PSU_MYIRC_2017_IRC_PARSER_H
