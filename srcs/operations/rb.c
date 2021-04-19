/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 14:21:40 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rb(t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	node = (*listb)->head;
	(*listb)->head = (*listb)->head->next;
	if ((*listb)->head)
		(*listb)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*listb)->tail;
	(*listb)->tail->next = node;
	(*listb)->tail = node;
}
