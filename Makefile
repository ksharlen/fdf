# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 08:27:12 by ksharlen          #+#    #+#              #
#    Updated: 2019/09/18 09:12:11 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= fdf
DIR_SRCS			:= src/
DIR_OBJS 			:= bin/
DIR_INCLUDE_FDF 	:= include/
DIR_INCLUDE_LIBFT	:= libft/include
DIR_TMP				:= tmp/
DIR_LIBFT			:= libft/

INCLUDE_LIBFT		:= libft.h
LIBFT				:= libft.a

INCLUDE_FDF			:= fdf.h
SRCS				:= main.c
OBJS				:= $(SRCS:.c=.o)
DIRS_INCLUDE		:= $(DIR_INCLUDE_LIBFT) $(DIR_INCLUDE_FDF)

INCLUDES			:= $(INCLUDE_FDF) $(INCLUDE_LIBFT)

CC					:= gcc
CFLAGS				:= -g -Wall -Wextra -Werror
OFLAGS				:= -c
IFLAGS				:= -I 
NFLAGS				:= -o

CREATE_DIR	:= mkdir -p
REMOVE		:= rm -rf
MAKE_LIBFT	:= make -C $(DIR_LIBFT)

vpath %.c $(DIR_SRCS)
vpath %.o $(DIR_OBJS)
vpath %.h $(DIRS_INCLUDE)
vpath %.a $(DIR_LIBFT)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(addprefix $(DIR_OBJS), $(OBJS)) $(addprefix $(DIR_LIBFT), $(LIBFT)) $(NFLAGS) $@

$(OBJS): %.o:%.c $(INCLUDES) | $(DIR_OBJS)
	$(CC) $(OFLAGS) $(CFLAGS) $< $(NFLAGS) $(DIR_OBJS)$@ $(addprefix $(IFLAGS), $(DIRS_INCLUDE))

$(DIR_OBJS):
	$(CREATE_DIR) $@

$(LIBFT):
	$(MAKE_LIBFT)

clean:
	$(REMOVE) $(addprefix $(DIR_OBJS), $(OBJS))
	$(REMOVE) $(DIR_OBJS)
	$(MAKE_LIBFT) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_LIBFT) fclean

re: all fclean

.PHONY: clean fclean  re
#.SILENT: all $(NAME) $(OBJS) $(DIR_OBJS) $(LIBFT) clean fclean re
