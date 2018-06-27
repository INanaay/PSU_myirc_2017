/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>
#include <stdlib.h>
#include "../../../inc/core/string/string.h"

char **strsplit(const char *buffer, const char *delim)
{
	size_t index = 0;
	char *token = NULL;
	char *copy = strdup(buffer);
	char *copy2 = copy;
	size_t token_count = count_occurences(buffer, *delim);
	char **result = malloc(sizeof(char *) * (token_count + 2));

	if (result == NULL)
	{
		free(copy);
		return (NULL);
	}
	for (index = 0; (token = strsep(&copy, delim)) != NULL; index++)
		result[index] = strdup(token);
	result[index] = NULL;
	free(copy2);
	return (result);
}
