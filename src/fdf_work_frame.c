/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:28 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 15:45:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FDF_BEG_X 0
#define FDF_BEG_Y 0

#define X elem->x
#define Y elem->y
#define Z elem->z

#define RAD_X rad->rad_x
#define RAD_Y rad->rad_y
#define RAD_Z rad->rad_z

#define SHIFT_X shift->shift_x
#define SHIFT_Y shift->shift_y

// static int		check_pix_in_to_win(t_coord *coor)
// {
// 	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
// 		((coor->x >= 0) && (coor->y >= 0)))
// 		return (SUCCESS);
// 	return (FAILURE);
// }

static t_coord	fdf_rot(t_pixel *elem, struct s_rad *rad, float *scale, struct s_shift *shift)
{
	t_coord	coord;

	coord.x = (X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X)) * sin(RAD_Y))
				* cos(RAD_Z) - (Y * cos(RAD_X) + Z * sin(RAD_X)) * sin(RAD_Z);
	coord.y = -(X * cos(RAD_Y) + (-Y * sin(RAD_X) + Z * cos(RAD_X)) * sin(RAD_Y))
				* sin(RAD_Z) + (Y * cos(RAD_X) + Z * sin(RAD_X)) * cos(RAD_Z);
	coord.x = coord.x * (int)round(*scale) + SHIFT_X;
	coord.y = coord.y * (int)round(*scale) + SHIFT_Y;
	return (coord);
}

void				fdf_map_to_img(t_map *map, int *img)
{
	print_map(map);
	exit(EXIT_FAILURE);
	// t_coord beg;
	// t_coord end;

	// P_UNUSED(map);
	// beg.x = 0;
	// beg.y = 0;

	// end.x = 0;
	// end.y = 0;
	// fdf_line_create(img, &beg, &end);
	// t_coord	curr_pix;
	// t_coord	next_pix;
	// t_coord up_pix;
	// // float	arr[3];
	// size_t	i;
	// size_t	j;

	// i = 0;
	// while (i < MAX_Y - 1)
	// {
	// 	j = 0;
	// 	while (j < MAX_X - 1)
	// 	{
	// 		// curr_pix = fdf_rot(&MAP[i * WIN_X + j], &map->rad, &map->scale, &map->shift);
	// 		// printf("curr_pix.x: %d\n", MAP[i * WIN_X + j].x);
	// 		// printf("curr_pix.y: %d\n", MAP[i * WIN_X + j].y);
	// 		// exit(EXIT_FAILURE);
	// 		// if (j + 1 != MAX_X)
	// 		// {
	// 			// next_pix = fdf_rot(&MAP[i * WIN_X + (j + 1)], &map->rad, &map->scale, &map->shift);
	// 			// fdf_line_create(img, &curr_pix, &next_pix);
	// 		// }
	// 		++j;
	// 	}
	// 	++i;
	}
	// while (i < MAX_Y / 2)
	// {
	// 	j = 0;
	// 	while (j < MAX_X / 2)
	// 	{
	// 		// fdf_rot_coor(&MAP[i * MAX_X + j], map->matr.x_matr, arr);
	// 		// curr_pix.x = (int)round(arr[0] * map->scale) + map->shift_x;
	// 		// curr_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
	// 		// curr_pix = fdf_rot(&MAP[i * MAX_X + j], &map->rad, &map->scale, &map->shift);
	// 		// if (j + 1 != MAX_X / 2)
	// 		// {
	// 		// 	next_pix = fdf_rot(&MAP[i * MAX_X + j + 1], &map->rad, &map->scale, &map->shift);
	// 		// 	// printf("haha\n");
	// 		// 	if (curr_pix.x > 0 && curr_pix.x < WIN_X && curr_pix.y > 0 && curr_pix.y < WIN_Y &&
	// 		// 		(next_pix.x > 0 && next_pix.y < WIN_X && next_pix.y > 0 && next_pix.y < WIN_Y))
	// 		// 	fdf_line_create(img, &curr_pix, &next_pix);
	// 		// 	// fdf_rot_coor(&MAP[i * MAX_X + j + 1], map->matr.x_matr, arr);
	// 		// 	// next_pix.x = (int)round(arr[0] * map->scale) + map->shift_x;
	// 		// 	// next_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
	// 		// }
	// 		// if (i > 0)
	// 		// {
	// 		// 	up_pix = fdf_rot(&MAP[(i - 1) * MAX_X + j], &map->rad, &map->scale, &map->shift);
	// 		// 	// fdf_rot_coor(&MAP[(i - 1) * MAX_X + j], map->matr.x_matr, arr);
	// 		// 	// up_pix.x = curr_pix.x;
	// 		// 	// up_pix.y = (int)round(arr[1] * map->scale) + map->shift_y;
	// 		// 	if (curr_pix.x > 0 && curr_pix.x < WIN_X && curr_pix.y > 0 && curr_pix.y < WIN_Y &&
	// 		// 		(next_pix.x > 0 && next_pix.y < WIN_X && next_pix.y > 0 && next_pix.y < WIN_Y))
	// 		// 	fdf_line_create(img, &curr_pix, &up_pix);
	// 		// }
	// 		++j;
	// 	}
	// 	++i;

void			fdf_work_frame(t_mlx *mlx)
{
	// printf("here\n");
	mlx_clear_window(MLX_PTR, MLX_WIN);
	ft_bzero(mlx->img, WIN_X * WIN_Y * 4);
	fdf_map_to_img(&mlx->map, mlx->img);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_P_IMG, FDF_BEG_X, FDF_BEG_Y);
}
