/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 12:41:20 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(t_list **list)
{
	t_node	*node;

	if (!list || !*list)
		return ;
	if (!(*list)->head || !(*list)->head->next)
		return ;
	node = (*list)->head->next;
	(*list)->head->next = node->next;
	(*list)->head->prev = node;
	node->prev = NULL;
	node->next = (*list)->head;
	(*list)->head = node;
}
