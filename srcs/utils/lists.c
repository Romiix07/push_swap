/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:58:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:17:57 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int		init_lists(t_list **list1, t_list **list2)
{
	if (!(*list1 = malloc(sizeof(t_list))))
		return (0);
	if (!(*list2 = malloc(sizeof(t_list))))
	{
		free(*list1);
		return (0);
	}
	(*list1)->head = NULL;
	(*list1)->tail = NULL;
	(*list2)->head = NULL;
	(*list2)->tail = NULL;
	(*list1)->tab = 0;
	(*list2)->tab = 0;
	(*list1)->colors = 0;
	(*list2)->colors = 0;
	return (1);
}

int		free_list(t_list **list, int *tab)
{
	t_node	*node;

	if (tab && !list)
	{
		free(tab);
		return (1);
	}
	if ((*list)->tab)
		free((*list)->tab);
	if ((*list)->colors)
		free((*list)->colors);
	while ((*list)->head)
	{
		node = (*list)->head->next;
		free((*list)->head);
		(*list)->head = node;
	}
	free(*list);
	return (1);
}

int		convert(int *tab, t_list **list, int tab_size)
{
	int		i;
	t_node	*node;

	i = 0;
	if (!(node = ft_lstnew(tab[i])))
		return (0);
	if ((*list)->head == NULL)
		(*list)->head = node;
	if ((*list)->tail == NULL)
		(*list)->tail = node;
	while (++i < tab_size)
	{
		if (!(node = ft_lstnew(tab[i])))
		{
			free_list(list, 0);
			return (0);
		}
		node->prev = (*list)->tail;
		(*list)->tail->next = node;
		(*list)->tail = node;
		node = NULL;
	}
	return (1);
}
