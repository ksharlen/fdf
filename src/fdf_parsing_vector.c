/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:47:15 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/18 22:16:21 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_vectors(vec3 *vec, struct s_map *map)
{
	vec3	*p_vec;
	int		x;
	int		y;

	y = 0;
	p_vec = vec;
	while (y < MAX_Y && p_vec)
	{
		x = 0;
		while (x < MAX_X)
		{
			laInit3DVector(p_vec, (float)x, (float)y,
				(float)FDF_GET_HEIGHT_L(*(MAP + y * MAX_X + x)), NULL);
			++x;
			++p_vec;
		}
		++y;
	}
}

// static void	print_vector(vec3 *vec, int max_x, int max_y)
// {
// 	int i;

// 	i = 0;
// 	while (i < max_x * max_y)
// 	{
// 		printf("%f %f %f\n", vec->data[LA_X], vec->data[LA_Y], vec->data[LA_Z]);
// 		++i;
// 		++vec;
// 	}
// }

vec3		*fdf_parsing_vector(struct s_map *map)
{
	size_t	num_vectors;
	vec3	*vec;

	num_vectors = MAX_X * MAX_Y;
	CHK_NULL_PTR(vec = (vec3 *)ft_memalloc(sizeof(vec3) *
		num_vectors), E_MALLOC, P_N);
	fill_vectors(vec, map);
	// print_vector(vec, MAX_X, MAX_Y);
	return (vec);
}
