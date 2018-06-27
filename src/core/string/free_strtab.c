/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>
#include <stdlib.h>

void free_strtab(char **tab)
{
	if (tab == NULL)
		return;
	for (size_t index = 0; tab[index] != NULL; index++)
		free(tab[index]);
	free(tab);
}