# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 08:27:12 by ksharlen          #+#    #+#              #
#    Updated: 2019/10/30 19:20:15 by ksharlen         ###   ########.fr        #
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

DIR_LINAL			:= ./lib/linal/source
DIR_INCLUDE_LINAL	:= ./lib/linal/include/

INCLUDE_FDF			:= fdf.h
SRCS				:= main.c\
							fdf_valid_arg.c\
							fdf_read_file.c\
							fdf_list.c\
							fdf_line_create.c\
							fdf_parsing_map.c\
							fdf_create_map.c\
							fdf_work_window.c\
							fdf_errors.c\
							fdf_work_frame.c\
							fdf_events.c\
							fdf_zoom.c\
							fdf_event_key_press.c\
							fdf_collect_height_not_zero.c\
							fdf_gradient.c

OBJS				:= $(SRCS:.c=.o)
DIRS_INCLUDE		:= $(DIR_INCLUDE_LIBFT) $(DIR_INCLUDE_FDF) $(DIR_INCLUDE_MLX) $(DIR_INCLUDE_LINAL)

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

vpath %.c $(DIR_SRCS) $(DIR_LINAL)
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
