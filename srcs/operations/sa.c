/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/20 16:11:59 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(t_list **lista)
{
	t_node	*node;

	write(1, "sa\n", 3);
	if (!lista || !*lista)
		return ;
	if (!(*lista)->head || !(*lista)->head->next)
		return ;
	if ((*lista)->head->nb == (*lista)->tail->nb)
		return ;
	node = (*lista)->head->next;
	(*lista)->head->next = node->next;
	(*lista)->head->prev = node;
	node->prev = NULL;
	node->next = (*lista)->head;
	(*lista)->head = node;
}
