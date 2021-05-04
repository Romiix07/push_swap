/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:42:06 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 13:54:54 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_backward(t_list *list, int forward, int base_nb, int *target)
{
	t_node	*tmp;
	int		backward;

	backward = 1;
	tmp = list->tail;
	while (tmp)
	{
		if (base_nb > tmp->nb)
			break ;
		++backward;
		tmp = tmp->prev;
	}
	if (tmp && backward < forward)
		*target = tmp->nb;
	return (backward < forward ? -backward : forward);
}

int			get_closest_nb(t_list *list, int max, int *target)
{
	t_node	*tmp;
	int		forward;
	int		base_nb;

	forward = 0;
	tmp = list->head;
	base_nb = max;
	while (tmp)
	{
		if (base_nb > tmp->nb)
			break ;
		++forward;
		tmp = tmp->next;
	}
	if (tmp)
		*target = tmp->nb;
	return (forward == 0 ? 0 : get_backward(list, forward, base_nb, target));
}
