/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:45:48 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/10 18:55:44 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

static int	open_file(char **av, t_list *lista, t_list *listb)
{
	int fd;

	if (lista->fd != 1)
		return (1);
	if ((fd = open(av[2], O_CREAT | O_APPEND | O_WRONLY | O_TRUNC, S_IRUSR |
	S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
		return (0);
	lista->fd = fd;
	listb->fd = fd;
	return (1);
}

static void	set_lists(char *exec, t_list *lista, t_list *listb, int *i)
{
	lista->option = ft_strstr(exec, "checker") ? 0 : 1;
	listb->option = lista->option;
	lista->fd = 1;
	listb->fd = 1;
	lista->read = 0;
	*i = 0;
}

void		set_opt(t_list *lista, t_list *listb, int opt)
{
	lista->option = opt;
	listb->option = opt;
}

int			get_options(int ac, char **av, t_list *lista, t_list *listb)
{
	int i;

	set_lists(av[0], lista, listb, &i);
	if (ac > 2 && av[1][0] && av[1][0] == '-' && !ft_isdigit(av[1][1]))
		while (av[1][++i])
		{
			if (av[1][i] == 'v')
				set_opt(lista, listb, OPT_DEBUG);
			else if (av[1][i] == 'c')
				set_opt(lista, listb, OPT_COLOR);
			else if (av[1][i] == 'r')
				lista->read = 1;
			else if (av[1][i] == 'w')
			{
				if (!open_file(av, lista, listb))
					return (return_error("Can't open file\n"));
			}
			else
				return (return_error("Invalid option\n"));
		}
	return (1);
}
