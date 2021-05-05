/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundreds_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:57 by cmarien           #+#    #+#             */
/*   Updated: 2021/05/05 14:31:56 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	hundred_swap_1(t_list *lst_a, int *size, t_algo *var)
{
	if (var->loop == 0)
	{
		if ((*size - var->chunk_size) < 0)
			var->chunk_size = *size;
		*size -= var->chunk_size;
		var->loop = var->chunk_size;
		var->max_chunk = get_nth_nb(lst_a, var->chunk_size);
	}
	var->direction = get_closest_nb(lst_a, var->max_chunk, &var->target);
}

void	hundred_swap_3(t_list *lst_a, t_list *lst_b, t_algo *var)
{
	if ((abso(var->direction) + abso(var->p)) > (var->lstt - var->g))
	{
		if (abso(var->direction) > abso(var->p))
		{
			if (var->direction > 0)
				while (lst_a->head->nb > var->max_chunk &&
					lst_b->head->nb != var->down)
					rrr(&lst_a, &lst_b, 1);
			if (var->direction < 0)
				while (lst_a->head->nb > var->max_chunk &&
					lst_b->head->nb != var->down)
					rr(&lst_a, &lst_b, 1);
		}
	}
	else if (var->direction > 0 && var->p > 0)
		while (lst_a->head->nb > var->max_chunk &&
			lst_b->head->nb != var->down)
			rr(&lst_a, &lst_b, 1);
	else if (var->direction < 0 && var->p < 0)
		while (lst_a->head->nb > var->max_chunk &&
			lst_b->head->nb != var->down)
			rrr(&lst_a, &lst_b, 1);
}

void	hundred_swap_4(t_list *lst_a, t_list *lst_b, t_algo *var)
{
	if ((abso(var->direction) + abso(var->p)) > (var->lstt - var->g))
	{
		if (abso(var->direction) > abso(var->p))
		{
			if (var->direction > 0)
				while (lst_a->head->nb > var->max_chunk &&
					lst_b->tail->nb != var->up)
					rrr(&lst_a, &lst_b, 1);
			if (var->direction < 0)
				while (lst_a->head->nb > var->max_chunk &&
					lst_b->tail->nb != var->p)
					rr(&lst_a, &lst_b, 1);
		}
	}
	else if (var->direction > 0 && var->p > 0)
		while (lst_a->head->nb > var->max_chunk &&
				lst_b->tail->nb != var->up)
			rr(&lst_a, &lst_b, 1);
	else if (var->direction < 0 && var->p < 0)
		while (lst_a->head->nb > var->max_chunk &&
				lst_b->tail->nb != var->up)
			rrr(&lst_a, &lst_b, 1);
}

void	hundred_swap_2(t_list *lst_a, t_list *lst_b, t_algo *var)
{
	if (get_up_down(lst_b, var->target, &var->up, &var->down) <= 0)
		var->p = put_to_head(lst_b, var->down);
	else
		var->p = put_to_tail(lst_b, var->up);
	if (abso(var->direction) > abso(var->p))
	{
		var->g = abso(var->direction);
		var->lstt = lst_size(lst_a);
	}
	else
	{
		var->g = abso(var->p);
		var->lstt = lst_size(lst_b);
	}
	if (get_up_down(lst_b, var->target, &var->up, &var->down) <= 0)
		hundred_swap_3(lst_a, lst_b, var);
	else
		hundred_swap_4(lst_a, lst_b, var);
}

void	hundred_swap_5(t_list *lst_a, t_list *lst_b, t_algo *var)
{
	if (get_up_down(lst_b, lst_a->head->nb, &var->up, &var->down) <= 0)
	{
		var->p = put_to_head(lst_b, var->down);
		if (var->p > 0)
			while (lst_b->head->nb != var->down)
				rb(&lst_b, 1);
		else if (var->p < 0)
			while (lst_b->head->nb != var->down)
				rrb(&lst_b, 1);
	}
	else
	{
		var->p = put_to_tail(lst_b, var->up);
		if (var->p > 0)
			while (lst_b->tail->nb != var->up)
				rb(&lst_b, 1);
		else if (var->p < 0)
			while (lst_b->tail->nb != var->up)
				rrb(&lst_b, 1);
	}
}
