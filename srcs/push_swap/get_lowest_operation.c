/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:59:41 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 17:24:26 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_backward_op(t_list *list, int forward, int nb)
{
	t_node	tmp;
	int		backward;

	backward = 1;
	tmp = *list->tail;
	while (tmp.prev)
	{
		if (nb > tmp.nb)
			break ;
		++backward;
		tmp = *tmp.prev;
	}
	if (!tmp.prev && nb < tmp.nb)
		backward = ++backward;
	//	printf("fw = %d, bc = %d\n", forward, backward);
	return (backward < forward ? -1 : 1);
}

int	get_lowest_operation(t_list *list, int nb)
{
	t_node	tmp;
	int		forward;

	//	printf("%d\n", nb);
	//	write(1, "printing\n", 9);
	print_list(list);
	forward = 0;
	tmp = *list->head;
	while (tmp.next)
	{
		if (nb < tmp.nb)
			break ;
		++forward;
		tmp = *tmp.next;
	}
	if (!tmp.next && nb < tmp.nb)
		forward = 0;
	else if (!tmp.next && nb > tmp.nb)
		++forward;
	return (forward == 0 ? 1 : get_backward_op(list, forward, nb));
}
