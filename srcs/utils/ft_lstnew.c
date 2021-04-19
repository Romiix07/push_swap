/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:57:32 by romain            #+#    #+#             */
/*   Updated: 2021/04/19 11:49:27 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

t_node	*ft_lstnew(int nb)
{
	t_node	*node;

	if ((node = malloc(sizeof(t_node))) == NULL)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
