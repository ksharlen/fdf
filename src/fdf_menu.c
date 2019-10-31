/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:14:30 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 13:23:54 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#undef COLOR
#define COLOR mlx->menu.color

#define DFLT_P			0

#define P_ZOOM_UP 		0
#define P_ZOOM_DOWN 	20 * 2

#define P_MOV_UP 		40 * 2
#define P_MOV_DOWN 		60 * 2
#define P_MOV_LEFT 		80 * 2
#define P_MOV_RIGHT 	100 * 2

#define P_ROT_X_L 		120 * 2
#define P_ROT_X_R 		140 * 2
#define P_Y_L 			160 * 2
#define P_Y_R 			180 * 2
#define P_Z_L 			200 * 2
#define P_Z_R 			220 * 2

#define FDF_P_RESET_IMG	240 * 2
#define FDF_P_IZOMETR	260 * 2

void	fdf_menu(t_mlx *mlx)
{
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_ZOOM_UP, COLOR, FDF_ZOOM_UP);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_ZOOM_DOWN, COLOR, FDF_ZOOM_DOWN);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_MOV_UP, COLOR, FDF_MOV_UP);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_MOV_DOWN, COLOR, FDF_MOV_DOWN);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_MOV_LEFT, COLOR, FDF_MOV_LEFT);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_MOV_RIGHT, COLOR, FDF_MOV_RIGHT);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_ROT_X_L, COLOR, FDF_ROT_X_L);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_ROT_X_R, COLOR, FDF_ROT_X_R);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_Y_L, COLOR, FDF_ROT_Y_L);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_Y_R, COLOR, FDF_ROT_Y_R);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_Z_L, COLOR, FDF_ROT_Z_L);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, P_Z_R, COLOR, FDF_ROT_Z_R);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P,
		FDF_P_RESET_IMG, COLOR, FDF_RESET_IMG);
	mlx_string_put(MLX_PTR, MLX_WIN, DFLT_P, FDF_P_IZOMETR, COLOR, FDF_IZOMETR);
}
