/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 19:33:50 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void		fill_image(struct s_map *map, int *image)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < MAX_Y)
// 	{
// 		j = 0;
// 		while (j < MAX_X)
// 		{
// 			*(image + (i * WIN_X) + j) = (int)FDF_GET_FAST_COLOR_L(*(MAP + i * MAX_X + j));
// 			++j;
// 		}
// 		++i;
// 	}
// }

int		main(int argc, char **argv)
{
	t_listfdf		*beg;
	t_map			map;

	if (fdf_valid_arg(argc, argv) == SUCCESS)
	{
		beg = NULL;
		if ((beg = fdf_read_file(FDF_MAP)))
		{
			fdf_parsing_map(beg, &map);
			list_delete(&beg);
			// fdf_test_window(&map);
			// fdf_create_map(beg, &map);
			// print_lines(beg);
			// creating_map(beg);
			// list_delete(&beg);
		}
	}
	return (0);
}
