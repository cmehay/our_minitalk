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
SRC_CLIENT = main.c
SRC_SERVER = main.c
SRCFILES_CLIENT = $(addprefix $(SRCDIR_CLIENT)/, $(SRC_CLIENT))
SRCFILES_SERVER = $(addprefix $(SRCDIR_SERVER)/, $(SRC_SERVER))
LIB = libft.a
LIBDIR = libft
LIBFILES = $(addprefix $(LIBDIR)/, $(LIB))
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME_CLIENT) $(NAME_SERVEUR)

$(LIB): $(LIBFILES)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFILES)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) -L$(LIBDIR) -lft

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFILES)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) -L$(LIBDIR) -lft

$(OBJ_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -I$(HEADDIR) -c $(SRCFILES_CLIENT)

$(OBJ_SERVER): $(SRC_SERVER)
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
