/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:54:12 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_pb(t_list *lista)
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

void		pb(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	if ((*lista)->option == OPT_DEBUG)
		print_ope(*lista, *listb, "pb", get_color_tab_pb(*lista));
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
	print_ope(*lista, *listb, "pb", (*lista)->tab);
}
