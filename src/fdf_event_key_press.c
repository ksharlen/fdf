/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 15:05:20 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SCALE	*scale

void	fdf_event_projection(int key, struct s_rad *rad)
{
	if (key == FDF_I)
	{
		FDF_RAD_X = -0.662680f;
		FDF_RAD_Y = 0.945437f;
		FDF_RAD_Z = -0.662680f;
	}
	else if (key == FDF_P)
		fdf_init_rad(rad);
}

void	fdf_event_height(int key, struct s_height *height_not_zero,
	size_t size_height)
{
	size_t	i;
	int		value;

	i = 0;
	value = (key == FDF_UP_ARROW ? 1 : -1);
	while (i < size_height)
	{
		if (height_not_zero[i].z)
			*height_not_zero[i].z += value;
		++i;
	}
}

void	fdf_event_scale(int key, float *scale)
{
	if (key == FDF_NUM_KEY_PLS)
		SCALE *= FDF_ZOOM_IN;
	else if (key == FDF_NUM_KEY_SUB)
		SCALE *= FDF_ZOOM_OUT;
}

void	fdf_event_shift(int key, struct s_shift *shift)
{
	if (key == FDF_A)
		FDF_SHIFT_X -= FDF_SHIFT;
	else if (key == FDF_D)
		FDF_SHIFT_X += FDF_SHIFT;
	else if (key == FDF_W)
		FDF_SHIFT_Y -= FDF_SHIFT;
	else if (key == FDF_S)
		FDF_SHIFT_Y += FDF_SHIFT;
}

void	fdf_event_rad(int key, struct s_rad *rad)
{
	if (CHK_ROT_X(key))
		FDF_RAD_Y += (key == FDF_NUM_4 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
	else if (CHK_ROT_Y(key))
		FDF_RAD_X += (key == FDF_NUM_8 ? FDF_ROT_DOWN : FDF_ROT_UP);
	else if (CHK_ROT_Z(key))
		FDF_RAD_Z += (key == FDF_NUM_7 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
}
