/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:50:14 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/24 22:26:38 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static const char	*fill_elem(const char *file_line,
								t_pixel *elem, size_t x, size_t y)
{
	elem->x = x;
	elem->y = y;
	elem->color = FDF_DFLT_COLOR;
	elem->z = ft_atoi_base_ptr(file_line, DECIMAL, (char **)&file_line);
	if (file_line && (*file_line == ','))
	{
		file_line++;
		if (file_line && (*file_line))
			elem->color = ft_atoi_base_ptr(file_line, HEX, (char **)&file_line);
	}
	return (file_line);
}

static void			fill_line(const size_t i, const char *curr_line, t_map *map)
{
	size_t	j;

	j = 0;
	while (*curr_line && j < MAX_X)
	{
		curr_line = fill_elem(curr_line, MAP + MAX_X * i + j, j, i);
		++j;
	}
}

static void			fill_map(const t_listfdf *beg, t_map *map)
{
	size_t	i;

	i = 0;
	while (beg && i < MAX_Y)
	{
		fill_line(i, beg->line, map);
		beg = beg->next;
		++i;
	}
}

void				fdf_create_map(t_listfdf *beg, t_map *map)
{
	size_t	size_map;

	size_map = MAX_X * MAX_Y;
	CHK_NULL_PTR(MAP = (t_pixel *)ft_memalloc(sizeof(t_pixel) *
				(size_map)), E_MALLOC, P_N);
	fill_map(beg, map);
}
