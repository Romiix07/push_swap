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

static int	get_tab_a(t_list *lista, t_list *listb)
{
	if (lista && lista->head && lista->head->next)
	{
		lista->tab[0] = lista->head->nb;
		lista->tab[1] = lista->head->next->nb;
		lista->tab[2] = listb->head ? listb->head->nb : lista->tab[0];
		lista->tab[3] = listb->head && listb->head->next ?
			listb->head->next->nb : lista->tab[1];
		lista->colors[0] = COLOR_RED;
		lista->colors[1] = COLOR_BLUE;
		lista->colors[2] = COLOR_GREEN;
		lista->colors[3] = COLOR_PUR;
		return (1);
	}
	return (0);
}

static int	get_tab_b(t_list *lista, t_list *listb)
{
	if (listb && listb->head && listb->head->next)
	{
		listb->tab[2] = listb->head->nb;
		listb->tab[3] = listb->head->next->nb;
		listb->tab[0] = lista->head ? lista->head->nb : listb->tab[2];
		listb->tab[1] = lista->head && lista->head->next ?
			lista->head->next->nb : lista->tab[3];
		listb->colors[0] = COLOR_RED;
		listb->colors[1] = COLOR_BLUE;
		listb->colors[2] = COLOR_GREEN;
		listb->colors[3] = COLOR_PUR;
		return (1);
	}
	return (0);
}

static int	*get_color_tab_ss(t_list *lista, t_list *listb)
{
	if (lista->option != OPT_DEBUG)
		return (0);
	if (get_tab_a(lista, listb) + get_tab_b(lista, listb) == 0)
		return (0);
	return (lista->head ? lista->tab : listb->tab);
}

void		ss(t_list **lista, t_list **listb)
{
	int	option;

	option = (*lista)->option;
	if (option == OPT_DEBUG)
		print_ope(*lista, *listb, "ss", get_color_tab_ss(*lista, *listb));
	(*lista)->option = 0;
	(*listb)->option = 0;
	sa(lista, listb);
	sb(lista, listb);
	(*lista)->option = option;
	(*listb)->option = option;
	print_ope(*lista, *listb, "ss", (*lista)->tab);
}
