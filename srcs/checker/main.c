/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:00:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:12:10 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "utils.h"

static int	check_init_tab(int ac, char **av, int **tab)
{
	if (ac < 2)
		return (return_error(0));
	if (get_tab_size(ac, av) == -1)
		return (return_error("Invalid numbers\n"));
	if (!(*tab = malloc(sizeof(int) * (get_tab_size(ac, av)))))
		return (return_error("Malloc of int tab\n"));
	if (!fill_tab(ac, av, tab))
	{
		free(*tab);
		return (return_error("Invalid argument\n"));
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		*tab;
	t_list	*lista;
	t_list	*listb;

	if (!check_init_tab(ac, av, &tab))
		return (0);
	if (!(init_lists(&lista, &listb)))
		return (0);
	if (!get_options(ac, av, lista, listb))
		return (free_list(0, tab));
	if (!convert(tab, &lista, get_tab_size(ac, av)))
		return (free_list(0, tab));
	free(tab);
	if (read_and_exec_lines(&lista, &listb, -1, 0) == 0)
		write(2, "Error\n", 6);
	else if (is_sorted(lista) == 0 || listb->head)
		write(lista->fd, "KO\n", 3);
	else
		write(lista->fd, "OK\n", 3);
	free_list(&lista, 0);
	return (free_list(&listb, 0));
}
