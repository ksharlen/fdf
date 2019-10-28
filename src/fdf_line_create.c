/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/28 19:06:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(x) ((x) >= 0 ? (x) : -(x))

static int		check_pix_in_to_win(t_coord *coor)
{
	if ((coor->x < WIN_X) && (coor->y < WIN_Y) &&
		((coor->x >= 0) && (coor->y >= 0)))
		return (SUCCESS);
	return (FAILURE);
}

// void	fdf_line_create(int *img, t_coord beg, t_coord end)
// {
// 	t_coord	curr;
// 	// int x;
// 	// int y;
// 	int dx;
// 	int dy;
// 	int d;
// 	int d1;
// 	int d2;

// 	dx = end.x - beg.x;
// 	dy = end.y - beg.y;
// 	d = (dy << 1) - dx;
// 	d1 = dy << 1;
// 	d2 = (dy - dx) << 1;
// 	curr.x = beg.x;
// 	curr.y = beg.y;
// 	if (check_pix_in_to_win(&beg) == SUCCESS)
// 		*(img + WIN_X * beg.y + beg.x) = FDF_DFLT_COLOR;
// 	if (check_pix_in_to_win(&end) == SUCCESS)
// 		*(img + WIN_X * end.y + end.x) = FDF_DFLT_COLOR;
// 	--end.x;
// 	while (curr.x < end.x)
// 	{
// 		++curr.x;
// 		if (d < 0)
// 			d += d1;
// 		else
// 		{
// 			++curr.y;
// 			d += d2;
// 		}
// 		if (check_pix_in_to_win(&curr) == SUCCESS)
// 			*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
// 	}
// }

void	fdf_line_create(int *img, t_coord beg, t_coord end)
{
	ssize_t A;
	ssize_t	B;
	ssize_t	sign;
	ssize_t signa;
	ssize_t	signb;
	ssize_t f = 0;
	t_coord	curr;

	A = end.y - beg.y;
	B = beg.x - end.x;

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
	if (check_pix_in_to_win(&beg) == SUCCESS)
		*(img + WIN_X * beg.y + beg.x) = FDF_DFLT_COLOR;
	curr.x = beg.x;
	curr.y = beg.y;
	// printf("beg.x: %zd\n", curr.x);
	// printf("beg.y: %zd\n", curr.y);
	if (sign == -1)
	{
		do
		{
			// printf("end.x: %zd\n", end.x);
			// printf("end.y: %zd\n", end.y);
			// sleep(1);
			// printf("curr.x: %zd\n", curr.x);
			// printf("curr.y: %zd\n", curr.y);
			f = f + A * signa;
			if (f > 0)
			{
				f = f - B * signb;
				curr.y = curr.y + signa;
			}
			curr.x = curr.x - signb;
			if (check_pix_in_to_win(&curr) == SUCCESS)
				*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
		}
		while (curr.x != end.x || curr.y != end.y);
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
				*(img + WIN_X * curr.y + curr.x) = FDF_DFLT_COLOR;
		}
		while (curr.x != end.x || curr.y != end.y);
	}
}