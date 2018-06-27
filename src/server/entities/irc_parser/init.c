/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <memory.h>
#include "../../../../inc/server/protocol/nickname.h"
#include "../../../../inc/server/entities/irc_parser.h"
#include "../../../../inc/server/protocol/user.h"
#include "../../../../inc/server/protocol/ping.h"
#include "../../../../inc/server/protocol/quit.h"
#include "../../../../inc/server/protocol/join.h"
#include "../../../../inc/server/protocol/part.h"
#include "../../../../inc/server/protocol/list.h"
#include "../../../../inc/server/protocol/message.h"
#include "../../../../inc/server/protocol/names.h"

static int irc_parser_add_handler(irc_parser_t *parser, const char *header,
				  irc_packet_handler handler)
{
	key_value_t pair;
	size_t index = parser->index;

	if (index >= parser->handler_count)
		return (EXIT_FAILURE);
	pair.key = header;
	pair.value = handler;
	parser->handlers[index] = pair;
	parser->index += 1;
	return (EXIT_SUCCESS);
}

static int irc_parser_init_handlers(irc_parser_t *parser)
{
	int err = 0;

	err |= irc_parser_add_handler(parser, "USER", user_handler);
	err |= irc_parser_add_handler(parser, "PONG", pong_handler);
	err |= irc_parser_add_handler(parser, "QUIT", quit_handler);
	err |= irc_parser_add_handler(parser, "JOIN", join_handler);
	err |= irc_parser_add_handler(parser, "PART", part_handler);
	err |= irc_parser_add_handler(parser, "LIST", list_handler);
	err |= irc_parser_add_handler(parser, "NICK", nickname_handler);
	err |= irc_parser_add_handler(parser, "NAMES", names_handler);
	err |= irc_parser_add_handler(parser, "PRIVMSG", message_handler);

	return (err != EXIT_SUCCESS ? EXIT_FAILURE : EXIT_SUCCESS);
}

int irc_parser_init(irc_parser_t *parser, size_t handler_count)
{
	parser->index = 0;
	parser->handler_count = handler_count;
	parser->handlers = malloc(sizeof(key_value_t) * handler_count);
	memset(parser->handlers, 0, sizeof(key_value_t) * handler_count);
	if (parser->handlers == NULL)
		return (EXIT_FAILURE);
	if (irc_parser_init_handlers(parser) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
