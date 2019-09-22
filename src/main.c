/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/22 16:01:30 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_escape(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(1);
	return(1);
}

int			fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
		return(fdf_escape(fdf));
	else
		return(0);
}

int			main(void)
{
	t_fdf	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "FDF");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 100, 100, 0x1fa312, "Hello world");
	mlx_key_hook(fdf.win_ptr, fdf_keys, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
