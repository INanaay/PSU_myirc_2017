/*
** EPITECH PROJECT, 2018
** irc
** File description:
** irc
*/

#include "../../inc/utils/Utils.hpp"

int get_double_array_size(char **array)
{
	int size = 0;

	while (array[size])
		size++;
	return (size);
}