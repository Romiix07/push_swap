/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:59:28 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/03 12:01:53 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	lst_size(t_list *list)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (list && list->head)
		tmp = list->head;
	else
		return (0);
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
