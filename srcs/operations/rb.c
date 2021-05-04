/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:51:24 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	rb(t_list **listb, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "rb\n", 3);
	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->head->nb == (*listb)->tail->nb)
		return ;
	node = (*listb)->head;
	(*listb)->head = (*listb)->head->next;
	(*listb)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*listb)->tail;
	(*listb)->tail->next = node;
	(*listb)->tail = node;
}
