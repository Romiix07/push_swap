/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:55:39 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:07 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		*get_color_tab_ss(t_list *lista, t_list *listb)
{
	if (lista->option != 2)
		return (0);
	if (!lista->head || !lista->head->next || !listb->head ||
		!listb->head->next)
		return (0);
	lista->tab[0] = lista->head->nb;
	lista->tab[1] = lista->head->next->nb;
	lista->tab[2] = listb->head->nb;
	lista->tab[3] = listb->head->next->nb;
	listb->tab[0] = lista->head->nb;
	listb->tab[1] = lista->head->next->nb;
	listb->tab[2] = listb->head->nb;
	listb->tab[3] = listb->head->next->nb;
	return (lista->tab);
}

void	ss(t_list **lista, t_list **listb)
{
	int	option;

	option = (*lista)->option;
	if (option == 2)
		print_ope(*lista, *listb, "ss", get_color_tab_ss(*lista, *listb));
	(*lista)->option = 0;
	(*listb)->option = 0;
	sa(lista, listb);
	sb(lista, listb);
	(*lista)->option = option;
	(*listb)->option = option;
	print_ope(*lista, *listb, "ss", (*lista)->tab);
}
