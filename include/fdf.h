/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:17:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/17 01:50:26 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"

# define PROG_NAME	"fdf"
# define P_N PROG_NAME

# define FDF_TITTLE	"fdf"
# define WIN_X		2560
# define WIN_Y 		1440
# define FDF_MAP	argv[1]
# define PART_STR	","
# define MAP map->map
# define MAX_X map->max_x
# define MAX_Y map->max_y

/*
**ERRORS_FDF
*/
# define FDF_NO_ARG			"No arguments"
# define FDF_TOO_MANY		"Too many argumets"
# define FDF_NOT_VALID		"File doesn't exist or Permission denied"
# define FDF_BAD_MAP		"Bad map"
# define FORM_ERR			"%v%s: %s\n"
# define FDF_PRINT_ERR(err) ft_printf(FORM_ERR, STDERR_FILENO, PROG_NAME, err)
# define FDF_PRINT_ERR_EXT(err) {FDF_PRINT_ERR(err); exit(EXIT_FAILURE);}

/*
**SYS_ERRORS
*/
# define FDF_CHK_ERR(val, err) if ((val) == FAILURE) ft_err_exit(err, P_N)
# define FDF_CHK_NULL_PTR(ptr, err) if (!(ptr)) ft_err_exit(err, P_N)

/*
**color and height repository
*/
# define POS_H 32
# define FDF_SET_HEIGHT_L(val, height)	(((val) | (height)) << POS_H)
# define FDF_SET_COLOR_L(val, color)	((val) | (color))
# define FDF_GET_COLOR_L(val)			(((val) << POS_H) >> POS_H)
# define FDF_GET_HEIGHT_L(val)			((val >> POS_H))

typedef long int	t_map;

typedef struct	s_cfg_image
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}				t_cfg_image;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_pixel;

struct			s_ptr
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_image;
};

struct			s_map
{
	t_map		**map;
	size_t		max_x;
	size_t		max_y;
	int			scale;
};

typedef struct	s_listfdf
{
	char				*line;
	size_t				size_line;
	struct s_listfdf	*next;
}				t_listfdf;

struct			s_gnl
{
	char		*line;
	int			ret;
};

/*
**VALID
*/
int				fdf_valid_arg(const int argc, char *const argv[]);

/*
**FDF_LIST
*/
void			list_add_end(t_listfdf **beg, char *line);
t_listfdf		*list_create(char *line);
void			list_delete(t_listfdf **beg);
size_t			list_size(t_listfdf *beg);

/*
**READ_FILE
*/
t_listfdf		*fdf_read_file(const char *filename);

/*
**WORK_MAP
*/
enum e_err		fdf_parsing_map(t_listfdf *beg);
void			fdf_create_map(t_listfdf *beg, struct s_map *map);

#endif
