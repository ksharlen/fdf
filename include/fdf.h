/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:17:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 14:07:15 by ksharlen         ###   ########.fr       */
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
# define FDF_DFLT_COLOR	0x00FFFF
# define FDF_HEIGHT_COLOR 0xC71585
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
# define FDF_INF			1
# define MAP				map->map
# define MAX_X				map->max_x
# define MAX_Y				map->max_y
# define MLX_PTR 			mlx->mlx_ptr.mlx_ptr
# define MLX_WIN 			mlx->mlx_ptr.mlx_win
# define MLX_P_IMG			mlx->mlx_ptr.mlx_image
# define MLX_IMG			mlx->img
# define FDF_CFG_IMG		cfg_image
# define FDF_BPP			mlx->FDF_CFG_IMG.bits_per_pixel
# define FDF_SL				mlx->FDF_CFG_IMG.size_line
# define FDF_ENDI			mlx->FDF_CFG_IMG.endian
# define FDF_LAST_ELEM_MAP	MAX_X * MAX_Y - 1
# define FDF_CHK_FILE		NULL
# define FDF_PIXEL_COLOR	*(img + WIN_X * beg.y + beg.x)

/*
**KEY_MAP_FOR_FDF
*/
# define FDF_A				KEY_A
# define FDF_S				KEY_S
# define FDF_D				KEY_D
# define FDF_W				KEY_W
# define FDF_I				KEY_I
# define FDF_P				KEY_P
# define FDF_ESC 			KEY_ESC
# define FDF_NUM_KEY_PLS 	KEY_NUM_PLS
# define FDF_NUM_KEY_SUB 	KEY_NUM_SUB

# define FDF_NUM_4			KEY_NUM_4
# define FDF_NUM_5			KEY_NUM_5
# define FDF_NUM_6			KEY_NUM_6
# define FDF_NUM_7			KEY_NUM_7
# define FDF_NUM_8			KEY_NUM_8
# define FDF_NUM_9			KEY_NUM_9

# define FDF_V				KEY_V

# define FDF_UP_ARROW		KEY_UP_ARROW
# define FDF_DOWN_ARROW		KEY_DOWN_ARROW

# define FDF_SPACE			KEY_SPACE

/*
**TMP
*/
# define FDF_T KEY_T

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
**MACRO_PRESS
*/
# define PRS_A(key) ((key) == FDF_A)
# define PRS_S(key) ((key) == FDF_S)
# define PRS_D(key) ((key) == FDF_D)
# define PRS_W(key) ((key) == FDF_W)

# define CHK_ROT_X(key) ((key) == FDF_NUM_4 || (key) == FDF_NUM_6)
# define CHK_ROT_Y(key) ((key) == FDF_NUM_8 || (key) == FDF_NUM_5)
# define CHK_ROT_Z(key) ((key) == FDF_NUM_7 || (key) == FDF_NUM_9)
# define CHK_ROTATE(key) (CHK_ROT_X(key) || CHK_ROT_Y(key) || CHK_ROT_Z(key))

# define CHK_SCALE(key) ((key) == FDF_NUM_KEY_PLS || (key) == FDF_NUM_KEY_SUB)
# define CHK_SHIFT(key) (PRS_A(key) || PRS_S(key) || PRS_D(key) || PRS_W(key))
# define CHK_HEIGHT(key) ((key) == FDF_UP_ARROW || (key) == FDF_DOWN_ARROW)

# define CHK_IZOMETR(key) ((key) == FDF_P || (key) == FDF_I)

/*
**MENU
*/
# define FDF_ZOOM_UP	"zoom_up: <+>"
# define FDF_ZOOM_DOWN	"zoom_down: <->"

# define FDF_MOV_UP		"mov_up: <w>"
# define FDF_MOV_DOWN	"mov_down: <s>"
# define FDF_MOV_LEFT	"mov_left: <a>"
# define FDF_MOV_RIGHT	"mov_right: <d>"

# define FDF_ROT_X_L	"rot_x_left: <num_4>"
# define FDF_ROT_X_R	"rot_x_right: <num_6>"
# define FDF_ROT_Y_L	"rot_y_up: <num_8>"
# define FDF_ROT_Y_R	"rot_y_down: <num_5>"
# define FDF_ROT_Z_L	"rot_z_left: <num_7>"
# define FDF_ROT_Z_R	"rot_z_right: <num_9>"

# define FDF_RESET_IMG	"default: <space>"

# define FDF_IZOMETR	"izometr: <i>"

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

struct				s_delta
{
	int dx;
	int dy;
};

struct				s_shift
{
	int32_t	shift_x;
	int32_t	shift_y;
};

typedef struct		s_copy
{
	t_pixel			*map;
	float			scale;
}					t_copy;

struct				s_menu
{
	int				color;
	BYTE			flag_menu;
};

struct				s_height
{
	int	*z;
	int	*color;
};

typedef struct		s_map
{
	struct s_rad	rad;
	t_copy			copy_map;
	struct s_shift	shift;
	struct s_height	*height_not_zero;
	size_t			size_height_not_zero;
	// int				**height_not_zero;
	t_pixel			*map;
	size_t			max_x;
	size_t			max_y;
	float			scale;
}					t_map;

typedef struct		s_mlx
{
	t_map				map;
	struct s_menu		menu;
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
	struct s_delta	delta;
	int				sx;
	int				sy;
	int				err;
	int				e2;
};

struct				s_color
{
	int red;
	int green;
	int blue;
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
void				fdf_reset_map(t_map *map);
void				collect_height(t_pixel *map, size_t	size_map,
	struct s_height *height_not_zero);

/*
**WINDOW
*/
void				fdf_work_window(t_mlx *mlx);

/*
**EVENTS
*/
void				fdf_events(t_mlx *mlx);
void				fdf_event_scale(int key, float *scale);
void				fdf_event_shift(int key, struct s_shift *shift);
void				fdf_event_rad(int key, struct s_rad *rad);
void				fdf_event_height(int key, struct s_height *height_not_zero,
	size_t size_height);
void				fdf_event_projection(int key, struct s_rad *rad);

/*
**ERRORS
*/
void				fdf_err_str(const int err);
void				fdf_err_ext(const int err);

/*
**WORK_FRAME
*/
void				fdf_line_create(int *img, t_pixel beg,
									t_pixel *end, t_pixel begin);
void				fdf_work_frame(t_mlx *mlx);
void				fdf_fit_screen_map(t_map *map);
void				fdf_scale_map(t_map *map);
void				fdf_zooming(t_map *map, const float zoom);
void				fdf_out_window(t_map *map);
void				fdf_in_window(t_map *map);

/*
**FREE
*/
void				fdf_del_map(t_pixel **map);
void				fdf_del_height_ptr(struct s_height **height);

/*
**BONUS
*/
void				fdf_collect_height_not_zero(t_map *map);
int					fdf_gradient(t_pixel *beg, t_pixel *curr, t_pixel *end,
								struct s_delta *delta);
void				fdf_menu(t_mlx *mlx);
void				fdf_init_rad(struct s_rad *rad);

#endif
