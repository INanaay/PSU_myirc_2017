/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <memory.h>

void str_remove(char *str, char c)
{
	size_t writer = 0;
	size_t len = strlen(str);

	for (size_t reader = 0; reader < len; reader++)
	{
		if (str[reader] != c)
		{
			str[writer] = str[reader];
			writer++;
		}
	}
	str[writer] = 0;
}