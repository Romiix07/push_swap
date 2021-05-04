/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:48:47 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	pa(t_list **lista, t_list **listb)
{
	t_node	*node;

	write(1, "pa\n", 3);
	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	node = (*listb)->head;
	if ((*listb)->head->nb != (*listb)->tail->nb)
	{
		(*listb)->head = (*listb)->head->next;
		(*listb)->head->prev = NULL;
	}
	else
	{
		(*listb)->head = NULL;
		(*listb)->tail = NULL;
	}
	node->next = (*lista)->head;
	node->prev = NULL;
	if ((*lista)->head)
		(*lista)->head->prev = node;
	(*lista)->head = node;
	if (!(*lista)->tail)
		(*lista)->tail = node;
}
