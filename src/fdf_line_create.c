/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:55:56 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 15:28:29 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ABS(x) ((x) >= 0 ? (x) : -(x))
// #define X 0
// #define Y 1

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

static int	chk_cmp(int x1, int x2, int y1, int y2)
{
	if (x1 == x2)
	{
		if (y1 == y2 && y1 == x1)
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
			// printf("beg.x: %zd\n", curr.x);
			// printf("beg.y: %zd\n", curr.y);
			if (sign == -1)
			{
				do
				{
					// printf("end.x: %zd\n", end.x);
					// printf("end.y: %zd\n", end.y);
					// sleep(1);
					printf("curr.x: %zd\n", curr.x);
					// printf("curr.y: %zd\n", curr.y);
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

//!

// static void	add_pixel(int *img, int x, int y, int color)
// {
// 	int pixel;

// 	if (x > 0 && x < WIN_X - 1000 && y > 0 && y < WIN_Y - 1000)
// 	{
// 		pixel = (x * g_img.bits_per_pixel / 8) + (y * g_img.size_line);
// 		img[pixel] = color;
// 		img[++pixel] = color >> 8;
// 		img[++pixel] = color >> 16;
// 		img[++pixel] = 0;
// 	}
// }

// static int	line_params(int delta[2], int sign[2], int error[2], int dots[4])
// {
// 	int len;

// 	delta[X] = abs(dots[X + 2] - dots[X]);
// 	delta[Y] = abs(dots[Y + 2] - dots[Y]);
// 	sign[X] = dots[X] < dots[X + 2] ? 1 : -1;
// 	sign[Y] = dots[Y] < dots[Y + 2] ? 1 : -1;
// 	error[0] = delta[X] - delta[Y];
// 	len = (int)round(sqrt(delta[X] * delta[X] + delta[Y] * delta[Y]));
// 	return (len);
// }

// // static void	draw_line(t_fdf *m, t_dots *coord0, t_dots *coord1, int dots[4])
// void		fdf_line_create(int *img, t_coord *beg, t_coord *end)
// {
// 	int delta[2];
// 	int sign[2];
// 	int error[2];
// 	int	dots[4];
// 	int len;
// 	int n;

// 	dots[0] = beg->x;
// 	dots[1] = beg->y;
// 	dots[2] = end->x;
// 	dots[3] = end->y;

// 	printf("b_x: %d		b_y: %d\n", beg->x, beg->y);
// 	printf("e_x: %d		e_y: %d\n", end->x, end->y);
// 	len = line_params(delta, sign, error, dots);
// 	n = 0;
// 	while (dots[X] != dots[X + 2] || dots[Y] != dots[Y + 2])
// 	{
// 		add_pixel(img, dots[X], dots[Y], FDF_DFLT_COLOR);
// 		error[1] = error[0] * 2;
// 		if (error[1] > -delta[Y])
// 		{
// 			error[0] -= delta[Y];
// 			dots[X] += sign[X];
// 		}
// 		if (error[1] < delta[X])
// 		{
// 			error[0] += delta[X];
// 			dots[Y] += sign[Y];
// 		}
// 	}
// 	add_pixel(img, dots[X + 2], dots[Y + 2], FDF_DFLT_COLOR);
// }