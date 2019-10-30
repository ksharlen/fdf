/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_collect_height_not_zero.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:31:41 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/30 17:58:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	num_not_zero_height(t_pixel *pixel, size_t	size_map)
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

void			collect_height(t_pixel *map, size_t	size_map, int **height_not_zero)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size_map)
	{
		if (map[i].z)
			height_not_zero[j++] = &map[i].z;
		++i;
	}
}

void	fdf_collect_height_not_zero(t_map *map)
{
	size_t	len_height_not_zero;

	len_height_not_zero = num_not_zero_height(map->map, MAX_X * MAX_Y);
	CHK_NULL_PTR(map->height_not_zero = (int **)ft_memalloc(sizeof(int *) *
		(len_height_not_zero + 1)), E_MALLOC, P_N);
	map->height_not_zero[len_height_not_zero] = NULL;
	collect_height(MAP, MAX_X * MAX_Y, map->height_not_zero);
}