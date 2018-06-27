/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_number(const char *str)
{
	size_t length = strlen(str);

	for (size_t index = 0; index < length; index++)
	{
		if (isdigit(str[index]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
