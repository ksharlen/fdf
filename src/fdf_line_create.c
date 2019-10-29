/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 17:37:29 by ksharlen         ###   ########.fr       */
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

static int	chk_cmp(int x1, int x2, int y1, int y2)
{
	if (x1 == x2)
	{
		if ((y1 == y2 && y1 == x1) || (y1 == y2))
			return (FAILURE);
	}
	return (SUCCESS);
}

void	fdf_line_create(int *img, t_coord *beg, t_coord *end)
{
	ssize_t A;
	ssize_t	B;
	ssize_t	sign;
	ssize_t signa;
	ssize_t	signb;
	ssize_t f = 0;
	t_coord	curr;

	if (chk_cmp(beg->x, end->x, beg->y, end->y) == SUCCESS)
	{
		A = end->y - beg->y;
		B = beg->x - end->x;

			if (ABS(A) > ABS(B))
				sign = 1;
			else
				sign = -1;
			if (A < 0)
				signa = -1;
			else
				signa = 1;
			if (B < 0)
				signb = -1;
			else
				signb = 1;
			if (check_pix_in_to_win(beg) == SUCCESS)
				*(img + WIN_X * beg->y + beg->x) = FDF_DFLT_COLOR;
			curr.x = beg->x;
			curr.y = beg->y;
			if (sign == -1)
			{
				do
				{
					f = f + A * signa;
					if (f > 0)
					{
						f = f - B * signb;
						curr.y = curr.y + signa;
					}
					curr.x = curr.x - signb;
					if (check_pix_in_to_win(&curr) == SUCCESS)
					{
						*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
					}
				} while ((curr.x < WIN_X) && (curr.x != end->x || curr.y != end->y));
			}
			else
			{
				do
				{
					f = f + B * signb;
					if (f > 0)
					{
						f = f - A * signa;
						curr.x = curr.x - signb;
					}
					curr.y = curr.y + signa;
					if (check_pix_in_to_win(&curr) == SUCCESS)
					{
						*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
					}
				} while (curr.x < WIN_X && (curr.x != end->x || curr.y != end->y));
			}
	}
}
