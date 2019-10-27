/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_matr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:37:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/27 23:20:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MATR_X matr->x_matr
#define MATR_Y matr->y_matr
#define MATR_Z matr->z_matr

void	fdf_rot_coor(t_pixel *pix, float matr[3][3], float arr[3])
{
	arr[0] = pix->x;
	arr[1] = pix->y;
	arr[2] = pix->z;
	arr[0] = matr[0][0] * arr[0] + matr[0][1] * arr[1] + matr[0][2] * arr[2];
	arr[1] = matr[1][0] * arr[0] + matr[1][1] * arr[1] + matr[1][2] * arr[2];
	arr[2] = matr[2][0] * arr[0] + matr[2][1] * arr[1] + matr[2][2] * arr[2];
}

static void	fdf_rot_x(int key, float matr[3][3])
{
	float	radian;

	radian = ((key == FDF_NUM_4 ? ROT_LEFT : ROT_RIGHT));
	// matr_init(tmp);
	matr[0][0] = matr[0][0];//!Потом удалю
	matr[0][1] = matr[0][1] * cos(radian) + matr[0][2] * sin(radian);
	matr[0][2] = matr[0][1] * (-sin(radian)) + matr[0][2] * cos(radian);
	matr[1][0] = matr[1][0];
	matr[1][1] = matr[1][1] * cos(radian) + matr[1][2] * sin(radian);
	matr[1][2] = matr[1][1] * (-sin(radian)) + matr[1][2] * cos(radian);
	matr[2][0] = matr[2][0];
	matr[2][1] = matr[2][1] * cos(radian) + matr[2][2] * sin(radian);
	matr[2][2] = matr[2][1] * (-sin(radian)) + matr[2][2] * cos(radian);
}

static void	fdf_rot_y(int key, float matr[3][3])
{
	P_UNUSED(key);
	P_UNUSED(matr);
}

static void	fdf_rot_z(int key, float matr[3][3])
{
	P_UNUSED(key);
	P_UNUSED(matr);
}

void	fdf_event_matr(int key, struct s_matr *matr)
{
	if (CHK_ROT_X(key))
		fdf_rot_x(key, MATR_X);
	else if (CHK_ROT_Y(key))
		fdf_rot_y(key, MATR_Y);
	else if (CHK_ROT_Z(key))
		fdf_rot_z(key, MATR_Z);
}
