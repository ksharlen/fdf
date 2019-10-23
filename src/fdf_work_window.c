/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 23:50:57 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	define_center(t_pixel elem)
{
	t_coord	center_win;
	t_coord	center_img;
	t_coord begin_img_centr;

	center_win.x = WIN_X / 2;
	center_win.y = WIN_Y / 2;
	center_img.x = elem.x / 2;
	center_img.y = elem.y / 2;
	begin_img_centr.x = center_win.x - center_img.x;
	begin_img_centr.y = center_win.y - center_img.y;
	return (begin_img_centr);
}

static void		fdf_map_to_img(t_map *map, int *img)
{
	int x;
	int y;
	size_t	i;
	t_coord	coor;
	size_t	center;

	i = 0;
	map->scale = 200;//!TEST
	fdf_scale_map(map);
	coor = define_center(MAP[MAX_X * MAX_Y - 1]);
	center = WIN_X * coor.y + coor.x;
	while (i < MAX_X * MAX_Y)
	{
		x = MAP->x;
		y = MAP->y;
		if ((x < WIN_X) && (y < (WIN_Y) && (x > 0 && y > 0)) && center > 0 && ((center + WIN_X * y + x) > 0 && (center + WIN_X * y + x) < WIN_X * WIN_Y))
			*((img + center) + WIN_X * y + x) = MAP->color;
		++i;
		++MAP;
	}
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
