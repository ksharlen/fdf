/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 17:38:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

struct s_cfg_image g_img;

static void		init_mlx(t_mlx *mlx)
{
	FDF_CHK_NULL_PTR(MLX_PTR = mlx_init(), FDF_E_INIT);
	FDF_CHK_NULL_PTR(MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y,
					PROG_NAME), FDF_E_WIN);
	FDF_CHK_NULL_PTR(MLX_P_IMG = mlx_new_image(MLX_PTR, WIN_X, WIN_Y),
					FDF_E_IMG);
	FDF_CHK_NULL_PTR(MLX_IMG = (int *)mlx_get_data_addr(MLX_P_IMG,
					&g_img.bits_per_pixel, &g_img.size_line, &g_img.endian), FDF_E_IMG);
}

void			fdf_work_window(t_mlx *mlx) //!Может быть будет еще что-то принимать
{
	init_mlx(mlx);
	fdf_map_to_img(&mlx->map, MLX_IMG);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, 0, 0);
	fdf_events(mlx);
}
