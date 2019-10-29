/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:41:54 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 15:44:23 by ksharlen         ###   ########.fr       */
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
			ft_printf("x: %d	y: %d\n", MAP[i * WIN_X + j].x, MAP[i * WIN_X + j]);
			++j;
		}
		++i;
	}
}