##
## EPITECH PROJECT, 2018
## Menger sponge
## File description:
## makefile
##

CFLAGS		+= -Wall -Wextra -g3

CPPFLAGS	+= -I ./include -I .

CC	=	gcc -pthread


COMMONSRC	=    src/utils/split_string.c   \
			src/utils/get_double_array_size.c  \
			src/core/linkedlist/init.c            \
			src/core/linkedlist/add.c          \
			src/core/linkedlist/destroy.c      \
			src/core/linkedlist/remove.c       \
			src/core/linkedlist/utils.c        \
			src/core/concurrency/threadpool.c	\
			src/core/string/contains.c          \
			src/core/concurrency/idgenerator.c  \
			src/core/linkedlist/insert.c        \
			src/core/linkedlist/stack.c         \
			src/core/string/case.c              \
			src/core/string/split.c             \
			src/core/string/tablen.c            \
			src/core/string/replace.c           \
			src/core/string/str_trim.c          \
			src/core/string/str_remove.c		\
			src/core/string/is_number.c         \
			src/core/string/free_strtab.c       \
			src/core/string/count_occurences.c


SERVERSRC  =	src/core/network/tcpserver/destroy.c   		\
		src/server/main.c   				\
		src/server/utils.c				\
		src/core/network/tcpserver/send.c       	\
		src/core/network/tcpserver/utils.c      	\
		src/core/network/tcpserver/init.c       	\
		src/core/network/tcpserver/start.c       	\
		src/core/network/tcpclient/tcpclient.c  	\
		src/server/entities/irc_server/init.c           \
		src/server/entities/irc_server/destroy.c        \
		src/server/entities/irc_channel/utils.c 	\
		src/server/entities/irc_channel/init.c  	\
		src/server/entities/irc_client/base.c 		\
		src/server/entities/irc_client/utils.c		\
		src/server/entities/irc_server/start.c  	\
		src/server/entities/irc_server/utils.c  	\
		src/server/entities/irc_parser/init.c   	\
		src/server/entities/irc_parser/destroy.c    	\
		src/server/entities/irc_parser/parse.c      	\
		src/server/protocol/list.c          		\
		src/server/protocol/user.c          		\
		src/server/protocol/ping.c          		\
		src/server/protocol/welcome.c       		\
		src/server/protocol/nickname.c      		\
		src/server/protocol/quit.c          		\
		src/server/protocol/join.c          	   	\
		src/server/protocol/part.c          	   	\
		src/server/protocol/message.c              	\
		src/server/protocol/names.c         	   	\
		src/server/entities/irc_server/channels.c



CLIENTSRC	=	src/core/network/ircclient/init.c  \
			src/core/network/ircclient/main.c \
			src/core/network/ircclient/commands.c \
			src/core/network/ircclient/start.c	\
			src/core/network/ircclient/commands/nick.c  \
			src/core/network/ircclient/commands/list.c  \
			src/core/network/ircclient/commands/join.c  \
			src/core/network/ircclient/commands/part.c  \
			src/core/network/ircclient/commands/users.c \
			src/core/network/ircclient/commands/names.c \
			src/core/network/ircclient/commands/msg.c   \
			src/core/network/ircclient/receive.c	\
			src/core/network/ircclient/send.c

CLIENTOBJ	=	$(CLIENTSRC:.c=.o)

COMMONOBJ	= $(COMMONSRC:.c=.o)

SERVEROBJ	= $(SERVERSRC:.c=.o)

CLIENTNAME	=	client

SERVERNAME	= server

all: client server

client: $(CLIENTOBJ) $(COMMONOBJ)
	$(CC) $(COMMONOBJ) $(CLIENTOBJ) -o $(CLIENTNAME) $(LDFLAGS)

server: $(SERVEROBJ) $(COMMONOBJ)
	$(CC) $(COMMONOBJ) $(SERVEROBJ) -o $(SERVERNAME) $(LDFLAGS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(CLIENTOBJ) $(SERVEROBJ)

fclean: clean
	$(RM) $(NAME) $(CLIENTNAME) $(SERVERNAME)

re: fclean all

.PHONY: all clean fclean re
