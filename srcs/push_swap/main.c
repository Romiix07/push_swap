/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:33:25 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

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
	if (!convert(tab, &lista, get_tab_size(ac, av)))
	{
		free(tab);
		return (return_error("Malloc of linked list\n"));
	}
	free(tab);
	push_swap(lista, listb, get_tab_size(ac, av));
	free_list(&lista);
	free_list(&listb);
	return (1);
}
