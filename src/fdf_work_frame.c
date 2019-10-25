/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/25 17:52:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FDF_BEG_X 0
#define FDF_BEG_Y 0

static int		check_pix_in_to_win(t_coord *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

void			fdf_map_to_img(t_map *map, int *img)
{
	t_coord	curr_pix;
	size_t	i;

	i = 0;
	while (i < MAX_X * MAX_Y)
	{
		curr_pix.x = round(MAP[i].x * map->scale);
		curr_pix.y = round(MAP[i].y * map->scale);
		if (check_pix_in_to_win(&curr_pix) == SUCCESS)
			*(img + WIN_X * curr_pix.y + curr_pix.x) = MAP[i].color;
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
