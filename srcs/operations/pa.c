/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/20 12:21:50 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pa(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	node = (*listb)->head;
	(*listb)->head = (*listb)->head->next;
	(*listb)->head->prev = NULL;
	node->next = (*lista)->head;
	node->prev = NULL;
	if ((*lista)->head)
		(*lista)->head->prev = node;
	(*lista)->head = node;
	if (!(*lista)->tail)
		(*lista)->tail = node;
}
