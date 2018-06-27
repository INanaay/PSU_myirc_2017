/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/05 by lebovin
*/

#ifndef PSU_MYIRC_2017_CHANNEL_H
#define PSU_MYIRC_2017_CHANNEL_H

#include "entities.h"

int irc_channel_init(irc_channel_t *channel,
const char *name, const char *subject, const char *password);
void irc_channel_destroy(irc_channel_t *channel);
int irc_channel_join(irc_channel_t *channel, irc_client_t *client);
int irc_channel_left(irc_channel_t *channel, irc_client_t *client);

#endif //PSU_MYIRC_2017_CHANNEL_H
