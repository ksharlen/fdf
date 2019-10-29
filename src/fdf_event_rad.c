/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/29 21:38:57 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_event_rad(int key, struct s_rad *rad)
{
	if (CHK_ROT_X(key))
		rad->rad_y += (key == FDF_NUM_4 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
	else if (CHK_ROT_Y(key))
		rad->rad_x += (key == FDF_NUM_8 ? FDF_ROT_DOWN : FDF_ROT_UP);
	else if (CHK_ROT_Z(key))
		rad->rad_z += (key == FDF_NUM_7 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
}
