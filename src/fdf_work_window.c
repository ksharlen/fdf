/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_work_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:17:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 23:00:03 by ksharlen         ###   ########.fr       */
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

void			fdf_work_window(vec3 *vec) //!Может быть будет еще что-то принимать
{
	struct s_ptr	mlx_ptr;

	MLX_PTR = mlx_init();
	MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, PROG_NAME);
	fdf_events(&mlx_ptr);
}
