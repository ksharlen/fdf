/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/30 15:53:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define X1 beg->x
#define Y1 beg->y
#define X2 end->x
#define Y2 end->y

static int		check_pix_in_to_win(t_pixel *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

void			fdf_line_create(int *img, t_pixel beg, t_pixel *end)
{
	struct s_line_create brain;

	brain.dx = abs(end->x - beg.x);
	brain.sx = beg.x < end->x ? 1 : -1;
	brain.dy = -abs(end->y - beg.y);
	brain.sy = beg.y < end->y ? 1 : -1;
	brain.err = brain.dx + brain.dy;
	while (FDF_INF)
	{
		if (check_pix_in_to_win(&beg) == SUCCESS)
			*(img + WIN_X * beg.y + beg.x) = beg.color;
		if (beg.x == end->x && beg.y == end->y)
			break ;
		brain.e2 = 2 * brain.err;
		if (brain.e2 >= brain.dy)
		{
			brain.err += brain.dy;
			beg.x += brain.sx;
		}
		if (brain.e2 <= brain.dx)
		{
			brain.err += brain.dx;
			beg.y += brain.sy;
		}
	}
}
