/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:22:49 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	pb(t_list **lista, t_list **listb, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "pb\n", 3);
	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	node = (*lista)->head;
	if ((*lista)->head->nb != (*lista)->tail->nb)
	{
		(*lista)->head = (*lista)->head->next;
		(*lista)->head->prev = NULL;
	}
	else
	{
		(*lista)->head = NULL;
		(*lista)->tail = NULL;
	}
	node->next = (*listb)->head;
	node->prev = NULL;
	if ((*listb)->head)
		(*listb)->head->prev = node;
	(*listb)->head = node;
	if (!(*listb)->tail)
		(*listb)->tail = node;
}
