/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:59:41 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 19:33:41 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_lower_nb(t_list *list, int nb)
{
	t_node	tmp;
	int		min;

	tmp = *list->head;
	while (tmp.next)
	{
		min = tmp.nb;
		if (tmp.nb < nb)
			break ;
		tmp = *tmp.next;
	}
	while (tmp.next)
	{
		if (tmp.nb > min && tmp.nb < nb)
			min = tmp.nb;
		tmp = *tmp.next;
	}
	if (tmp.nb > min && tmp.nb < nb)
		min = tmp.nb;
	return (min);	
}

static int	get_backward_op(t_list *list, int forward, int nb)
{
	t_node	tmp;
	int		backward;

	backward = 0;
	tmp = *list->tail;
	while (tmp.prev)
	{
		if (nb == tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (nb != tmp.nb)
		++backward;
	printf("fw = %d, bc = %d\n", forward, backward);
	return (backward < forward ? -1 : 1);
}

int	get_lowest_operation(t_list *list, int nb)
{
	t_node	tmp;
	int		forward;
	int		min;

	min = get_lower_nb(list, nb);
	printf("nb = %d, min = %d\n", nb, min);
	write(1, "printing\n", 9);
	print_list(list);
	forward = 0;
	tmp = *list->head;
	while (tmp.next)
	{
		if (min == tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (min != tmp.nb)
		++forward;
	return (forward == 0 ? 1 : get_backward_op(list, forward, min));
}
