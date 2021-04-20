/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/20 16:13:18 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrb(t_list **listb)
{
	t_node	*node;

	write(1, "rrb\n", 4);
	//	write(1, "lista:\n", 7);
	//	print_list(*lista);
	/*	write(1, "listb:\n", 7);
		print_list(*listb);*/
	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->tail->nb == (*listb)->head->nb)
		return ;
	node = (*listb)->tail;
	(*listb)->tail = (*listb)->tail->prev;
	//	printf("rrbnode = %d\n", node->nb);
	//	printf("rrbtail = %d\n", (*listb)->tail->nb);
	(*listb)->tail->next = NULL;
	(*listb)->head->prev = node;
	node->next = (*listb)->head;
	node->prev = NULL;
	(*listb)->head = node;
}
