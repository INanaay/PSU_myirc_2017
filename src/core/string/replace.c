/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>

void str_replace(char *str, char to_replace, char c)
{
	for (size_t index = 0; str[index] != 0; index++)
		if (str[index] == to_replace)
			str[index] = c;
}
