/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:18 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		*get_color_tab_rb(t_list *listb)
{
	int	i;

	if (listb->option != 2)
		return (0);
	i = -1;
	while (++i < 4)
		listb->tab[i] = listb->head->nb;
	return (listb->tab);
}

void	rb(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->head->nb == (*listb)->tail->nb)
		return ;
	if ((*listb)->option == 2)
		print_ope(*lista, *listb, "rb", get_color_tab_rb(*listb));
	node = (*listb)->head;
	(*listb)->head = (*listb)->head->next;
	(*listb)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*listb)->tail;
	(*listb)->tail->next = node;
	(*listb)->tail = node;
	print_ope(*lista, *listb, "rb", (*listb)->tab);
}
