/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/16 16:20:21 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*tab1;
	int	*tab2;

	if (ac < 2)
		return (return_error("Not enough arguments\n"));
	if (!(tab1 = malloc(sizeof(int) * (ac - 1))))
		return (return_error("Malloc of int tab1\n"));
	if (!(tab2 = malloc(sizeof(int) * (ac - 1))))
	{
		free(tab1);
		return (return_error("Malloc of int tab2\n"));
	}
	if (!fill_tab(ac, av, &tab1))
	{
		free(tab1);
		free(tab2);
		return (return_error("Invalid argument\n"));
	}
	sort(tab1, tab2, ac - 1);
	free(tab1);
	free(tab2);
	return (1);
}
