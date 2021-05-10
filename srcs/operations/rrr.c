/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:26:34 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 01:53:35 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	*get_color_tab_rrr(t_list *lista, t_list *listb)
{
	int	i;

	if (listb->option != 2)
		return (0);
	i = 0;
	lista->tab[i] = lista->tail->nb;
	listb->tab[i] = lista->tail->nb;
	lista->colors[0] = COLOR_RED;
	listb->colors[0] = COLOR_RED;
	while (++i < 4)
	{
		lista->tab[i] = listb->tail->nb;
		listb->tab[i] = listb->tail->nb;
		lista->colors[i] = COLOR_BLUE;
		listb->colors[i] = COLOR_BLUE;
	}
	return (lista->tab);
}

void		rrr(t_list **lista, t_list **listb)
{
	int	option;

	option = (*lista)->option;
	if (option == OPT_DEBUG)
		print_ope(*lista, *listb, "rrr", get_color_tab_rrr(*lista, *listb));
	(*lista)->option = 0;
	(*listb)->option = 0;
	rra(lista, listb);
	rrb(lista, listb);
	(*lista)->option = option;
	(*listb)->option = option;
	print_ope(*lista, *listb, "rrr", (*lista)->tab);
}
