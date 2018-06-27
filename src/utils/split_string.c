/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include "../../inc/core/network/ircclient/ircclient.hpp"

char **split_string(char *line, char *tokens)
{
	char *str = strdup(line);
	char **res = NULL;
	char *p = strtok(str, tokens);
	int n_spaces = 0;

	while (p) {
		res = realloc(res, sizeof(char *) * ++n_spaces);
		if (res == NULL)
			exit(84);
		res[n_spaces - 1] = p;
		p = strtok(NULL, tokens);
	}
	res = realloc(res, sizeof(char *) * (n_spaces + 1));
	res[n_spaces] = 0;
	return (res);
}
