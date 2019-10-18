/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 22:42:22 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_press(int key, void *param)
{
	if (key == FDF_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

static int		close_win(void *param)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	fdf_work_window(vec3 *vec) //!Может быть будет еще что-то принимать
{
	struct s_ptr	ptr;

	MLX_PTR = mlx_init();
	MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, PROG_NAME);
	fdf_events(&ptr);
	// mlx_hook(MLX_WIN, FDF_KEY_PRESS, FDF_X_MASK, key_press, NULL);
	// mlx_hook(MLX_WIN, FDF_RED_BUTTON, FDF_X_MASK, close_win, NULL);
	// mlx_loop(MLX_PTR);
}
