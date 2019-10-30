/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/30 17:02:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SHIFT_X shift->shift_x
#define SHIFT_Y shift->shift_y
#define SCALE	*scale

void	fdf_event_height(int key, int **height_not_zero)
{
	int value;

	value = (key == FDF_UP_ARROW ? 1 : -1);
	while (*height_not_zero)
	{
		if (**height_not_zero)
			**height_not_zero += value;
		++height_not_zero;
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
		SHIFT_X -= FDF_SHIFT;
	else if (key == FDF_D)
		SHIFT_X += FDF_SHIFT;
	else if (key == FDF_W)
		SHIFT_Y -= FDF_SHIFT;
	else if (key == FDF_S)
		SHIFT_Y += FDF_SHIFT;
}

void	fdf_event_rad(int key, struct s_rad *rad)
{
	if (CHK_ROT_X(key))
		rad->rad_y += (key == FDF_NUM_4 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
	else if (CHK_ROT_Y(key))
		rad->rad_x += (key == FDF_NUM_8 ? FDF_ROT_DOWN : FDF_ROT_UP);
	else if (CHK_ROT_Z(key))
		rad->rad_z += (key == FDF_NUM_7 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
}
