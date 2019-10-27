/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/27 23:27:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_pix_in_to_win(t_coord *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

void	fdf_line_create(int *img, t_coord *beg, t_coord *end)
{
	int A;
	int	B;
	int	sign;
	int signa;
	int	signb;
	int f = 0;
	t_coord	curr;

	A = end->y - beg->y;
	B = beg->x - end->x;

	if (FT_ABS(A) > FT_ABS(B))
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
			printf("here\n");
			f += A * signa;
			if (f > 0)
			{
				f -= B * signb;
				curr.y += signa;
			}
			curr.x -= signb;
			if (check_pix_in_to_win(&curr) == SUCCESS)
				*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
		} while (curr.x != end->x && curr.y != end->y);
	}
	else
	{
		do
		{
			f += B * signb;
			if (f > 0)
			{
				f -= A * signa;
				curr.x -= signb;
			}
			curr.y += signa;
			if (check_pix_in_to_win(&curr) == SUCCESS)
				*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
		} while (curr.x != end->x && curr.y != end->y);
	}
}