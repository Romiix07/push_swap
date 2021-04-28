/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:42:06 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 15:11:16 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_backward(t_list *list, int forward, int base_nb)
{
	t_node	tmp;
	int		backward;

	backward = 0;
	tmp = *list->tail;
	while (tmp.prev)
	{
		if (base_nb > tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (!tmp.prev && base_nb < tmp.nb)
		backward = 0;
	else if (!tmp.prev && base_nb > tmp.nb)
		++backward;
	return (backward < forward ? -1 : 1);
}

int	get_closest_nb(t_list *list, int max)
{
	t_node	tmp;
	int		forward;
	int		base_nb;

	forward = 0;
	tmp = *list->head;
	base_nb = max;
	while (tmp.next)
	{
		if (base_nb > tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (!tmp.next && base_nb < tmp.nb)
		forward = 0;
	else if (!tmp.next && base_nb > tmp.nb)
		++forward;
	return (forward == 0 ? 1 : get_backward(list, forward, base_nb));
}
