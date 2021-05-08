/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 18:04:20 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int			*get_color_tab_sa(t_list *lista)
{
	int	i;

	if (lista->option != 2)
		return (0);
	if (!lista->head || !lista->head->next)
		return (0);
	i = 0;
	lista->tab[i] = lista->head->nb;
	while (++i < 4)
		lista->tab[i] = lista->head->next->nb;
	return (lista->tab);
}

static void	sa_same(t_list **lista, t_list **listb)
{
	t_node	*node;

	if ((*lista)->option == 2)
		print_ope(*lista, *listb, "sa", get_color_tab_sa(*lista));
	node = (*lista)->head;
	(*lista)->head = (*lista)->tail;
	(*lista)->tail = node;
	(*lista)->head->next = node;
	(*lista)->head->prev = NULL;
	node->next = NULL;
	node->prev = (*lista)->head;
	print_ope(*lista, *listb, "sa", (*lista)->tab);
}

void		sa(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!lista || !*lista)
		return ;
	if (!(*lista)->head || !(*lista)->head->next)
		return ;
	if ((*lista)->head->nb == (*lista)->tail->nb)
		return ;
	if ((*lista)->head->next->nb == (*lista)->tail->nb)
		return (sa_same(lista, listb));
	if ((*lista)->option == 2)
		print_ope(*lista, *listb, "sa", get_color_tab_sa(*lista));
	node = (*lista)->head->next;
	(*lista)->head->next = node->next;
	(*lista)->head->prev = node;
	if ((*lista)->head->next)
		(*lista)->head->next->prev = (*lista)->head;
	node->prev = NULL;
	node->next = (*lista)->head;
	(*lista)->head = node;
	print_ope(*lista, *listb, "sa", (*lista)->tab);
}
