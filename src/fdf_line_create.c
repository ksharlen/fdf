/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 21:36:11 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define X1 beg->x
#define Y1 beg->y
#define X2 end->x
#define Y2 end->y

static int		check_pix_in_to_win(t_coord *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

void	fdf_line_create(int *img, t_coord beg, t_coord *end)
{
	int dx;
	int sx;
	int sy;
	int err;
	int dy;
	int e2;

	dx =  abs(end->x - beg.x);
	sx = beg.x < end->x ? 1 : -1;
	dy = -abs(end->y - beg.y);
	sy = beg.y < end->y ? 1 : -1;
    err = dx + dy;
    while (1)
    {
		if (check_pix_in_to_win(&beg) == SUCCESS)
			*(img + WIN_X * beg.y + beg.x) = FDF_DFLT_COLOR;
		if (beg.x == end->x && beg.y == end->y)
			break;
        e2 = 2 * err;
        if (e2 >= dy)
		{
			err += dy;
            beg.x += sx;
		}
        if (e2 <= dx)
        {
			err += dx;
            beg.y += sy;
		}
	}
}
