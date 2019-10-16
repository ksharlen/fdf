/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:58:21 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/17 00:16:24 by ksharlen         ###   ########.fr       */
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
			FDF_CHK_ERR(byte_read = read(fd, NULL, 0), E_READ); //NULL видимо можно
			if (close(fd) == FAILURE)
				ft_err_exit(E_CLOSE, PROG_NAME);
		}
		else
			FDF_PRINT_ERR(FDF_NOT_VALID);
	}
	return (err);
}

int					fdf_valid_arg(const int argc, char *const argv[])
{
	enum e_err			err;

	err = FAILURE;
	if (argc == 1)
		FDF_PRINT_ERR(FDF_NO_ARG);
	else if (argc > 2)
		FDF_PRINT_ERR(FDF_TOO_MANY);
	else if (argc == 2)
		err = valid_file(FDF_MAP);
	return (err);
}
