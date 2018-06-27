/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>

size_t tablen(char **tab)
{
	size_t len = 0;

	while (tab[len] != NULL)
		len++;
	return (len);
}
