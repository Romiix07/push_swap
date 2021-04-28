/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:00:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 12:59:21 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "utils.h"

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*lista;
	t_list	*listb;

	if (ac < 2)
		return (return_error("Not enough arguments\n"));
	if (get_tab_size(ac, av) == -1)
		return (return_error("Invalid numbers\n"));
	if (!(tab = malloc(sizeof(int) * (get_tab_size(ac, av)))))
		return (return_error("Malloc of int tab\n"));
	if (!fill_tab(ac, av, &tab))
	{
		free(tab);
		return (return_error("Invalid argument\n"));
	}
	if (!(init_lists(&lista, &listb)))
		return (0);
	convert(tab, &lista, get_tab_size(ac, av));
	free(tab);
	if (read_and_exec_lines(&lista, &listb) == 0)
		return (write(2, "Error\n", 6));
	//	print_list(lista);
	if (is_sorted(lista) == 0 || listb->head)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_list(&lista);
	free_list(&listb);
}
