/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:50:46 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 18:59:01 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

static int	get_min(t_list *lst_a)
{
	t_node	tmp;
	int		min;

	tmp = *lst_a->head;
	min = tmp.nb;
	while (tmp.next)
	{
		if (min > tmp.nb)
			min = tmp.nb;
		tmp = *tmp.next;
	}
	if (min > tmp.nb)
		min = tmp.nb;
	return (min);
}

static int	where_is_min_backward(t_list *list, int forward, int min)
{
	t_node	tmp;
	int		backward;

	backward = 0;
	tmp = *list->tail;
	while (tmp.prev)
	{
		if (min > tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (!tmp.prev && min > tmp.nb)
		++backward;
	return (backward < forward ? -1 : 1);
}

int			where_is_lowest_nb(t_list *list)
{
	t_node	tmp;
	int		min;
	int		forward;

	min = get_min(list);
	forward = 0;
	tmp = *list->head;
	while (tmp.next)
	{
		if (min == tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (!tmp.next && min > tmp.nb)
		++forward;
	return (forward == 0 ? 1 : where_is_min_backward(list, forward, min));
}
