/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:48:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/25 18:50:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	// printf("here\n");
		MAP[i].x -= center_img.x;
		MAP[i].y -= center_img.y;
		// MAP[i].x += (center_win.x);
		// MAP[i].y += (center_win.y);
		++i;
	}
}

enum e_err		fdf_parsing_map(t_listfdf *beg, t_map *map)
{
	valid_map(beg);
	FDF_GET_MAX_X(MAX_X, beg->line);
	FDF_GET_MAX_Y(MAX_Y, beg);
	fdf_create_map(beg, map);
	map->scale = FDF_DFLT_SCALE;
	fdf_fit_screen_map(map);
	fdf_map_align(map);
	return (SUCCESS);
}
