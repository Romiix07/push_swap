/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:02:02 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static void	sa_same(t_list **lista)
{
	t_node	*node;

	node = (*lista)->head;
	(*lista)->head = (*lista)->tail;
	(*lista)->tail = node;
	(*lista)->head->next = node;
	(*lista)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*lista)->head;
}

void		sa(t_list **lista, int option)
{
	t_node	*node;

	if (option == 1)
		write(1, "sa\n", 3);
	if (!lista || !*lista)
		return ;
	if (!(*lista)->head || !(*lista)->head->next)
		return ;
	if ((*lista)->head->nb == (*lista)->tail->nb)
		return ;
	if ((*lista)->head->next->nb == (*lista)->tail->nb)
		return (sa_same(lista));
	node = (*lista)->head->next;
	(*lista)->head->next = node->next;
	(*lista)->head->prev = node;
	if ((*lista)->head->next)
		(*lista)->head->next->prev = (*lista)->head;
	node->prev = NULL;
	node->next = (*lista)->head;
	(*lista)->head = node;
}
