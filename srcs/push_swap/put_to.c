/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:15:40 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/29 15:23:12 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_backward_tail(t_list *list, int forward, int base_nb)
{
	t_node	tmp;
	int		backward;

	backward = 0;
	tmp = *list->tail;
	if (tmp.nb == nb)
		return (0);
	while (tmp.prev)
	{
		if (base_nb == tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (nb != tmp.nb)
		++backward;
	return (backward < forward ? -1 : 1);
}

int			put_to_tail(t_list *list, int nb)
{
	t_node	tmp;
	int		forward;

	forward = 1;
	tmp = *list->head;
	while (tmp.next)
	{
		if (nb == tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (nb != tmp.nb)
		++forward;
	return (get_backward_tail(list, forward, base_nb));
}

static int	get_backward_head(t_list *list, int forward, int base_nb)
{
	t_node	tmp;
	int		backward;

	backward = 1;
	tmp = *list->tail;
	while (tmp.prev)
	{
		if (base_nb == tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (nb != tmp.nb)
		++backward;
	return (backward < forward ? -1 : 1);
}

int			put_to_head(t_list *list, int nb)
{
	t_node	tmp;
	int		forward;

	forward = 0;
	tmp = *list->head;
	if (tmp.nb == nb)
		return (0);
	while (tmp.next)
	{
		if (nb == tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (nb != tmp.nb)
		++forward;
	return (get_backward_head(list, forward, base_nb));
}
