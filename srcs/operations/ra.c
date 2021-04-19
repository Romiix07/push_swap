/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 14:24:07 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_list **lista)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	node = (*lista)->head;
	(*lista)->head = (*lista)->head->next;
	if ((*lista)->head)
		(*lista)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*lista)->tail;
	(*lista)->tail->next = node;
	(*lista)->tail = node;
}
