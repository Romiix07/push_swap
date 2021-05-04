/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nth_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:55:05 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 16:04:36 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

static void	replace_tab_max(int *tab, int *max, int n, int size)
{
	int	i;

	i = 0;
	while ((tab)[i] != *max)
		++i;
	(tab)[i] = n;
	*max = n;
	i = -1;
	while (++i < size)
		*max = *max < (tab)[i] ? (tab)[i] : *max;
}

int			get_nth_nb(t_list *list, int n)
{
	t_node	*tmp;
	int		max;
	int		i;
	int		tab[n];

	i = -1;
	tmp = list->head;
	max = tmp->nb;
	while (++i < n)
	{
		tab[i] = tmp->nb;
		max = max < tmp->nb ? tmp->nb : max;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->nb < max)
			replace_tab_max(&tab[0], &max, tmp->nb, n);
		tmp = tmp->next;
	}
	return (max);
}
