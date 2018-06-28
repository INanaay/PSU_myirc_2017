/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include "../../../../inc/server/entities/entities.h"
#include "../../../../inc/server/entities/irc_channel.h"

irc_channel_t *irc_server_create_channel(irc_server_t *irc, const char *name,
					const char *subject, const char *pwd)
{
	irc_channel_t *channel = malloc(sizeof(irc_channel_t));

	if (channel == NULL)
		return (NULL);
	if (irc_channel_init(channel, name, subject, pwd) != EXIT_SUCCESS)
		return (NULL);
	if (linkedlist_append(&irc->channels, channel) != EXIT_SUCCESS)
		return (NULL);
	return (channel);
}
