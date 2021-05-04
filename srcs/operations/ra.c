/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:51:29 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ra(t_list **lista, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "ra\n", 3);
	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	if ((*lista)->head->nb == (*lista)->tail->nb)
		return ;
	node = (*lista)->head;
	(*lista)->head = (*lista)->head->next;
	(*lista)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*lista)->tail;
	(*lista)->tail->next = node;
	(*lista)->tail = node;
}
