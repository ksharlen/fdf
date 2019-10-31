/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:29:47 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 14:02:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_del_map(t_pixel **map)
{
	if (map && *map)
	{
		free(*map);
		*map = NULL;
	}
}

void	fdf_del_height_ptr(struct s_height **height)
{
	if (height && *height)
	{
		free(*height);
		*height = NULL;
	}
}
