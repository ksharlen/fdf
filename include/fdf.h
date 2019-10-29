/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:17:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 22:02:09 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define WIN_X		2048
# define WIN_Y 		1100
# define FDF_DFLT_COLOR	0x00ff00
# define FDF_DFLT_SCALE	1.0
# define FDF_DFLT_SHIFT_X ((WIN_X) / 2)
# define FDF_DFLT_SHIFT_Y ((WIN_Y) / 2)
# define FDF_MAP	argv[1]
# define PART_STR	","

/*
**ZOOM
*/
# define FDF_ZOOM_OUT	0.9
# define FDF_ZOOM_IN	1.1

# define FDF_SHIFT		13

# define FDF_ROT_LEFT		-(M_PI / 128)
# define FDF_ROT_RIGHT		M_PI / 128
# define FDF_ROT_UP			FDF_ROT_RIGHT
# define FDF_ROT_DOWN		FDF_ROT_LEFT

/*
**FDF_ALIAS
*/
# define FDF_INF 1
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
# define FDF_A	KEY_A
# define FDF_S	KEY_S
# define FDF_D	KEY_D
# define FDF_W	KEY_W
# define FDF_ESC KEY_ESC
# define FDF_NUM_KEY_PLS KEY_NUM_PLS
# define FDF_NUM_KEY_SUB KEY_NUM_SUB

# define FDF_NUM_4 KEY_NUM_4
# define FDF_NUM_5 KEY_NUM_5
# define FDF_NUM_6 KEY_NUM_6
# define FDF_NUM_7 KEY_NUM_7
# define FDF_NUM_8 KEY_NUM_8
# define FDF_NUM_9 KEY_NUM_9

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
# define CHK_ROT_X(key) ((key) == FDF_NUM_4 || (key) == FDF_NUM_6)
# define CHK_ROT_Y(key) ((key) == FDF_NUM_8 || (key) == FDF_NUM_5)
# define CHK_ROT_Z(key) ((key) == FDF_NUM_7 || (key) == FDF_NUM_9)

# define CHK_ROTATE(key) (CHK_ROT_X(key) || CHK_ROT_Y(key) || CHK_ROT_Z(key))

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
	int	x;
	int	y;
}					t_coord;

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

struct				s_rad
{
	float	rad_x;
	float	rad_y;
	float	rad_z;
};

struct				s_shift
{
	int32_t	shift_x;
	int32_t	shift_y;
};

typedef struct		s_map
{
	t_pixel			*map;
	struct s_rad	rad;
	size_t			max_x;
	size_t			max_y;
	float			scale;
	struct s_shift	shift;
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

struct				s_line_create
{
	int dx;
	int sx;
	int sy;
	int dy;
	int err;
	int e2;
};

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
void				fdf_parsing_map(t_listfdf *beg, t_map *map);
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
void				fdf_line_create(int *img, t_coord beg, t_coord *end);
void				fdf_work_frame(t_mlx *mlx);
void				fdf_fit_screen_map(t_map *map);
void				fdf_scale_map(t_map *map);
void				fdf_zooming(t_map *map, const float zoom);
void				fdf_out_window(t_map *map);
void				fdf_in_window(t_map *map);
void				fdf_event_rad(int key, struct s_rad *rad);

#endif
