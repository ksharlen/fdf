/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:50:30 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/16 22:53:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		list_size(t_listfdf *beg)
{
	size_t	list_size;

	list_size = 0;
	if (beg)
		while (beg)
			++list_size && (beg = beg->next);
	return (list_size);
}

void		list_delete(t_listfdf **beg)
{
	t_listfdf	*curr;
	t_listfdf	*tmp;

	curr = (*beg);
	while (curr)
	{
		tmp = curr->next;
		ft_strdel(&curr->line);
		free(curr);
		curr = tmp;
	}
	*beg = NULL;
}

t_listfdf	*list_create(char *line)
{
	t_listfdf	*new;

	new = NULL;
	if (line)
	{
		new = (t_listfdf *)ft_memalloc(sizeof(t_listfdf));
		if (!new)
			ft_err_exit(E_MALLOC, "fdf");
		new->line = line;
		new->size_line = ft_strlen(line);
		new->next = NULL;
	}
	return (new);
}

void		list_add_end(t_listfdf **beg, char *line)
{
	t_listfdf	*new;
	t_listfdf	*res;

	if (beg)
	{
		new = list_create(line);
		if (*beg)
		{
			res = (*beg);
			while (res->next)
				res = res->next;
			res->next = new;
		}
		else
			(*beg) = new;
	}
}
