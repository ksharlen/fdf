# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 08:27:12 by ksharlen          #+#    #+#              #
#    Updated: 2019/09/20 19:01:56 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= fdf
DIR_SRCS			:= src/
DIR_OBJS 			:= bin/
DIR_INCLUDE_FDF 	:= include/
DIR_INCLUDE_LIBFT	:= lib/libft/include
DIR_INCLUDE_MLX		:= lib/minilibx/
DIR_TMP				:= tmp/
DIR_LIB				:= lib/
DIR_LIBFT			:= lib/libft/
DIR_MLX				:= lib/minilibx/

INCLUDE_LIBFT		:= libft.h
INCLUDE_MLX			:= mlx.h
LIBFT				:= libft.a
MLX					:= libmlx.a

INCLUDE_FDF			:= fdf.h
SRCS				:= main.c
OBJS				:= $(SRCS:.c=.o)
DIRS_INCLUDE		:= $(DIR_INCLUDE_LIBFT) $(DIR_INCLUDE_FDF) $(DIR_INCLUDE_MLX)

INCLUDES			:= $(INCLUDE_FDF) $(INCLUDE_LIBFT) $(INCLUDE_MLX)

FRAMEWORKS			:= -framework OpenGL -framework AppKit

CC					:= gcc
CFLAGS				:= -g -Wall -Wextra -Werror
OFLAGS				:= -c
IFLAGS				:= -I
NFLAGS				:= -o

CREATE_DIR	:= mkdir -p
REMOVE		:= rm -rf
MAKE_LIBFT	:= make -C $(DIR_LIBFT)
MAKE_MLX	:= make -C $(DIR_MLX)

vpath %.c $(DIR_SRCS)
vpath %.o $(DIR_OBJS)
vpath %.h $(DIRS_INCLUDE)
vpath %.a $(DIR_LIBFT) $(DIR_MLX)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(addprefix $(DIR_OBJS), $(OBJS)) $(addprefix $(DIR_LIBFT), $(LIBFT)) $(addprefix $(DIR_MLX), $(MLX)) $(NFLAGS) $@ $(FRAMEWORKS)

$(OBJS): %.o:%.c $(INCLUDES) | $(DIR_OBJS)
	$(CC) $(OFLAGS) $(CFLAGS) $< $(NFLAGS) $(DIR_OBJS)$@ $(addprefix $(IFLAGS), $(DIRS_INCLUDE))

$(DIR_OBJS):
	$(CREATE_DIR) $@

$(LIBFT):
	$(MAKE_LIBFT)

$(MLX):
	$(MAKE_MLX)

clean:
	$(REMOVE) $(addprefix $(DIR_OBJS), $(OBJS))
	$(REMOVE) $(DIR_OBJS)
	$(MAKE_LIBFT) clean
	$(MAKE_MLX) clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE_MLX) fclean

re: all fclean

.PHONY: clean fclean  re
.SILENT: all $(NAME) $(OBJS) $(DIR_OBJS) $(LIBFT) $(MLX) clean fclean re
