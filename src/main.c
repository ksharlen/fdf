/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/17 00:10:07 by ksharlen         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_listfdf		*beg;
	struct s_map	map;

	if (fdf_valid_arg(argc, argv) == SUCCESS)
	{
		beg = NULL;
		if ((beg = fdf_read_file(FDF_MAP)))
		{
			fdf_parsing_map(beg);
			fdf_create_map(beg, &map);
			// print_lines(beg);
			// creating_map(beg);
			// list_delete(&beg);
		}
	}
	return (0);
}
