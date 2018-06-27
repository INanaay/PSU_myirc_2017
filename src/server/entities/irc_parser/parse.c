/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdio.h>
#include <memory.h>
#include "../../../../inc/core/string/string.h"
#include "../../../../inc/server/entities/irc_parser.h"

char **irc_parser_get_packets(const uint8_t *buffer, size_t n)
{
	char **result = NULL;
	char *plain_text = malloc(n + 1);

	if (plain_text == NULL)
		return (NULL);
	strncpy(plain_text, (const char *)buffer, n);
	plain_text[n] = 0;
	str_trim(plain_text);
	result = strsplit(plain_text, "\r\n");
	free(plain_text);
	return (result);
}

char **irc_parser_get_tokens(const char *packet)
{
	char **tokens = NULL;

	tokens = strsplit(packet, " ");
	return (tokens);
}

irc_packet_handler irc_parser_get_handler(irc_parser_t *parser, char **tokens)
{
	const char *token = NULL;
	const char *header = NULL;

	for (size_t it = 0; tokens[it] != NULL; it++)
	{
		token = tokens[it];
		for (size_t index = 0; index < parser->handler_count - 1;
			index++)
		{
			header = parser->handlers[index].key;
			if (strcmp(header, token) == 0)
				return (parser->handlers[index].value);
		}
	}
	return (NULL);
}
