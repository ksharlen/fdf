/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:21:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/24 20:50:07 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_fit_screen_map(t_map *map)
{
	t_coord	max_coor_map;

	max_coor_map.x = MAP[MAX_X * MAX_Y - 1].x;
	max_coor_map.y = MAP[MAX_X * MAX_Y - 1].y;
	if (max_coor_map.x < WIN_X / 2 && max_coor_map.y < WIN_Y / 2)//!Тут подумать
		fdf_in_window(map);
	else if (max_coor_map.x > WIN_X || max_coor_map.y > WIN_Y)
		fdf_out_window(map);
}

void	fdf_in_window(t_map *map)
{
	t_coord	max_map;
	t_coord	need_zoom;

	need_zoom.x = (int)round(WIN_X - (WIN_X / 3));
	need_zoom.y = (int)round(WIN_Y - (WIN_Y / 3));
	max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	while (max_map.x < need_zoom.x || max_map.y < need_zoom.y)
	{
		fdf_zooming(map, FDF_ZOOM_IN);
		max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
		max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	}
}

void	fdf_out_window(t_map *map)
{
	t_coord	max_map;

	max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	while (max_map.x > MAX_X || max_map.y > MAX_Y)
	{
		fdf_zooming(map, FDF_ZOOM_OUT);
		max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
		max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	}
}

void	fdf_zooming(t_map *map, const float zoom)
{
	size_t	i;

	i = 0;
	while (i < MAX_X * MAX_Y - 1)
	{
		MAP->x = (int)round(MAP->x * zoom);
		MAP->y = (int)round(MAP->y * zoom);
		MAP->z = (int)round(MAP->z * zoom);
		++i;
	}
}
