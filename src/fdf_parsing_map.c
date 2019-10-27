/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:48:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/27 20:04:10 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MATR_X matr->x_matr
#define MATR_Y matr->y_matr
#define MATR_Z matr->z_matr

static void		valid_map(t_listfdf *beg)
{
	size_t	len_curr_line_map;
	size_t	len_next_line_map;

	len_curr_line_map = ft_num_words(beg->line, PART_STR);
	while (beg->next)
	{
		len_next_line_map = ft_num_words(beg->next->line, PART_STR);
		if (len_curr_line_map != len_next_line_map)
			FDF_PRINT_ERR_EXT(FDF_BAD_MAP);
		len_curr_line_map = len_next_line_map;
		beg = beg->next;
	}
}

static void		fdf_map_align(t_map *map)
{
	t_coord		center_win;
	t_coord		center_img;
	size_t		i;

	center_win.x = FDF_MIDDLE(WIN_X);
	center_win.y = FDF_MIDDLE(WIN_Y);
	center_img.x = FDF_MIDDLE(MAP[FDF_LAST_ELEM_MAP].x);
	center_img.y = FDF_MIDDLE(MAP[FDF_LAST_ELEM_MAP].y);
	i = 0;
	while (i < map->max_x * map->max_y)
	{
		MAP[i].x -= center_img.x;
		MAP[i].y -= center_img.y;
		++i;
	}
}

static void		fdf_init_matr(float matr[3][3])
{
	matr[0][0] = 1.0f;
	matr[0][1] = 0.0f;
	matr[0][2] = 0.0f;
	matr[1][0] = 0.0f;
	matr[1][1] = 1.0f;
	matr[1][2] = 0.0f;
	matr[2][0] = 0.0f;
	matr[2][1] = 0.0f;
	matr[2][2] = 1.0f;
}

static void		fdf_init_matrix(struct s_matr *matr)
{
	fdf_init_matr(MATR_X);
	fdf_init_matr(MATR_Y);
	fdf_init_matr(MATR_Z);
}

// static void		print_matr(float matr[3][3])
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		j = 0;
// 		while (j < 3)
// 		{
// 			printf("%f	", matr[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// 	printf("\n");
// }

enum e_err		fdf_parsing_map(t_listfdf *beg, t_map *map)
{
	valid_map(beg);
	FDF_GET_MAX_X(MAX_X, beg->line);
	FDF_GET_MAX_Y(MAX_Y, beg);
	fdf_init_matrix(&map->matr);
// print_matr(map->matr.x_matr);
// print_matr(map->matr.y_matr);
// print_matr(map->matr.z_matr);
// exit(EXIT_FAILURE);
	fdf_create_map(beg, map);
	map->scale = FDF_DFLT_SCALE;
	map->shift_x = FDF_DFLT_SHIFT_X;
	map->shift_y = FDF_DFLT_SHIFT_Y;
	fdf_fit_screen_map(map);
	fdf_map_align(map);
	return (SUCCESS);
}
