/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <rmouduri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:41:45 by romain            #+#    #+#             */
/*   Updated: 2020/11/18 16:04:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp1 = *lst;
	tmp2 = *lst;
	while (tmp2)
	{
		tmp1 = tmp1->next;
		ft_lstdelone(tmp2, del);
		tmp2 = tmp1;
	}
	*lst = NULL;
}
