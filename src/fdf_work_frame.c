/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/27 22:48:16 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FDF_BEG_X 0
#define FDF_BEG_Y 0

// static int		check_pix_in_to_win(t_coord *coor)
// {
// 	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
// 		((coor->x >= 0) && (coor->y >= 0)))
// 		return (SUCCESS);
// 	return (FAILURE);
// }

void			fdf_map_to_img(t_map *map, int *img)
{
	t_coord	curr_pix;
	t_coord	next_pix;
	t_coord up_pix;
	float	arr[3];
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			fdf_rot_coor(&MAP[i * MAX_X + j], map->matr.x_matr, arr);
			curr_pix.x = round(arr[0] * MAP[i * MAX_X + j].x * map->scale) + map->shift_x;
			curr_pix.y = round(arr[1] * MAP[i * MAX_X + j].y * map->scale) + map->shift_y;
			if (j + 1 != MAX_X)
			{
				next_pix.x = round(MAP[i * MAX_X + j + 1].x * map->scale + map->shift_x);
				next_pix.y = round(MAP[i * MAX_X + j + 1].y * map->scale + map->shift_y);
				fdf_line_create(img, &curr_pix, &next_pix);
			}
			if (i > 0)
			{
				up_pix.x = curr_pix.x;
				up_pix.y = round(MAP[(i - 1) * MAX_X + j].y * map->scale + map->shift_y);
				fdf_line_create(img, &curr_pix, &up_pix);
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
