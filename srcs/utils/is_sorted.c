/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:19:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 16:51:22 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int	is_sorted(t_list *lista, t_list *listb)
{
	t_node	tmp;
	int		nb;

	if (!lista || (listb && (listb->head || listb->tail)))
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
	return (1);
}
