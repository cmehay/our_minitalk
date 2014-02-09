#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:09:23 by cmehay            #+#    #+#              #
#    Updated: 2013/11/29 12:19:45 by cmehay           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_CLIENT = client
NAME_SERVER = serveur
SRCDIR_CLIENT = srcs_client
SRCDIR_SERVER = srcs_server
HEADDIR = includes
HEAD = minitalk.h
HEADFILES = $(addprefix $(HEADDIR)/, $(HEAD))
SRC_CLIENT = main_client.c crc32_client.c exit_client.c mem_proc_client.c \
	signals_client.c singleton_client.c
SRC_SERVER = main.c checksum.c crc32.c mem_proc.c singleton.c signals.c exit.c
SRCFILES_CLIENT = $(addprefix $(SRCDIR_CLIENT)/, $(SRC_CLIENT))
SRCFILES_SERVER = $(addprefix $(SRCDIR_SERVER)/, $(SRC_SERVER))
LIB = libft.a
LIBDIR = libft
LIBFILES = $(addprefix $(LIBDIR)/, $(LIB))
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIB): $(LIBFILES)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFILES)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) -L$(LIBDIR) -lft

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFILES)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) -L$(LIBDIR) -lft

$(OBJ_CLIENT): $(SRCFILES_CLIENT)
	$(CC) $(CFLAGS) -I$(HEADDIR) -c $(SRCFILES_CLIENT)

$(OBJ_SERVER): $(SRCFILES_SERVER)
	$(CC) $(CFLAGS) -I$(HEADDIR) -c $(SRCFILES_SERVER)

$(LIBFILES):
	$(MAKE) -C $(LIBDIR) $(LIB)

.PHONY: all clean fclean re

clean:
	/bin/rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
