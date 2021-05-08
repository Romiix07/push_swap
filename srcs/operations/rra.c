/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:42 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		*get_color_tab_rra(t_list *lista)
{
	int	i;

	if (lista->option != 2)
		return (0);
	i = -1;
	while (++i < 4)
		lista->tab[i] = lista->tail->nb;
	return (lista->tab);
}

void	rra(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	if ((*lista)->tail->nb == (*lista)->head->nb)
		return ;
	if ((*lista)->option == 2)
		print_ope(*lista, *listb, "rra", get_color_tab_rra(*lista));
	node = (*lista)->tail;
	(*lista)->tail = (*lista)->tail->prev;
	(*lista)->tail->next = NULL;
	(*lista)->head->prev = node;
	node->next = (*lista)->head;
	node->prev = NULL;
	(*lista)->head = node;
	print_ope(*lista, *listb, "rra", (*lista)->tab);
}
