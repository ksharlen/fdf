/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/20 20:48:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FDF");
	mlx_string_put(mlx_ptr, win_ptr, 100, 100, 0x1fa312, "Hello world");
	mlx_loop(mlx_ptr);
	return (0);
}
