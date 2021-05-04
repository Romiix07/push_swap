/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 14:52:02 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	rra(t_list **lista, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "rra\n", 4);
	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	if ((*lista)->tail->nb == (*lista)->head->nb)
		return ;
	node = (*lista)->tail;
	(*lista)->tail = (*lista)->tail->prev;
	(*lista)->tail->next = NULL;
	(*lista)->head->prev = node;
	node->next = (*lista)->head;
	node->prev = NULL;
	(*lista)->head = node;
}
