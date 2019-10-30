/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:58:10 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/30 19:36:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percentage(int *beg, int *end, int *curr)
{
	double place;
	double distance;

	place = (*curr) - (*beg);
	distance = (*end) - (*beg);
	return ((distance == 0) ? 1.0 : (place / distance));
}

static int		get_light(int beg, int end, double *percent)
{
	return ((int)((1 - (*percent)) * beg + (*percent) * end));
}

int				fdf_gradient(t_pixel *beg, t_pixel *curr, t_pixel *end, struct s_delta *delta)
{
	struct s_color	color;
	double			percent;

	if (curr->color == end->color)
		return (curr->color);
	if (delta->dx > delta->dy)
		percent = percentage(&beg->x, &end->x, &curr->x);
	else
		percent = percentage(&beg->y, &end->y, &curr->y);
	color.red = get_light((beg->color >> 16) & 0xFF,
							(end->color >> 16) & 0xFF, &percent);
	color.green = get_light((beg->color >> 8) & 0xFF,
				(end->color >> 8) & 0xFF, &percent);
	color.blue = get_light(beg->color & 0xFF, end->color & 0xFF, &percent);
	return ((color.red << 16) | (color.green << 8) | color.blue);
}
