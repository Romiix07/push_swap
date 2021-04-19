/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 14:19:19 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pa(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head)
		return ;
	node = (*listb)->head;
	(*listb)->head = (*listb)->head->next;
	if ((*listb)->head)
		(*listb)->head->prev = NULL;
	node->next = (*lista)->head;
	node->prev = NULL;
	if ((*lista)->head)
		(*lista)->head->prev = node;
	(*lista)->head = node;
}
