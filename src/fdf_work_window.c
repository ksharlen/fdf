/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/25 00:06:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #undef	MLX_PTR
// #undef	MLX_WIN
// #undef	MLX_P_IMG
// #undef	MLX_IMG

// # define MLX_PTR mlx.mlx_ptr.mlx_ptr
// # define MLX_WIN mlx.mlx_ptr.mlx_win
// # define MLX_P_IMG mlx.mlx_ptr.mlx_image
// # define MLX_IMG	mlx.img

static int		check_pix_in_to_win(t_pixel *elem)
{
	if ((elem->x < WIN_X) && (elem->y < WIN_Y) && (elem->x >= 0) && elem->y >= 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

void			fdf_map_to_img(t_map *map, int *img)
{
	t_coord	curr_pix;
	size_t	i;

	i = 0;
	// printf("map_scale: %f\n", map->scale);
	while (i < MAX_X * MAX_Y)
	{
		curr_pix.x = round(MAP[i].x * map->scale);
		curr_pix.y = round(MAP[i].y * map->scale);
		if (check_pix_in_to_win(&MAP[i]) == SUCCESS)
			*(img + WIN_X * curr_pix.y + curr_pix.x) = MAP[i].color;
		++i;
		// ++MAP;
	}
	// int x;
	// int y;
	// size_t	i;

	// i = 0;
	// map->scale = 2;//!TEST
	// fdf_scale_map(map);
	// while (i < MAX_X * MAX_Y)
	// {
	// 	x = MAP->x;
	// 	y = MAP->y;
	// 	if (((x < WIN_X) && (y < WIN_Y)) && (x >= 0 && y >= 0) && ((center + WIN_X * y + x) > 0) && (center + WIN_X * y + x) < WIN_X * WIN_Y)
	// 		*((img + center) + WIN_X * y + x) = MAP->color;
	// 	++i;
	// 	++MAP;
	// }
}

static t_mlx	init_mlx(void)
{
	t_mlx		mlx;

	FDF_CHK_NULL_PTR(MLX_PTR = mlx_init(), FDF_E_INIT);
	FDF_CHK_NULL_PTR(MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y,
					PROG_NAME), FDF_E_WIN);
	FDF_CHK_NULL_PTR(MLX_P_IMG = mlx_new_image(MLX_PTR, WIN_X, WIN_Y),
					FDF_E_IMG);
	FDF_CHK_NULL_PTR(MLX_IMG = (int *)mlx_get_data_addr(MLX_P_IMG,
					&FDF_BPP, &FDF_SL, &FDF_ENDI), FDF_E_IMG);
	return (mlx);
}

void			fdf_work_window(t_map *map) //!Может быть будет еще что-то принимать
{
	t_mlx		mlx;

	mlx.map = map;
	// printf("scale: %f\n", mlx.map->scale);
	// exit(EXIT_FAILURE);
	mlx = init_mlx();
	mlx_clear_window(MLX_PTR, MLX_WIN);
	fdf_map_to_img(map, MLX_IMG);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, 0, 0);
	fdf_events(&mlx);
}
