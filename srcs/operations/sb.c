/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:54:26 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_sb(t_list *listb)
{
	int	i;

	if (listb->option != 2)
		return (0);
	if (!listb->head || !listb->head->next)
		return (0);
	i = 0;
	listb->tab[i] = listb->head->nb;
	listb->colors[i] = COLOR_RED;
	while (++i < 4)
	{
		listb->tab[i] = listb->head->next->nb;
		listb->colors[i] = COLOR_BLUE;
	}
	return (listb->tab);
}

static void	sb_same(t_list **lista, t_list **listb)
{
	t_node	*node;

	if ((*listb)->option == OPT_DEBUG)
		print_ope(*lista, *listb, "sb", get_color_tab_sb(*listb));
	node = (*listb)->head;
	(*listb)->head = (*listb)->tail;
	(*listb)->tail = node;
	(*listb)->head->next = node;
	(*listb)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*listb)->head;
	print_ope(*lista, *listb, "sb", (*listb)->tab);
}

void		sb(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb)
		return ;
	if (!(*listb)->head || !(*listb)->head->next)
		return ;
	if ((*listb)->head->nb == (*listb)->tail->nb)
		return ;
	if ((*listb)->head->next->nb == (*listb)->tail->nb)
		return (sb_same(lista, listb));
	if ((*listb)->option == OPT_DEBUG)
		print_ope(*lista, *listb, "sb", get_color_tab_sb(*listb));
	node = (*listb)->head->next;
	(*listb)->head->next = node->next;
	(*listb)->head->prev = node;
	if ((*listb)->head->next)
		(*listb)->head->next->prev = (*listb)->head;
	node->prev = NULL;
	node->next = (*listb)->head;
	(*listb)->head = node;
	print_ope(*lista, *listb, "sb", (*listb)->tab);
}
