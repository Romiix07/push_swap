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

void	hundred_swap_1(t_list *lista, int *size, t_algo *var)
{
	if (var->loop == 0)
	{
		if ((*size - var->chunk_size) < 0)
			var->chunk_size = *size;
		*size -= var->chunk_size;
		var->loop = var->chunk_size;
		var->max_chunk = get_nth_nb(lista, var->chunk_size);
	}
	var->direction = get_closest_nb(lista, var->max_chunk, &var->target);
}

void	hundred_swap_3(t_list *lista, t_list *listb, t_algo *var)
{
	if ((abso(var->direction) + abso(var->p)) > (var->lstt - var->g))
	{
		if (abso(var->direction) > abso(var->p))
		{
			if (var->direction > 0)
				while (lista->head->nb > var->max_chunk &&
					listb->head->nb != var->down)
					rrr(&lista, &listb);
			if (var->direction < 0)
				while (lista->head->nb > var->max_chunk &&
					listb->head->nb != var->down)
					rr(&lista, &listb);
		}
	}
	else if (var->direction > 0 && var->p > 0)
		while (lista->head->nb > var->max_chunk &&
			listb->head->nb != var->down)
			rr(&lista, &listb);
	else if (var->direction < 0 && var->p < 0)
		while (lista->head->nb > var->max_chunk &&
			listb->head->nb != var->down)
			rrr(&lista, &listb);
}

void	hundred_swap_4(t_list *lista, t_list *listb, t_algo *var)
{
	if ((abso(var->direction) + abso(var->p)) > (var->lstt - var->g))
	{
		if (abso(var->direction) > abso(var->p))
		{
			if (var->direction > 0)
				while (lista->head->nb > var->max_chunk &&
					listb->tail->nb != var->up)
					rrr(&lista, &listb);
			if (var->direction < 0)
				while (lista->head->nb > var->max_chunk &&
					listb->tail->nb != var->p)
					rr(&lista, &listb);
		}
	}
	else if (var->direction > 0 && var->p > 0)
		while (lista->head->nb > var->max_chunk &&
				listb->tail->nb != var->up)
			rr(&lista, &listb);
	else if (var->direction < 0 && var->p < 0)
		while (lista->head->nb > var->max_chunk &&
				listb->tail->nb != var->up)
			rrr(&lista, &listb);
}

void	hundred_swap_2(t_list *lista, t_list *listb, t_algo *var)
{
	if (get_up_down(listb, var->target, &var->up, &var->down) <= 0)
		var->p = put_to_head(listb, var->down);
	else
		var->p = put_to_tail(listb, var->up);
	if (abso(var->direction) > abso(var->p))
	{
		var->g = abso(var->direction);
		var->lstt = lst_size(lista);
	}
	else
	{
		var->g = abso(var->p);
		var->lstt = lst_size(listb);
	}
	if (get_up_down(listb, var->target, &var->up, &var->down) <= 0)
		hundred_swap_3(lista, listb, var);
	else
		hundred_swap_4(lista, listb, var);
}

void	hundred_swap_5(t_list *lista, t_list *listb, t_algo *var)
{
	if (get_up_down(listb, lista->head->nb, &var->up, &var->down) <= 0)
	{
		var->p = put_to_head(listb, var->down);
		if (var->p > 0)
			while (listb->head->nb != var->down)
				rb(&lista, &listb);
		else if (var->p < 0)
			while (listb->head->nb != var->down)
				rrb(&lista, &listb);
	}
	else
	{
		var->p = put_to_tail(listb, var->up);
		if (var->p > 0)
			while (listb->tail->nb != var->up)
				rb(&lista, &listb);
		else if (var->p < 0)
			while (listb->tail->nb != var->up)
				rrb(&lista, &listb);
	}
}
