/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
static size_t spaces_count(const char *str)
{
	size_t count = 0;

	while (isspace(*str))
	{
		count += 1;
		str += 1;
	}
	return (count);
}

static void remove_begin(char *str)
{
	size_t index = 0;

	while (isspace(str[index]))
		index += 1;
	if (index > 0)
		strcpy(str, &str[index]);
}

static void remove_end(char *str)
{
	size_t length = strlen(str) - 1;
	char tmp = str[length];

	while (length > 0 && isspace(tmp))
	{
		str[length] = 0;
		length -= 1;
		tmp = str[length];
	}
}

static void remove_middle(char *str)
{
	char cread;
	size_t reader = 1;
	size_t writer = 1;
	size_t length = strlen(str);

	while (reader < length) {
		cread = str[reader];
		if (isspace(cread)) {
			str[writer] = cread;
			reader += spaces_count(&str[reader]);
			writer += 1;
		}
		else {
			str[writer] = cread;
			writer += 1;
			reader += 1;
		}
	}
	str[writer] = 0;
}

void str_trim(char *str)
{
	if (str == NULL)
		return;
	remove_begin(str);
	remove_middle(str);
	remove_end(str);
}
