/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/28 19:11:46 by ksharlen         ###   ########.fr       */
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
	// t_coord beg;
	// t_coord end;

	// P_UNUSED(map);
	// beg.x = 1500;
	// beg.y = 1500;

	// end.x = 100;
	// end.y = 100;
	// fdf_line_create(img, beg, end);
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
			curr_pix.x = (int)round(arr[0] * map->scale) + map->shift_x;
			curr_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
			if (j + 1 != MAX_X)
			{
				fdf_rot_coor(&MAP[i * MAX_X + j + 1], map->matr.x_matr, arr);
				next_pix.x = (int)round(arr[0] * map->scale) + map->shift_x;
				next_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
				fdf_line_create(img, curr_pix, next_pix);
			}
			if (i > 0)
			{
				fdf_rot_coor(&MAP[(i - 1) * MAX_X + j], map->matr.x_matr, arr);
				up_pix.x = curr_pix.x;
				up_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
				fdf_line_create(img, curr_pix, up_pix);
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
