/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/28 23:24:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #define MATR_X matr->x_matr
// #define MATR_Y matr->y_matr
// #define MATR_Z matr->z_matr

// void	fdf_rot_coor(t_pixel *pix, float matr[3][3], float arr[3])
// {
// 	arr[0] = pix->x;
// 	arr[1] = pix->y;
// 	arr[2] = pix->z;
// 	arr[0] = matr[0][0] * arr[0] + matr[0][1] * arr[1] + matr[0][2] * arr[2];
// 	arr[1] = matr[1][0] * arr[0] + matr[1][1] * arr[1] + matr[1][2] * arr[2];
// 	arr[2] = matr[2][0] * arr[0] + matr[2][1] * arr[1] + matr[2][2] * arr[2];
// }

// static void	fdf_rot_x(int key, float matr[3][3])
// {
// 	float	radian;

// 	radian = ((key == FDF_NUM_4 ? ROT_LEFT : ROT_RIGHT));
// 	// matr_init(tmp);
// 	matr[0][0] = matr[0][0];//!Потом удалю
// 	matr[0][1] = matr[0][1] * cos(radian) + matr[0][2] * sin(radian);
// 	matr[0][2] = matr[0][1] * (-sin(radian)) + matr[0][2] * cos(radian);
// 	matr[1][0] = matr[1][0];
// 	matr[1][1] = matr[1][1] * cos(radian) + matr[1][2] * sin(radian);
// 	matr[1][2] = matr[1][1] * (-sin(radian)) + matr[1][2] * cos(radian);
// 	matr[2][0] = matr[2][0];
// 	matr[2][1] = matr[2][1] * cos(radian) + matr[2][2] * sin(radian);
// 	matr[2][2] = matr[2][1] * (-sin(radian)) + matr[2][2] * cos(radian);
// }

// static void	fdf_rot_y(int key, float matr[3][3])
// {
// 	P_UNUSED(key);
// 	P_UNUSED(matr);
// }

// static void	fdf_rot_z(int key, float matr[3][3])
// {
// 	P_UNUSED(key);
// 	P_UNUSED(matr);
// }

void	fdf_event_rad(int key, struct s_rad *rad)
{
	if (CHK_ROT_X(key))
		rad->rad_x += (key == FDF_NUM_4 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
	else if (CHK_ROT_Y(key))
		rad->rad_y += (key == FDF_NUM_8 ? FDF_ROT_UP : FDF_ROT_DOWN);
	else if (CHK_ROT_Z(key))
		rad->rad_z += (key == FDF_NUM_7 ? FDF_ROT_LEFT : FDF_ROT_RIGHT);
}
