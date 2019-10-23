/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:41:37 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 23:06:25 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#undef MLX_PTR
#undef MLX_WIN
#define MLX_PTR	mlx_ptr->mlx_ptr
#define MLX_WIN mlx_ptr->mlx_win

static int	key_press(int key, void *param)
{
	P_UNUSED(param);
	if (key == FDF_ESC)
		exit(EXIT_SUCCESS);
	else if (key == FDF_LEFT_ARROW)
		;
	else if (key == FDF_RIGHT_ARROW)
		;
	else if (key == FDF_UP_ARROW)
		;
	else if (key == FDF_DOWN_ARROW)
		;
	return (SUCCESS);
}

static int	red_button(void *param)
{
	P_UNUSED(param);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	P_UNUSED(x);
	P_UNUSED(y);
	P_UNUSED(param);
	if (button == FDF_LEFT_BUTTON)
		;
	else if (button == FDF_RIGHT_BUTTON)
		;
	else if (button == FDF_MIDDLE_BUTTON)
		;
	else if (button == FDF_SCROLL_DOWN)
		;
	else if (button == FDF_SCROLL_UP)
		;
	else if (button == FDF_SCROLL_LEFT)
		;
	else if (button == FDF_SCROLL_RIGHT)
		;
	return (SUCCESS);
}

static int	mouse_mov(int x, int y, void *param)
{
	P_UNUSED(x);
	P_UNUSED(y);
	P_UNUSED(param);
	return (SUCCESS);
}

void		fdf_events(struct s_ptr *mlx_ptr)
{
	mlx_hook(MLX_WIN, FDF_KEY_PRESS, FDF_NOT_WORK, key_press, NULL);
	mlx_hook(MLX_WIN, FDF_RED_BUTTON, FDF_NOT_WORK, red_button, NULL);
	mlx_hook(MLX_WIN, FDF_MOUSE_BUTTON_PRESS, FDF_NOT_WORK, mouse_press, NULL);
	mlx_hook(MLX_WIN, FDF_MOUSE_MOVEMENT, FDF_NOT_WORK, mouse_mov, NULL);
	mlx_loop(MLX_PTR);
}
