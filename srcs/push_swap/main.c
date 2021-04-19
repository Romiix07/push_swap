/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 12:05:24 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*list1;
	t_list	*list2;

	if (ac < 2)
		return (return_error("Not enough arguments\n"));
	if (!(tab = malloc(sizeof(int) * (ac - 1))))
		return (return_error("Malloc of int tab\n"));
	if (!fill_tab(ac, av, &tab))
	{
		free(tab);
		return (return_error("Invalid argument\n"));
	}
	if (!(init_lists(&list1, &list2)))
		return (0);
	convert(tab, &list1, ac - 1);
	free(tab);
	/*	if (!is_sorted(list1, list2))
		sort(list1, list1, ac - 1);
	free_lists(&list1, &list2);
	*/
	while (list1->head)
	{
		printf("%d ", list1->head->nb);
		list1->head = list1->head->next;
	}
	return (1);
}
