/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 22:16:51 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_listfdf		*beg;
	struct s_map	map;
	vec3			*vec;

	if (fdf_valid_arg(argc, argv) == SUCCESS)
	{
		beg = NULL;
		if ((beg = fdf_read_file(FDF_MAP)))
		{
			fdf_parsing_map(beg, &map);
			vec = fdf_parsing_vector(&map);
			fdf_work_window(vec);
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
