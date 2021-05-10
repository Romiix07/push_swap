/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 18:02:58 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_pa(t_list *listb)
{
	int	i;

	if (listb->option != OPT_DEBUG)
		return (0);
	i = -1;
	listb->colors[0] = COLOR_RED;
	while (++i < 4)
		listb->tab[i] = listb->head->nb;
	return (listb->tab);
}

void		pa(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb || !(*listb)->head || !(*listb)->tail)
		return ;
	if ((*listb)->option == OPT_DEBUG)
		print_ope(*lista, *listb, "pa", get_color_tab_pa(*listb));
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
	node->next = (*lista)->head;
	node->prev = NULL;
	if ((*lista)->head)
		(*lista)->head->prev = node;
	(*lista)->head = node;
	if (!(*lista)->tail)
		(*lista)->tail = node;
	print_ope(*lista, *listb, "pa", (*listb)->tab);
}
