/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:17:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/22 14:20:58 by bnigellu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"
# include "keysymdef.h"

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;
#endif
