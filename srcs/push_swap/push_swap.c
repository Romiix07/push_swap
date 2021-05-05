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

void	three_swap(t_list *lst)
{
	int	nb;
	int	next;
	int	next2;

	nb = lst->head->nb;
	next = lst->head->next->nb;
	next2 = lst->head->next->next->nb;
	if (nb > next && nb < next2)
		sa(&lst, 1);
	else if (nb > next && next > next2)
	{
		sa(&lst, 1);
		rra(&lst, 1);
	}
	else if (nb > next && next < next2)
		ra(&lst, 1);
	else if (nb < next && nb < next2)
	{
		sa(&lst, 1);
		ra(&lst, 1);
	}
	else if (nb < next && nb > next2)
		rra(&lst, 1);
}

void	four_swap(t_list *lst_a, t_list *lst_b)
{
	pb(&lst_a, &lst_b, 1);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
		pa(&lst_a, &lst_b, 1);
	else if (lst_b->head->nb > lst_a->tail->nb)
	{
		pa(&lst_a, &lst_b, 1);
		ra(&lst_a, 1);
	}
	else
	{
		while (lst_a->head->nb < lst_b->head->nb)
			ra(&lst_a, 1);
		pa(&lst_a, &lst_b, 1);
	}
	while (is_sorted(lst_a) != 1)
		rra(&lst_a, 1);
}

void	five_swap(t_list *lst_a, t_list *lst_b)
{
	int	index;
	int	direction;

	index = 0;
	direction = 0;
	five_swap_1(lst_a, lst_b, &index);
	five_swap_2(lst_a, lst_b, &index);
	five_swap_3(lst_a, lst_b, &index, direction);
	check_sort(lst_a);
}

void	hundred_swap(t_list *lst_a, t_list *lst_b, int size)
{
	t_algo var;

	var_edit(&var, size);
	while (size > 0 || var.loop > 0)
	{
		hundred_swap_1(lst_a, &size, &var);
		if (lst_b->head != NULL)
			hundred_swap_2(lst_a, lst_b, &var);
		var.direction = get_closest_nb(lst_a, var.max_chunk, &var.target);
		if (var.direction > 0)
			while (lst_a->head->nb > var.max_chunk)
				ra(&lst_a, 1);
		else if (var.direction < 0)
			while (lst_a->head->nb > var.max_chunk)
				rra(&lst_a, 1);
		if (lst_b->head != NULL)
			hundred_swap_5(lst_a, lst_b, &var);
		pb(&lst_a, &lst_b, 1);
		var.loop--;
	}
	while (lst_b->head)
		pa(&lst_a, &lst_b, 1);
	check_sort(lst_a);
}

void	push_swap(t_list *lst_a, t_list *lst_b, int size)
{
	if (is_sorted(lst_a) == 1)
		return ;
	if (size == 2)
		sa(&lst_a, 1);
	if (size == 3)
		three_swap(lst_a);
	if (size == 4)
		four_swap(lst_a, lst_b);
	if (size == 5)
		five_swap(lst_a, lst_b);
	if (size > 5)
		hundred_swap(lst_a, lst_b, size);
}
