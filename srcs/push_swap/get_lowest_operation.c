/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:59:41 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/03 11:02:03 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_lower_nb(t_list *list, int nb)
{
	t_node	tmp;
	int		min;

	tmp = *list->head;
	min = tmp.nb;
	while (tmp.next)
	{
		if (tmp.nb < nb)
			break ;
		min = tmp.nb;
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

static int	get_backward_op(t_list *list, int forward, int nb, char swtch)
{
	t_node	tmp;
	int		backward;

	backward = 0;
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
	//	printf("fw = %d, bc = %d\n", forward, backward);
	return (backward < forward ? -1 : 1);
}

int	get_lowest_operation(t_list *list, int nb, char swtch, int *min_returned)
{
	t_node	tmp;
	int		forward;
	int		min;

	min = get_lower_nb(list, nb);
	*min_returned = min;
//	printf("nb = %d, min = %d\n", nb, min);
//	write(1, "printing\n", 9);
//	print_list(list);
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
	return (forward == 0 ? 1 : get_backward_op(list, forward, min, swtch));
}
