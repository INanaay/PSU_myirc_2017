/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdlib.h>

size_t count_occurences(const char *buffer, char delim)
{
	size_t occurences = 0;

	for (size_t index = 0; buffer[index] != 0; index++)
	{
		if (buffer[index] == delim)
			occurences += 1;
	}
	return (occurences);
}
