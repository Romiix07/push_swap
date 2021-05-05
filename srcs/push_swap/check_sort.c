/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:05:32 by cmarien           #+#    #+#             */
/*   Updated: 2021/05/05 14:05:34 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	check_sort(t_list *lst_a)
{
	int lowest;

	lowest = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (lowest == 1)
			ra(&lst_a, 1);
		else
			rra(&lst_a, 1);
	}
}
