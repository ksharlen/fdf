/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:45:20 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 17:38:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mul_line(const size_t line, t_map *map)
{
	size_t	j;
	int		scale;

	j = 0;
	scale = map->scale;
	while (j < MAX_X)
	{
		MAP[line * MAX_X + j].x *= scale;
		MAP[line * MAX_X + j].y *= scale;
		MAP[line * MAX_X + j].z *= scale;
		++j;
	}
}

void		fdf_scale_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (i < MAX_Y)
		{
			mul_line(i, map);
			++i;
		}
	}
}
