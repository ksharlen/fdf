/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:21:44 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 15:27:22 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_listfdf	*fdf_read_file(const char *filename)
{
	t_listfdf		*beg;
	struct s_gnl	gnl;
	int				fd;

	beg = NULL;
	CHK_SYS_ERR_EXT(fd = open(filename, O_RDONLY), E_OPEN, P_N);
	while ((gnl.ret = get_next_line(fd, &gnl.line, FLAG_OFF)))
	{
		FDF_CHK_ERR(gnl.ret, E_MALLOC);
		fdf_list_add_end(&beg, gnl.line);
	}
	get_next_line(fd, NULL, FLAG_ON);
	CHK_SYS_ERR_EXT(close(fd), E_CLOSE, P_N);
	return (beg);
}
