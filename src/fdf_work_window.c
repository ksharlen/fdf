/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 21:31:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_mlx(t_mlx *mlx)
{
	FDF_CHK_NULL_PTR(MLX_PTR = mlx_init(), FDF_E_INIT);
	FDF_CHK_NULL_PTR(MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y,
					PROG_NAME), FDF_E_WIN);
	FDF_CHK_NULL_PTR(MLX_P_IMG = mlx_new_image(MLX_PTR, WIN_X, WIN_Y),
					FDF_E_IMG);
	FDF_CHK_NULL_PTR(MLX_IMG = (int *)mlx_get_data_addr(MLX_P_IMG,
					&FDF_BPP, &FDF_SL, &FDF_ENDI), FDF_E_IMG);
}

void			fdf_work_window(t_mlx *mlx)
{
	init_mlx(mlx);
	fdf_map_to_img(&mlx->map, MLX_IMG);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, 0, 0);
	fdf_events(mlx);
}
