/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:00:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/20 16:03:15 by rmouduri         ###   ########.fr       */
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
	if (!(tab = malloc(sizeof(int) * (ac - 1))))
		return (return_error("Malloc of int tab\n"));
	if (!fill_tab(ac, av, &tab))
	{
		free(tab);
		return (return_error("Invalid argument\n"));
	}
	if (!(init_lists(&lista, &listb)))
		return (0);
	convert(tab, &lista, ac - 1);
	free(tab);
	if (read_and_exec_lines(&lista, &listb) == 0)
		return (write(2, "Error\n", 6));
	print_list(lista);
	if (is_sorted(lista) == 0 || lista->head)
		return (write(1, "KO\n", 3));
	return (write(1, "OK\n", 3));
}
