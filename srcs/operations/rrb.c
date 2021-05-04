/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:42:09 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrb(t_list **listb, int write)
{
	t_node	*node;

	if (write)
		write(1, "rrb\n", 4);
	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->tail->nb == (*listb)->head->nb)
		return ;
	node = (*listb)->tail;
	(*listb)->tail = (*listb)->tail->prev;
	(*listb)->tail->next = NULL;
	(*listb)->head->prev = node;
	node->next = (*listb)->head;
	node->prev = NULL;
	(*listb)->head = node;
}
