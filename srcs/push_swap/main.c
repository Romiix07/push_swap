/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 02:26:44 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

static int	init_tab_list(t_list **lista, t_list **listb)
{
	(*lista)->tab = 0;
	(*listb)->tab = 0;
	if ((*lista)->option == 2 && (!((*lista)->tab = malloc(sizeof(int) * 4)) ||
		!((*listb)->tab = malloc(sizeof(int) * 4))))
	{
		if ((*lista)->tab)
			free((*lista)->tab);
		(*lista)->tab = 0;
		if ((*listb)->tab)
			free((*listb)->tab);
		(*listb)->tab = 0;
		free_list(lista);
		free_list(listb);
		return (0);
	}
	return (1);
}

static void	get_option(char *s, t_list *lista, t_list *listb)
{
	if (!ft_strcmp("-v", s))
	{
		lista->option = 2;
		listb->option = 2;
		return ;
	}
	else if (!ft_strcmp("-b", s))
	{
		lista->option = 3;
		listb->option = 3;
		return ;
	}
	lista->option = 1;
	listb->option = 1;
}

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
	get_option(av[1], lista, listb);
	if (!init_tab_list(&lista, &listb))
		return (return_error("Malloc of tabs in lists\n"));
	push_swap(lista, listb, get_tab_size(ac, av));
	free_list(&lista);
	free_list(&listb);
	return (1);
}
