/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 22:31:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	define_center(size_t max_x_map, size_t max_y_map)
{
	t_coord	center_win;
	t_coord	center_img;
	t_coord begin_img_centr;

	center_win.x = WIN_X / 2;
	center_win.y = WIN_Y / 2;
	center_img.x = max_x_map / 2;
	center_img.y = max_y_map / 2;
	begin_img_centr.x = center_win.x - center_img.x;
	begin_img_centr.y = center_win.y - center_img.y;
	return (begin_img_centr);
}

static void		fdf_map_to_img(t_map *map, int *img)
{
	size_t	i;
	size_t	j;
	t_coord	coor;

	i = 0;
	coor = define_center(MAX_X, MAX_Y);
	img = img + ((WIN_X) * coor.y + coor.x);
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			*(img + (WIN_X) * i + j) = MAP[i * MAX_X + j].color;
			++j;
		}
		++i;
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
	image = (int *)mlx_get_data_addr(MLX_IMG, &cfg_image.bits_per_pixel, &cfg_image.size_line, &cfg_image.endian);
	fdf_map_to_img(map, image);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_IMG, 0, 0);
	fdf_events(&mlx_ptr);
}
	// put_map_to_img(map, image);
	// fdf_create_mash(image, vec);
