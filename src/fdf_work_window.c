/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/24 20:55:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		chek_pix_in_to_win(t_pixel *elem)
{
	if ((elem->x < WIN_X) && (elem->y < WIN_Y) && (elem->x >= 0) && elem->y >= 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

static void		fdf_map_to_img(t_map *map, int *img)
{
	t_coord	curr_pix;
	size_t	i;

	i = 0;
	while (i < FDF_LAST_ELEM_MAP)
	{
		curr_pix.x = MAP->x;
		curr_pix.y = MAP->y;
		if (check_pix_in_to_win(MAP))
			*(img + WIN_X * curr_pix.y + curr_pix.x) = MAP->color;
		++i;
		++MAP;
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

void			fdf_work_window(t_map *map) //!Может быть будет еще что-то принимать
{
	struct s_ptr		mlx_ptr;
	struct s_cfg_image	cfg_image;
	int					*image;

	MLX_PTR = mlx_init();
	FDF_CHK_NULL_PTR(MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y,
					PROG_NAME), FDF_E_WIN);
	FDF_CHK_NULL_PTR(MLX_IMG = mlx_new_image(MLX_PTR, WIN_X, WIN_Y),
					FDF_E_IMG);
	image = (int *)mlx_get_data_addr(MLX_IMG, &FDF_BPP, &FDF_SL, &FDF_ENDI);
	fdf_map_to_img(map, image);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_IMG, 0, 0);
	fdf_events(&mlx_ptr);
}
