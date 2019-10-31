/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 15:02:01 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_pix_in_to_win(t_pixel *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

void			fdf_line_create(int *img, t_pixel beg,
	t_pixel *end, t_pixel begin)
{
	struct s_line_create brain;

	brain.delta.dx = abs(end->x - beg.x);
	brain.sx = beg.x < end->x ? 1 : -1;
	brain.delta.dy = -abs(end->y - beg.y);
	brain.sy = beg.y < end->y ? 1 : -1;
	brain.err = brain.delta.dx + brain.delta.dy;
	while (FDF_INF)
	{
		if (check_pix_in_to_win(&beg) == SUCCESS)
			FDF_PIXEL_COLOR = fdf_gradient(&begin, &beg, end, &brain.delta);
		if (beg.x == end->x && beg.y == end->y)
			break ;
		brain.e2 = 2 * brain.err;
		if (brain.e2 >= brain.delta.dy)
		{
			brain.err += brain.delta.dy;
			beg.x += brain.sx;
		}
		if (brain.e2 <= brain.delta.dx)
		{
			brain.err += brain.delta.dx;
			beg.y += brain.sy;
		}
	}
}
