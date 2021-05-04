/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:19:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:18:24 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int	is_sorted(t_list *lista)
{
	t_node	tmp;
	int		nb;

	if (!lista)
		return (0);
	if (lista->head)
		tmp = *lista->head;
	nb = tmp.nb;
	while (tmp.next)
	{
		if (nb > tmp.nb)
			return (0);
		nb = tmp.nb;
		tmp = *tmp.next;
	}
	if (nb > tmp.nb)
		return (0);
	return (1);
}

int	is_rev_sorted(t_list *lista)
{
	t_node	tmp;
	int		nb;

	if (!lista)
		return (0);
	if (lista->head)
		tmp = *lista->head;
	nb = tmp.nb;
	while (tmp.next)
	{
		if (nb < tmp.nb)
			return (0);
		nb = tmp.nb;
		tmp = *tmp.next;
	}
	if (nb < tmp.nb)
		return (0);
	return (1);
}
