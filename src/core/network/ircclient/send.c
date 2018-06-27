/*
** EPITECH PROJECT, 2018
** ric
** File description:
** send
*/

#include <fcntl.h>
#include <unistd.h>
#include "../../../../inc/core/network/ircclient/ircclient.hpp"

static int open_file(char *path)
{
	int fd = open(path, O_RDONLY, 0644);

	if (fd == -1)
	{
		printf("Error openning file.\n");
		return (-1);
	}
	return (fd);
}

static void send_packet(t_client_info *client, char *file, char **command,
			size_t size)
{
	char packet[513 + size];

	memset(packet, 0, 513 + size);
	strcat(packet, "SENDFILE ");
	strcat(packet, command[1]);
	strcat(packet, " ");
	strcat(packet, command[2]);
	strcat(packet, " ");
	strcat(packet, command[3]);
	strcat(packet, " :");
	strcat(packet, file);
	strcat(packet, "\r\n");
	printf("packet = \n%s\n", packet);
	write(client->sd, packet, strlen(packet));

}

void send_file(char *path, t_client_info *client, size_t size, char **command)
{
	char *buffer = calloc(size + 1, sizeof(char));
	ssize_t read_size = 0;
	int file_fd = open_file(path);

	if (buffer == NULL) {
		printf("Couldnt alloc.\n");
		return;
	}
	if (file_fd == -1)
		return;
	read_size = read(file_fd, buffer, size);
	if (read_size <= 0) {
		printf("Couldnt read.\n");
			return;
	}
	send_packet(client, buffer, command, size);
}
