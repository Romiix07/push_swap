/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:05:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:52:58 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_ra(t_list *lista)
{
	int	i;

	if (lista->option != OPT_DEBUG)
		return (0);
	i = -1;
	lista->colors[0] = COLOR_RED;
	while (++i < 4)
		lista->tab[i] = lista->head->nb;
	return (lista->tab);
}

void		ra(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	if ((*lista)->head->nb == (*lista)->tail->nb)
		return ;
	if ((*lista)->option == OPT_DEBUG)
		print_ope(*lista, *listb, "ra", get_color_tab_ra(*lista));
	node = (*lista)->head;
	(*lista)->head = (*lista)->head->next;
	(*lista)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*lista)->tail;
	(*lista)->tail->next = node;
	(*lista)->tail = node;
	print_ope(*lista, *listb, "ra", (*lista)->tab);
}
