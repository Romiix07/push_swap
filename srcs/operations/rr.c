/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:24:14 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:27 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_rr(t_list *lista, t_list *listb)
{
	int	i;

	if (listb->option != OPT_DEBUG)
		return (0);
	i = 0;
	lista->tab[i] = lista->head->nb;
	listb->tab[i] = lista->head->nb;
	lista->tab[i] = lista->head ? lista->head->nb : listb->head->nb;
	listb->tab[i] = lista->head ? lista->head->nb : listb->head->nb;
	lista->colors[0] = COLOR_RED;
	listb->colors[0] = COLOR_RED;
	while (++i < 4)
	{
		lista->tab[i] = listb->head ? listb->head->nb : lista->head->nb;
		listb->tab[i] = listb->head ? listb->head->nb : lista->head->nb;
		lista->colors[i] = COLOR_BLUE;
		listb->colors[i] = COLOR_BLUE;
	}
	return (lista->tab);
}

void		rr(t_list **lista, t_list **listb)
{
	int	option;

	option = (*lista)->option;
	if (option == OPT_DEBUG)
		print_ope(*lista, *listb, "rr", get_color_tab_rr(*lista, *listb));
	(*lista)->option = 0;
	(*listb)->option = 0;
	ra(lista, listb);
	rb(lista, listb);
	(*lista)->option = option;
	(*listb)->option = option;
	print_ope(*lista, *listb, "rr", (*lista)->tab);
}
