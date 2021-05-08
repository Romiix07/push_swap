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

int		*get_color_tab_rr(t_list *lista, t_list *listb)
{
	int	i;

	if (listb->option != 2)
		return (0);
	i = 0;
	lista->tab[i] = lista->head->nb;
	listb->tab[i] = lista->head->nb;
	while (++i < 4)
	{
		lista->tab[i] = listb->head->nb;
		listb->tab[i] = listb->head->nb;
	}
	return (lista->tab);
}

void	rr(t_list **lista, t_list **listb)
{
	int	option;

	option = (*lista)->option;
	if (option == 2)
		print_ope(*lista, *listb, "rr", get_color_tab_rr(*lista, *listb));
	(*lista)->option = 0;
	(*listb)->option = 0;
	ra(lista, listb);
	rb(lista, listb);
	(*lista)->option = option;
	(*listb)->option = option;
	print_ope(*lista, *listb, "rr", (*lista)->tab);
}
