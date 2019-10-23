/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:58:21 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 23:08:05 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			valid_file(const char *filename)
{
	enum e_err	err;
	int			fd;
	ssize_t		byte_read;

	err = FAILURE;
	if (filename && *filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd != FAILURE)
		{
			err = SUCCESS;
			FDF_CHK_ERR(byte_read = read(fd, FDF_CHK_FILE, 0), FDF_NOT_VALID);
			CHK_SYS_ERR_EXT(close(fd), E_CLOSE, P_N);
		}
		else
			FDF_PRINT_ERR(FDF_NOT_VALID);
	}
	return (err);
}

int					fdf_valid_arg(const int argc, char *const argv[])
{
	enum e_err	err;

	err = FAILURE;
	if (argc == 1)
		FDF_PRINT_ERR(FDF_NO_ARG);
	else if (argc > 2)
		FDF_PRINT_ERR(FDF_TOO_MANY);
	else if (argc == 2)
		err = valid_file(FDF_MAP);
	return (err);
}
