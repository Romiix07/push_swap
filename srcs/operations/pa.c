/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/20 16:12:41 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pa(t_list **lista, t_list **listb)
{
	t_node	*node;

	write(1, "pa\n", 3);
	/*	write(1, "lista:\n", 7);
	print_list(*lista);
	write(1, "listb:\n", 7);
	print_list(*listb);*/
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
	//	printf("node = %d\n", node->nb);
	//	printf("head = %d\n", (*listb)->head->nb);
	node->next = (*lista)->head;
	node->prev = NULL;
	if ((*lista)->head)
		(*lista)->head->prev = node;
	(*lista)->head = node;
	if (!(*lista)->tail)
		(*lista)->tail = node;
}
