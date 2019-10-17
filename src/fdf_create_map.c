/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:50:14 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/17 18:36:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_create_map(t_listfdf *beg, struct s_map *map)
{
	MAX_X = list_size(beg);
	MAX_Y = ft_num_words(beg->line, PART_STR);
	CHK_NULL_PTR(MAP = (t_map **)ft_memalloc(sizeof(t_map *) *
		(MAX_X * MAX_Y)), E_MALLOC, P_N);
}
