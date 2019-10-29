/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:54 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 17:06:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			ft_printf("x: %d	y: %d\n", MAP[i * MAX_X + j].x, MAP[i * MAX_X + j]);
			++j;
		}
		++i;
	}
}

void	print_map_ext(t_map *map)
{
	print_map(map);
	exit(EXIT_FAILURE);
}
