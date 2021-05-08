/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:05:27 by cmarien           #+#    #+#             */
/*   Updated: 2021/05/05 14:32:46 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "unistd.h"

void	three_swap(t_list *lista, t_list *listb)
{
	int	nb;
	int	next;
	int	next2;

	nb = lista->head->nb;
	next = lista->head->next->nb;
	next2 = lista->head->next->next->nb;
	if (nb > next && nb < next2)
		sa(&lista, &listb);
	else if (nb > next && next > next2)
	{
		sa(&lista, &listb);
		rra(&lista, &listb);
	}
	else if (nb > next && next < next2)
		ra(&lista, &listb);
	else if (nb < next && nb < next2)
	{
		sa(&lista, &listb);
		ra(&lista, &listb);
	}
	else if (nb < next && nb > next2)
		rra(&lista, &listb);
}

void	four_swap(t_list *lista, t_list *listb)
{
	pb(&lista, &listb);
	if (is_sorted(lista) != 1)
		three_swap(lista, listb);
	if (listb->head->nb < lista->head->nb)
		pa(&lista, &listb);
	else if (listb->head->nb > lista->tail->nb)
	{
		pa(&lista, &listb);
		ra(&lista, &listb);
	}
	else
	{
		while (lista->head->nb < listb->head->nb)
			ra(&lista, &listb);
		pa(&lista, &listb);
	}
	while (is_sorted(lista) != 1)
		rra(&lista, &listb);
}

void	five_swap(t_list *lista, t_list *listb)
{
	int	index;
	int	direction;

	index = 0;
	direction = 0;
	five_swap_1(lista, listb, &index);
	five_swap_2(lista, listb, &index);
	five_swap_3(lista, listb, &index, direction);
	check_sort(lista, listb);
}

void	hundred_swap(t_list *lista, t_list *listb, int size)
{
	t_algo var;

	var_edit(&var, size);
	while (size > 0 || var.loop > 0)
	{
		hundred_swap_1(lista, &size, &var);
		if (listb->head != NULL)
			hundred_swap_2(lista, listb, &var);
		var.direction = get_closest_nb(lista, var.max_chunk, &var.target);
		if (var.direction > 0)
			while (lista->head->nb > var.max_chunk)
				ra(&lista, &listb);
		else if (var.direction < 0)
			while (lista->head->nb > var.max_chunk)
				rra(&lista, &listb);
		if (listb->head != NULL)
			hundred_swap_5(lista, listb, &var);
		pb(&lista, &listb);
		var.loop--;
	}
	while (listb->head)
		pa(&lista, &listb);
	check_sort(lista, listb);
}

void	push_swap(t_list *lista, t_list *listb, int size)
{
	if (is_sorted(lista) == 1)
		return ;
	if (size == 2)
		sa(&lista, &listb);
	if (size == 3)
		three_swap(lista, listb);
	if (size == 4)
		four_swap(lista, listb);
	if (size == 5)
		five_swap(lista, listb);
	if (size > 5)
		hundred_swap(lista, listb, size);
}
