/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:19:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 12:31:04 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	print_list(t_list *list)
{
	t_node	tmp;

	if (!list)
		return ;
	if (list->head)
		tmp = *list->head;
	while (tmp.next)
	{
		ft_putnbr(tmp.nb);
		write(1, " ", 1);
		tmp = *tmp.next;
	}
	ft_putnbr(tmp.nb);
}
