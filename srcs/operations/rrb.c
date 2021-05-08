/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:48 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		*get_color_tab_rrb(t_list *listb)
{
	int	i;

	if (listb->option != 2)
		return (0);
	i = -1;
	while (++i < 4)
		listb->tab[i] = listb->tail->nb;
	return (listb->tab);
}

void	rrb(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->tail->nb == (*listb)->head->nb)
		return ;
	if ((*listb)->option == 2)
		print_ope(*lista, *listb, "rrb", get_color_tab_rrb(*listb));
	node = (*listb)->tail;
	(*listb)->tail = (*listb)->tail->prev;
	(*listb)->tail->next = NULL;
	(*listb)->head->prev = node;
	node->next = (*listb)->head;
	node->prev = NULL;
	(*listb)->head = node;
	print_ope(*lista, *listb, "rrb", (*listb)->tab);
}
