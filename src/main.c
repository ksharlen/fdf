/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 01:52:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	print_lines(t_listfdf *beg)
// {
// 	while (beg)
// 	{
// 		printf("%s\n", beg->line);
// 		// printf("%ld\n", beg->size_line);
// 		beg = beg->next;
// 	}
// }

static void		fill_image(struct s_map *map, int *image)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			*(image + i * WIN_X + j) = (int)FDF_GET_FAST_COLOR_L(*(MAP + i * MAX_X + j));
			++j;
		}
		++i;
	}
}

// static void		test_fill_image(int *image)
// {
// 	size_t	x;
// 	size_t	y;

// 	y = 300;
// 	x = 0;
// 	while (x < WIN_X)
// 	{
// 		*(image + x * WIN_Y + y) = 0x00ff00;
// 		++x;
// 	}
// }

int		key_hook(int key, char *test)
{
	P_UNUSED(test);

	if (key == 0x35)
		exit(EXIT_FAILURE);
	return (key);
}

static void		fdf_test_window(struct s_map *map)
{
	struct s_ptr		ptr;
	struct s_cfg_image	cfg;
	int					*image;
	// int					key;

	if (map)
	{
		MLX_PTR = mlx_init();
		// key = mlx_key_hook(MLX_PTR, key_hook, "hello");
		MLX_WIN = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, PROG_NAME);
		MLX_IMG = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
		image = (int *)mlx_get_data_addr(MLX_IMG, &cfg.bits_per_pixel, &cfg.size_line, &cfg.endian);
		fill_image(map, image);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN, MLX_IMG, 0, 0);
		mlx_key_hook(MLX_WIN, key_hook, "hello");
		mlx_loop(MLX_PTR);
	}
}

int		main(int argc, char **argv)
{
	t_listfdf		*beg;
	struct s_map	map;

	if (fdf_valid_arg(argc, argv) == SUCCESS)
	{
		beg = NULL;
		if ((beg = fdf_read_file(FDF_MAP)))
		{
			fdf_parsing_map(beg, &map);
			list_delete(&beg);
			fdf_test_window(&map);
			// fdf_create_map(beg, &map);
			// print_lines(beg);
			// creating_map(beg);
			// list_delete(&beg);
		}
	}
	return (0);
}
