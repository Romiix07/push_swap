/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:55:39 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:23:30 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ss(t_list **list1, t_list **list2, int option)
{
	if (option == 1)
		write(1, "ss\n", 3);
	sa(list1, 0);
	sb(list2, 0);
}
