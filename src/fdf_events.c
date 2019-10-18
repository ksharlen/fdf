/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:41:37 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 22:46:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#undef MLX_PTR
#undef MLX_WIN
#define MLX_PTR	ptr->mlx_ptr
#define MLX_WIN ptr->mlx_win

static void	key_press(int key, void *param)
{
	if (key == FDF_ESC)
		exit(EXIT_SUCCESS);
}

static void	red_button(void *param)
{
	exit(EXIT_SUCCESS);
}

void	fdf_events(struct s_ptr *ptr)
{
	mlx_hook(MLX_WIN, FDF_KEY_PRESS, FDF_X_MASK, key_press, NULL); //Подупать над param
	mlx_hook(MLX_WIN, FDF_RED_BUTTON, FDF_X_MASK, red_button, NULL);
	mlx_loop(MLX_PTR);
}
