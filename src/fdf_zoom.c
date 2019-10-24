/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:21:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/24 22:42:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_fit_screen_map(t_map *map)
{
	t_coord	max_coor_map;

	max_coor_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_coor_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	if (max_coor_map.x < (ssize_t)(WIN_X / 2) && max_coor_map.y < (ssize_t)(WIN_Y / 2))//!Тут подумать
		fdf_in_window(map);
	else if (max_coor_map.x > WIN_X || max_coor_map.y > WIN_Y)
		fdf_out_window(map);
}

void	fdf_in_window(t_map *map)
{
	t_pixel	*last_elem;
	t_coord	need_zoom;

	need_zoom.x = (ssize_t)round(WIN_X - (WIN_X / 3));
	need_zoom.y = (ssize_t)round(WIN_Y - (WIN_Y / 3));
	last_elem = &MAP[FDF_LAST_ELEM_MAP];
	while ((last_elem->x * (int)map->scale) < need_zoom.x && (last_elem->y * (int)map->scale) < need_zoom.y)
		map->scale = map->scale * FDF_ZOOM_IN;
}

void	fdf_out_window(t_map *map)
{
	t_coord	max_map;

	max_map.x = MAP[FDF_LAST_ELEM_MAP].x;
	max_map.y = MAP[FDF_LAST_ELEM_MAP].y;
	while (((max_map.x * map->scale) > (ssize_t)MAX_X) || (max_map.y * map->scale) > (ssize_t)MAX_Y)
		map->scale *= FDF_ZOOM_OUT;
}

void	fdf_zooming(t_map *map, const float zoom)
{
	size_t	i;

	P_UNUSED(zoom);
	P_UNUSED(map);
	i = 0;
	// printf("zoom: %f\n", zoom);
	// printf("max_X: %zu\n", map->max_x);
	// printf("max_Y: %zu\n", map->max_y);
	// while (i < MAX_X * MAX_Y)
	// {
		// printf("x: %5d y: %5d z: %5d\n", MAP->x, MAP->y, MAP->z);
		// MAP[i].x = MAP[i].x * zoom;
		// MAP[i].y = MAP[i].y * zoom;
		// MAP[i].z = (int)round((float)MAP->z * zoom);
		// printf("MAP->x: %d	MAP->y: %d	MAP->z: %d\n", MAP->x, MAP->y, MAP->z);
		// printf("lx: %5d ly: %5d lz: %5d\n", MAP->x, MAP->y, MAP->z);
		// if (i == 5)
			// exit(EXIT_FAILURE);
		// ++i;
	// }
}
