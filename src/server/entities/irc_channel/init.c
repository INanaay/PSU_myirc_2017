/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#include <string.h>
#include "../../../../inc/server/entities/entities.h"

int irc_channel_init(irc_channel_t *channel, const char *name,
		const char *subject, const char *password)
{
	int ret = 0;

	if (channel == NULL)
		return (EXIT_FAILURE);
	memset(channel, 0, sizeof(irc_channel_t));
	if (name == NULL)
		return (EXIT_FAILURE);
	channel->name = strdup(name);
	if (subject == NULL)
		channel->subject = strdup("no topic specified.");
	else
		channel->subject = strdup(subject);
	if (password != NULL)
		channel->password = strdup(password);
	ret |= linkedlist_init(&channel->clients);
	ret |= linkedlist_init(&channel->messages);
	if (ret != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void irc_channel_destroy(irc_channel_t *channel)
{
	linkedlist_t *clients;
	linkedlist_t *messages;

	if (channel->name != NULL)
		free(channel->name);
	if (channel->subject != NULL)
		free(channel->subject);
	if (channel->password != NULL)
		free(channel->password);
	clients = &channel->clients;
	messages = &channel->messages;
	for (node_t *node = messages->begin; node != NULL; node = node->next)
		free(node->value);
	linkedlist_destroy(clients);
	memset(channel, 0, sizeof(irc_channel_t));
}
