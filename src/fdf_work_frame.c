/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 21:40:29 by ksharlen         ###   ########.fr       */
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

static t_coord	fdf_rot(t_pixel *elem, struct s_rad *rad, float *scale, struct s_shift *shift)
{
	t_coord	coord;

	coord.x = (int)round(((X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X)) * sin(RAD_Y))
				* cos(RAD_Z) - (Y * cos(RAD_X) + Z * sin(RAD_X)) * sin(RAD_Z)) * *scale) + SHIFT_X;
	coord.y = (int)round((-(X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X)) * sin(RAD_Y))
				* sin(RAD_Z) + (Y * cos(RAD_X) + Z * sin(RAD_X)) * cos(RAD_Z)) * *scale) + SHIFT_Y;
	return (coord);
}

void				fdf_map_to_img(t_map *map, int *img)
{
	t_coord	curr;
	t_coord	next;
	t_coord	up;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			curr = fdf_rot(&MAP[i * MAX_X + j], &map->rad, &map->scale, &map->shift);
			if (j + 1 != MAX_X)
			{
				next = fdf_rot(&MAP[i * MAX_X + j + 1], &map->rad, &map->scale, &map->shift);
				fdf_line_create(img, curr, &next);
			}
			if (i)
			{
				up = fdf_rot(&MAP[(i - 1) * MAX_X + j], &map->rad, &map->scale, &map->shift);
				fdf_line_create(img, curr, &up);
			}
			++j;
		}
		++i;
	}
}

void			fdf_work_frame(t_mlx *mlx)
{
	mlx_clear_window(MLX_PTR, MLX_WIN);
	ft_bzero(mlx->img, WIN_X * WIN_Y * 4);
	fdf_map_to_img(&mlx->map, mlx->img);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, FDF_BEG_X, FDF_BEG_Y);
}
