/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_collect_height_not_zero.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:31:41 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 13:52:04 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	num_not_zero_height(t_pixel *pixel, size_t size_map)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (i < size_map)
	{
		if (pixel[i].z)
			++len;
		++i;
	}
	return (len);
}

void			collect_height(t_pixel *map, size_t size_map,
	struct s_height *height_not_zero)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size_map)
	{
		if (map[i].z)
		{
			if (map[i].color == FDF_DFLT_COLOR)
			{
				height_not_zero[j].color = &map[i].color;
				*height_not_zero[j].color = FDF_HEIGHT_COLOR;
			}
			height_not_zero[j++].z = &map[i].z;
		}
		++i;
	}
}

void			fdf_collect_height_not_zero(t_map *map)
{
	map->size_height_not_zero = num_not_zero_height(map->map, MAX_X * MAX_Y);
	CHK_NULL_PTR(map->height_not_zero = (struct s_height *)ft_memalloc(sizeof(struct s_height) *
		(map->size_height_not_zero + 1)), E_MALLOC, P_N);
	collect_height(MAP, MAX_X * MAX_Y, map->height_not_zero);
}
