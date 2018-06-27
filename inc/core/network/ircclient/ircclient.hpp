//
// Created by NANAA on 08/05/18.
//

#ifndef PSU_MYIRC_2017_IRCCLIENT_HPP
#define PSU_MYIRC_2017_IRCCLIENT_HPP

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "../../linkedlist/linkedlist.h"

#define NB_COMMANDS (7 + 0)
#define DEFAULT_PORT (6667 + 0)
#define MAX_COMMAND_LEN (510 + 0)

enum CONNECTION_TYPE
{
	NOT_CONNECTED,
	NO_LOGIN,
	CONNECTED
};

struct s_client_info
{
	linkedlist_t channels_list;
	int sd;
	enum CONNECTION_TYPE connected;
	char *nickname;
	char *host;
	char *current_channel;
	char input[2048];
};

typedef struct s_client_info t_client_info;

struct s_commands
{
	char *command;
	void (*fptr)(char **, t_client_info *);
};

typedef struct s_commands t_commands;

void init_client_info(t_client_info *client_info);
void client_start(t_client_info *);
void handle_input(char *input, t_client_info *client_info);
void connect_to_server(char *ip, int port, t_client_info *client_info);
char **split_string(char *line, char *tokens);
void try_connect(char **command, t_client_info *client_info);
void nick_command(char **command, t_client_info *client_info);
void list_command(char **command, t_client_info *client_info);
void join_command(char **command, t_client_info *client_info);
void part_command(char **command, t_client_info *client_info);
void users_command(char **command, t_client_info *client_info);
void names_command(char **command, t_client_info *client_info);
void msg_command(char **command, char *msg, t_client_info *client_info);
char *get_server_response(t_client_info *client);
void *read_server_thread(void *p_client_info);
void send_pong(char *ping, t_client_info *client);
void msg_to_channel_command(char *msg, t_client_info *client_info);
void get_server_host(t_client_info *client_info);
void client_run(t_client_info *client_info);
void send_file(char *path, t_client_info *client, size_t size, char **command);

#endif //PSU_MYIRC_2017_IRCCLIENT_HPP
