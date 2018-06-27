/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include "../../../../inc/server/entities/irc_parser.h"

void irc_parser_destroy(irc_parser_t *parser)
{
	if (parser->handlers != NULL)
		free(parser->handlers);
}