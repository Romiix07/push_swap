/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_up_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:04:33 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/29 15:09:09 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static int	get_bigger_nb(t_list *list, int nb)
{
	t_node	tmp;
	int		max;

	tmp = *list->head;
	max = tmp.nb;
	while (tmp.next)
	{
		if (tmp.nb > nb)
			break ;
		max = tmp.nb;
		tmp = *tmp.next;
	}
	while (tmp.next)
	{
		if (tmp.nb < max && tmp.nb > nb)
			max = tmp.nb;
		tmp = *tmp.next;
	}
	if (tmp.nb < max && tmp.nb > nb)
		max = tmp.nb;
	return (max);	
}

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

int			get_up_down(t_list *list, int ref, int *max, int *min)
{
	*max = get_bigger_nb(list, ref);
	*min = get_lower_nb(list, ref);
	if (*max < ref)
		return (-1);
	else if (*min > ref)
		return (1);
	return (0);
}
