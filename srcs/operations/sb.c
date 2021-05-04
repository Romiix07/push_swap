/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:52:26 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static void	sb_same(t_list **listb)
{
	t_node	*node;

	node = (*listb)->head;
	(*listb)->head = (*listb)->tail;
	(*listb)->tail = node;
	(*listb)->head->next = node;
	(*listb)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*listb)->head;
}

void		sb(t_list **listb, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "sb\n", 3);
	if (!listb || !*listb)
		return ;
	if (!(*listb)->head || !(*listb)->head->next)
		return ;
	if ((*listb)->head->nb == (*listb)->tail->nb)
		return ;
	if ((*listb)->head->next->nb == (*listb)->tail->nb)
		return (sb_same(listb));
	node = (*listb)->head->next;
	(*listb)->head->next = node->next;
	(*listb)->head->prev = node;
	if ((*listb)->head->next)
		(*listb)->head->next->prev = (*listb)->head;
	node->prev = NULL;
	node->next = (*listb)->head;
	(*listb)->head = node;
}
