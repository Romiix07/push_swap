/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:59:41 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 16:04:29 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_lower_nb(t_list *list, int nb)
{
	t_node	*tmp;
	int		min;

	tmp = list->head;
	while (tmp)
	{
		min = tmp->nb;
		if (tmp->nb < nb)
			break ;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->nb > min && tmp->nb < nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

static int	get_backward_op(t_list *list, int forward, int nb, char swtch)
{
	t_node	tmp;
	int		backward;

	backward = 1;
	tmp = *list->tail;
	if (swtch == 0 && nb == tmp.nb)
		return (0);
	while (tmp.prev)
	{
		if (nb == tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (nb != tmp.nb)
		++backward;
	return (backward < forward ? -backward : forward);
}

int			get_lowest_operation(t_list *list, int nb, char swtch)
{
	t_node	tmp;
	int		forward;
	int		min;

	min = get_lower_nb(list, nb);
	forward = 0;
	tmp = *list->head;
	if (swtch == 1 && min == tmp.nb)
		return (0);
	while (tmp.next)
	{
		if (min == tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (min != tmp.nb)
		++forward;
	return (forward == 0 ? 0 : get_backward_op(list, forward, min, swtch));
}
