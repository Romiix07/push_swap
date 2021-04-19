/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 15:26:23 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrb(t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	node = (*listb)->tail;	
	(*listb)->tail = (*listb)->tail->prev;
	(*listb)->tail->next = NULL;
	(*listb)->head->prev = node;
	node->next = (*listb)->head;
	node->prev = NULL;
	(*listb)->head = node;
}
