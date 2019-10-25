/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:17:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/25 19:50:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!NEED REFACT HEADERS

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "fdf_keymap.h"
# include "libft.h"
# include "mlx.h"

# define PROG_NAME	"fdf"
# define P_N PROG_NAME

# define FDF_TITTLE	"fdf"
# define WIN_X		1600
# define WIN_Y 		900
// # define WIN_X	200
// # define WIN_Y	200
# define FDF_DFLT_COLOR	0x00ff00
# define FDF_DFLT_SCALE	1.0
# define FDF_DFLT_SHIFT_X ((WIN_X) / 2)
# define FDF_DFLT_SHIFT_Y ((WIN_Y) / 2)
# define FDF_MAP	argv[1]
# define PART_STR	","

/*
**ZOOM
*/
# define FDF_ZOOM_OUT	0.8
# define FDF_ZOOM_IN	1.2

# define FDF_SHIFT		13

/*
**FDF_ALIAS
*/
# define MAP map->map
# define MAX_X map->max_x
# define MAX_Y map->max_y
# define MLX_PTR mlx->mlx_ptr.mlx_ptr
# define MLX_WIN mlx->mlx_ptr.mlx_win
# define MLX_P_IMG mlx->mlx_ptr.mlx_image
# define MLX_IMG	mlx->img
# define FDF_CFG_IMG cfg_image
# define FDF_BPP mlx->FDF_CFG_IMG.bits_per_pixel
# define FDF_SL mlx->FDF_CFG_IMG.size_line
# define FDF_ENDI mlx->FDF_CFG_IMG.endian
# define FDF_LAST_ELEM_MAP MAX_X * MAX_Y - 1
# define FDF_CHK_FILE NULL

/*
**KEY_MAP_FOR_FDF
*/
# define FDF_ESC KEY_ESC
# define FDF_NUM_KEY_PLS KEY_NUM_KEY_PLS
# define FDF_NUM_KEY_SUB KEY_NUM_KEY_SUB
# define FDF_LEFT_ARROW KEY_LEFT_ARROW
# define FDF_RIGHT_ARROW KEY_RIGHT_ARROW
# define FDF_UP_ARROW KEY_UP_ARROW
# define FDF_DOWN_ARROW KEY_DOWN_ARROW

/*
**MOUSE
*/
# define FDF_LEFT_BUTTON	1
# define FDF_RIGHT_BUTTON	2
# define FDF_MIDDLE_BUTTON	3
# define FDF_SCROLL_UP		4
# define FDF_SCROLL_DOWN	5
# define FDF_SCROLL_LEFT	6
# define FDF_SCROLL_RIGHT	7

/*
**MACRO
*/
# define FDF_MIDDLE(val) (val) / 2
# define FDF_GET_MAX_X(val, line) ((val) = ft_num_words((line), (PART_STR)))
# define FDF_GET_MAX_Y(val, beg) (val) = (list_size(beg))

/*
**ERRORS
*/
# define FDF_E_WIN				0
# define FDF_E_IMG				1
# define FDF_E_XPM_IMG			2
# define FDF_E_XPM_FILE_IMG		3
# define FDF_E_INIT				4

/*
**ERRORS_FDF
*/
# define FDF_CHK_ERR_EXT(val, err) if ((val) == F) fdf_err_ext(err)
# define FDF_CHK_NULL_PTR(val, err) if (!(val)) fdf_err_ext(err)

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
# define FDF_CHK_ERR(val, err) if ((val) == F) FDF_PRINT_ERR_EXT(err)
# define FDF_CHK_NUMM_PTR(ptr, err) if (!(val)) FDF_PRINT_ERR_EXT(err)

//!need delete
/*
**color and height repository
*/
# define POS_H 32
# define FDF_SET_HEIGHT_L(val, height)	(((val) | (height)) << POS_H)
# define FDF_SET_COLOR_L(val, color)	((val) | (color))
# define FDF_GET_FAST_COLOR_L(val)		((val))
# define FDF_GET_COLOR_L(val)			(((val) << POS_H) >> POS_H)
# define FDF_GET_HEIGHT_L(val)			(((val) >> POS_H))
# define FDF_SET_HC_L(v, h, c) FDF_SET_HEIGHT_L(v, h) | FDF_SET_COLOR_L(v, c)

/*
**EVENTS
*/
# define FDF_NOT_WORK				0
# define FDF_KEY_PRESS				2
# define FDF_KEY_RELEASE			3
# define FDF_MOUSE_BUTTON_PRESS		4
# define FDF_MOUSE_BUTTON_RELEASE	5
# define FDF_MOUSE_MOVEMENT			6
# define FDF_EXPOSE					12
# define FDF_RED_BUTTON				17

typedef struct		s_cfg_image
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}					t_cfg_image;

typedef struct		s_coord
{
	ssize_t x;
	ssize_t y;
}				t_coord;

typedef struct		s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}					t_pixel;

struct				s_ptr
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_image;
};

typedef struct		s_map
{
	t_pixel		*map;
	size_t		max_x;
	size_t		max_y;
	float		scale;
	int32_t		shift_x;
	int32_t		shift_y;
}					t_map;

typedef struct		s_mlx
{
	t_map				map;
	struct s_ptr		mlx_ptr;
	struct s_cfg_image	cfg_image;
	int					*img;
}					t_mlx;



typedef struct		s_listfdf
{
	char				*line;
	struct s_listfdf	*next;
}					t_listfdf;

struct				s_gnl
{
	char		*line;
	int			ret;
};

// struct				s_event
// {
// 	struct s_ptr	mlx_ptr;
// 	t_map			*map;
// }

/*
**VALID
*/
int					fdf_valid_arg(const int argc, char *const argv[]);

/*
**FDF_LIST
*/
void				list_add_end(t_listfdf **beg, char *line);
t_listfdf			*list_create(char *line);
void				list_delete(t_listfdf **beg);
size_t				list_size(t_listfdf *beg);

/*
**READ_FILE
*/
t_listfdf			*fdf_read_file(const char *filename);

/*
**WORK_MAP
*/
enum e_err			fdf_parsing_map(t_listfdf *beg, t_map *map);
void				fdf_create_map(t_listfdf *beg, t_map *map);
void				fdf_map_to_img(t_map *map, int *img);

/*
**WINDOW
*/
void				fdf_work_window(t_mlx *mlx);

/*
**EVENTS
*/
void				fdf_events(t_mlx *mlx);

/*
**ERRORS
*/
void				fdf_err_str(const int err);
void				fdf_err_ext(const int err);

/*
**WORK_FRAME
*/
void				fdf_work_frame(t_mlx *mlx);
void				fdf_fit_screen_map(t_map *map);
void				fdf_scale_map(t_map *map);
void				fdf_zooming(t_map *map, const float zoom);
void				fdf_out_window(t_map *map);
void				fdf_in_window(t_map *map);

#endif
