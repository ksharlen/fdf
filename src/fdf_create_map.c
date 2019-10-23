/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:50:14 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 20:22:01 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static const char	*fill_elem(const char *file_line, t_map *elem)
// {
// 	char		*p_file_line;
// 	int			height;
// 	unsigned	color;

// 	*elem = 0;
// 	color = DFLT_COLOR;
// 	height = ft_atoi_base_ptr(file_line, DECIMAL, &p_file_line);
// 	if (p_file_line && *p_file_line == ',')
// 	{
// 		file_line = p_file_line + 1;
// 		if (p_file_line && *p_file_line)
// 			color = ft_atoi_base_ptr(file_line, HEX, &p_file_line);
// 	}
// 	*elem = FDF_SET_HC_L(*elem, height, color);
// 	return (p_file_line);
// }

// static void	fill_line(const int ind_line, const char *file_line, struct s_map *map)
// {
// 	size_t		j;
// 	const char	*curr_val;

// 	j = 0;
// 	curr_val = file_line;
// 	while (j < MAX_X && curr_val && *curr_val)
// 	{
// 		curr_val = fill_elem(curr_val, MAP + ind_line * MAX_X + j);
// 		++j;
// 	}
// }

// static void	print_map(struct s_map *map)
// {
// 	size_t		i;
// 	size_t		j;
// 	int			height;
// 	unsigned	color;

// 	i = 0;
// 	if (map)
// 	while (i < MAX_Y)
// 	{
// 		j = 0;
// 		while (j < MAX_X)
// 		{
// 			height = 0;
// 			color = 0;
// 			height = FDF_GET_HEIGHT_L(*(MAP + i * MAX_X + j));
// 			color = (unsigned)FDF_GET_COLOR_L(*(MAP + i * MAX_X + j));
// 			ft_printf("%d|%u		", height, color);
// 			++j;
// 		}
// 		ft_printf("\n");
// 		++i;
// 	}
// }

// static void	fill_map(const t_listfdf *beg, struct s_map *map)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < MAX_Y && beg)
// 	{
// 		fill_line(i, beg->line, map);
// 		beg = beg->next;
// 		++i;
// 	}
// }

static const char *fill_elem(const char *file_line, t_pixel *elem)
{
	elem->color = DFLT_COLOR;
	elem->z = ft_atoi_base_ptr(file_line, DECIMAL, (char **)&file_line);
	if (file_line && (*file_line == ','))
	{
		file_line++;
		if (file_line && (*file_line))
			elem->color = ft_atoi_base_ptr(file_line, HEX, (char **)&file_line);
	}
	return (file_line);
}

static void fill_line(const size_t i, const char *curr_line, t_map *map)
{
	size_t	j;

	j = 0;
	while (*curr_line && j < MAX_X)
	{
		curr_line = fill_elem(curr_line, MAP + MAX_X * i + j);
		++j;
	}
}

static void	fill_map(const t_listfdf *beg, t_map *map)
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

// static void	print_map(t_pixel *map, size_t max_x, size_t max_y)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < max_y)
// 	{
// 		j = 0;
// 		while (j < max_x)
// 		{
// 			ft_printf("%*u ", 10, map[i * max_x + j].color);
// 			++j;
// 		}
// 		ft_printf("\n");
// 		++i;
// 	}
// }

void		fdf_create_map(t_listfdf *beg, t_map *map)
{
	size_t	size_map;

	size_map = MAX_X * MAX_Y;
	CHK_NULL_PTR(MAP = (t_pixel *)ft_memalloc(sizeof(t_pixel) *
				(size_map)), E_MALLOC, P_N);
	fill_map(beg, map);
	// print_map(MAP, MAX_X, MAX_Y);
	// CHK_NULL_PTR(MAP = (t_map *)ft_memalloc(sizeof(t_map) *
	// 	(MAX_X * MAX_Y)), E_MALLOC, P_N);
	// fill_map(beg, map);
	// print_map(map);
}
