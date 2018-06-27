/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>

int str_contains(const char *str, const char *request)
{
	size_t current_len = 0;
	size_t str_len = strlen(str);
	size_t req_len = strlen(request);

	if (req_len > str_len)
		return (0);
	for (size_t it = 0; it < str_len; it++)
	{
		current_len = str_len - it;
		if (current_len < req_len)
			return (0);
		if (strncmp(str, request, req_len) == 0)
			return (1);
	}
	return (0);
}