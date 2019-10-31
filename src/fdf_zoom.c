/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:21:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 15:32:09 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	in_window(t_map *map)
{
	t_pixel	*last_elem;
	t_coord	need_zoom;

	need_zoom.x = (ssize_t)round(WIN_X - (WIN_X / 3));
	need_zoom.y = (ssize_t)round(WIN_Y - (WIN_Y / 3));
	last_elem = &MAP[FDF_LAST_ELEM_MAP];
	while ((last_elem->x * (int)map->scale) < need_zoom.x &&
		(last_elem->y * (int)map->scale) < need_zoom.y)
		map->scale = map->scale * FDF_ZOOM_IN;
}

static void	out_window(t_map *map)
{
	t_coord	max_map;

	max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	while (((max_map.x * map->scale) > (ssize_t)MAX_X) ||
		(max_map.y * map->scale) > (ssize_t)MAX_Y)
		map->scale *= FDF_ZOOM_OUT;
}

void		fdf_fit_screen_map(t_map *map)
{
	t_coord	max_coor_map;

	max_coor_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_coor_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	if (max_coor_map.x < (ssize_t)(WIN_X / 2) &&
		max_coor_map.y < (ssize_t)(WIN_Y / 2))
		in_window(map);
	else if (max_coor_map.x > WIN_X || max_coor_map.y > WIN_Y)
		out_window(map);
}
