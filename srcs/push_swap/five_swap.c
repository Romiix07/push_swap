/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:05:44 by cmarien           #+#    #+#             */
/*   Updated: 2021/05/05 14:32:34 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	five_swap_1(t_list *lista, t_list *listb, int *i)
{
	pb(&lista, &listb);
	pb(&lista, &listb);
	if (is_sorted(lista) != 1)
		three_swap(lista, listb);
	if (listb->head->nb < lista->head->nb)
	{
		if (listb->head->nb > listb->head->next->nb)
		{
			pa(&lista, &listb);
			*i += 1;
		}
		pa(&lista, &listb);
		*i += 1;
		if (*i < 2 && listb->head->nb > lista->tail->nb)
		{
			pa(&lista, &listb);
			ra(&lista, &listb);
			*i += 1;
		}
	}
}

void	five_swap_2(t_list *lista, t_list *listb, int *i)
{
	if (*i < 2 && (listb->head->nb > lista->tail->nb))
	{
		if (listb->head->nb < listb->head->next->nb)
		{
			pa(&lista, &listb);
			ra(&lista, &listb);
			*i += 1;
		}
		pa(&lista, &listb);
		ra(&lista, &listb);
		*i += 1;
		if (*i < 2 && listb->head->nb < lista->head->nb)
		{
			*i += 1;
			pa(&lista, &listb);
		}
	}
	if (*i == 0 && (listb->head->next->nb > lista->tail->nb ||
		listb->head->next->nb < lista->head->nb))
	{
		rb(&lista, &listb);
		pa(&lista, &listb);
		*i += 1;
	}
}

void	five_swap_3(t_list *lista, t_list *listb, int *i, int direction)
{
	while (*i < 2)
	{
		*i += 1;
		direction = get_lowest_operation(lista, listb->head->nb, 0);
		if (!(listb->head->nb < lista->head->nb &&
			listb->head->nb > lista->tail->nb))
		{
			if (direction >= 0)
			{
				while (lista->head->nb > listb->head->nb)
					ra(&lista, &listb);
				while (lista->head->nb < listb->head->nb)
					ra(&lista, &listb);
			}
			else if (direction < 0)
			{
				while (lista->tail->nb < listb->head->nb)
					rra(&lista, &listb);
				while (lista->tail->nb > listb->head->nb)
					rra(&lista, &listb);
			}
		}
		pa(&lista, &listb);
	}
}
