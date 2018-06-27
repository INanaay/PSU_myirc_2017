/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>
#include <stdlib.h>

char *get_lowercase_string(const char *str)
{
	size_t index = 0;
	size_t len = strlen(str);
	const char min_to_maj = 'a' - 'A';
	char *ret = malloc(sizeof(char) * (len + 1));

	if (ret == NULL)
		return (NULL);
	while (index < len)
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			ret[index] = str[index] + min_to_maj;
		else
			ret[index] = str[index];
		index += 1;
	}
	ret[index] = 0;
	return (ret);
}

char *get_uppercase_string(const char *str)
{
	size_t index = 0;
	size_t len = strlen(str);
	const char min_to_maj = 'a' - 'A';
	char *ret = malloc(sizeof(char) * (len + 1));

	if (ret == NULL)
		return (NULL);
	while (index < len)
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			ret[index] = str[index] - min_to_maj;
		else
			ret[index] = str[index];
		index += 1;
	}
	ret[index] = 0;
	return (ret);
}
