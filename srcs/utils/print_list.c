/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:19:00 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/03 11:07:22 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	is_nb_color(int nb, int *tab)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (tab[i] == nb)
			return (1);
	return (0);
}

void		print_list_color(t_list *list, int *tab)
{
	t_node	*tmp;

	if (!list)
		return ;
	if (list->head)
		tmp = list->head;
	else
	{
		write(1, "NULL List\n", 10);
		return ;
	}
	while (tmp)
	{
		if (is_nb_color(tmp->nb, tab))
			ft_putnbr_color(tmp->nb);
		else
			ft_putnbr(tmp->nb);
		if (tmp->next)
			write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void		print_list(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return ;
	if (list->head)
		tmp = list->head;
	else
	{
		write(1, "NULL List\n", 10);
		return ;
	}
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		if (tmp->next)
			write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
