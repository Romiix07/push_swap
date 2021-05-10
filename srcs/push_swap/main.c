/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/10 23:02:48 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

static int	init_tab_list(t_list **lista, t_list **listb)
{
	(*lista)->tab = 0;
	(*listb)->tab = 0;
	(*lista)->colors = 0;
	(*listb)->colors = 0;
	if ((*lista)->option == OPT_DEBUG &&
		(!((*lista)->tab = malloc(sizeof(int) * 4)) ||
		!((*listb)->tab = malloc(sizeof(int) * 4)) ||
		!((*lista)->colors = malloc(sizeof(char *) * 4)) ||
		!((*listb)->colors = malloc(sizeof(char *) * 4))))
	{
		if ((*lista)->tab)
			free((*lista)->tab);
		(*lista)->tab = 0;
		if ((*listb)->tab)
			free((*listb)->tab);
		(*listb)->tab = 0;
		if ((*lista)->colors)
			free((*lista)->colors);
		if ((*listb)->colors)
			free((*listb)->colors);
		free_list(lista, 0);
		free_list(listb, 0);
		return (0);
	}
	return (1);
}

static int	check_r_option(char **av, char **s)
{
	int		i;

	i = 0;
	*s = 0;
	while (av[1][0] == '-' && av[1][++i] && !ft_isdigit(av[1][i]))
		if (av[1][i] == 'r')
		{
			*s = read_array();
			break ;
		}
	if (*s)
	{
		if ((i = get_str_size(*s)) <= 0)
			free(*s);
		return (i);
	}
	return (0);
}

static int	check_init_tab(int ac, char **av, int **tab)
{
	int		r;
	char	*s;

	if (!(r = get_tab_size(ac, av) <= 0 ? check_r_option(av, &s) :
		get_tab_size(ac, av)))
		return (return_error("Invalid numbers\n"));
	if (!(*tab = malloc(sizeof(int) * r)))
	{
		if (s)
			free(s);
		return (return_error("Malloc of int tab\n"));
	}
	if (get_tab_size(ac, av) <= 0)
	{
		r = fill_read_tab(s, tab) ? get_str_size(s) : 0;
		free(s);
		if (r <= 0)
			free(*tab);
		return (r);
	}
	else if (!fill_tab(ac, av, tab))
		return (free_list(0, *tab) * 0 + return_error("Invalid argument\n"));
	return (1);
}

int			main(int ac, char **av)
{
	int		*tab;
	t_list	*lista;
	t_list	*listb;
	int		size;

	if (ac < 2 || !(size = check_init_tab(ac, av, &tab)))
		return (ac < 2 ? return_error("Not enough arguments\n") : 0);
	if (!(init_lists(&lista, &listb)))
		return (0);
	if (!get_options(ac, av, lista, listb))
		return (free_list(&lista, tab) + free_list(&listb, 0));
	if (!convert(tab, &lista, lista->read == 1 ? size : get_tab_size(ac, av)))
		return (free_list(0, tab) + return_error("Malloc of linked list\n"));
	free(tab);
	if (!init_tab_list(&lista, &listb))
		return (return_error("Malloc of tabs/colors in lists\n"));
	push_swap(lista, listb, lista->read == 1 ? size : get_tab_size(ac, av));
	free_list(&lista, 0);
	free_list(&listb, 0);
	return (1);
}
