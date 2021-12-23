# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfichot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:19:14 by bfichot           #+#    #+#              #
#    Updated: 2021/11/24 18:15:06 by bfichot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
HEADER			= include
RM				= rm -f
NAME			= $(SERVER) $(CLIENT)
SRCS_SERVER		= srcs/server.c srcs/utils.c
SRCS_CLIENT		= srcs/client.c srcs/utils.c
OBJS_SERVER 	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT 	= $(SRCS_CLIENT:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all:		$(NAME) $(SERVER) $(CLIENT)

$(SERVER):	$(OBJS_SERVER)
			$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT):	$(OBJS_CLIENT)
			$(CC) -o $@ $^ $(CFLAGS)
clean:
		$(RM) srcs/*.o

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean r
