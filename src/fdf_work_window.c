/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 20:54:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_map_to_img(t_map *map, int *img)
{
	
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
	// put_map_to_img(map, image);
	// fdf_create_mash(image, vec);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_IMG, 0, 0);
	fdf_events(&mlx_ptr);
}
