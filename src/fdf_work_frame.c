/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 00:12:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FDF_BEG_X 0
#define FDF_BEG_Y 0

#define X elem->x
#define Y elem->y
#define Z elem->z

#define RAD_X rad->rad_x
#define RAD_Y rad->rad_y
#define RAD_Z rad->rad_z

#define SHIFT_X shift->shift_x
#define SHIFT_Y shift->shift_y

static t_pixel		fdf_rot(t_pixel *elem, struct s_rad *rad,
	float *scale, struct s_shift *shift)
{
	t_pixel	coord;
	float x_x;
	float x_y;
	float x_z;

	float y_x;
	float y_y;
	float y_z;

	float z_x;
	float z_y;
	float z_z;

	x_x = elem->x;
	x_y = elem->y * cos(RAD_X) + elem->z * sin(RAD_X);
	x_z = -elem->y * sin(RAD_X) + elem->z * cos(RAD_X);

	y_x = x_x * cos(RAD_Y) + x_z * sin(RAD_Y);
	y_y = x_y;
	y_z = -x_x * sin(RAD_Y) + x_z * cos(RAD_Y);

	z_x = y_x * cos(RAD_Z) - y_y * sin(RAD_Z);
	z_y = y_x * sin(RAD_Z) + y_y * cos(RAD_Z);
	z_z = y_z;

	coord.x = (int)round(z_x * (*scale)) + SHIFT_X;
	coord.y = (int)round(z_y * (*scale)) + SHIFT_Y;
	// coord.x = (int)round(((X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X))
	// 		* sin(RAD_Y)) * cos(RAD_Z) - (Y * cos(RAD_X) + Z * sin(RAD_X)) *
	// 			sin(RAD_Z)) * *scale) + SHIFT_X;
	// coord.y = (int)round((-(X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X))
	// 		* sin(RAD_Y)) * sin(RAD_Z) + (Y * cos(RAD_X) + Z * sin(RAD_X)) *
	// 			cos(RAD_Z)) * *scale) + SHIFT_Y;
	coord.color = elem->color;
	return (coord);
}

static void			parse_line(size_t i, int *img, t_map *map)
{
	t_pixel	curr;
	t_pixel	next;
	t_pixel	up;
	size_t	j;

	j = 0;
	while (j < MAX_X)
	{
		curr = fdf_rot(&MAP[i * MAX_X + j], &map->rad,
						&map->scale, &map->shift);
		if (j + 1 != MAX_X)
		{
			next = fdf_rot(&MAP[i * MAX_X + j + 1], &map->rad,
							&map->scale, &map->shift);
			fdf_line_create(img, curr, &next, curr);
		}
		if (i)
		{
			up = fdf_rot(&MAP[(i - 1) * MAX_X + j], &map->rad,
							&map->scale, &map->shift);
			fdf_line_create(img, curr, &up, curr);
		}
		++j;
	}
}

void				fdf_map_to_img(t_map *map, int *img)
{
	size_t	i;

	i = 0;
	while (i < MAX_Y)
	{
		parse_line(i, img, map);
		++i;
	}
}

void				fdf_work_frame(t_mlx *mlx)
{
	mlx_clear_window(MLX_PTR, MLX_WIN);
	ft_bzero(mlx->img, WIN_X * WIN_Y * 4);
	fdf_map_to_img(&mlx->map, mlx->img);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, FDF_BEG_X, FDF_BEG_Y);
	if (mlx->menu.flag_menu)
		fdf_menu(mlx);
	else
		mlx_string_put(MLX_PTR, MLX_WIN, 0, 0,
			FDF_DFLT_COLOR, "Press <v> for menu");
}
