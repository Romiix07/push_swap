/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:26:34 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:23:16 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	rrr(t_list **lista, t_list **listb, int option)
{
	if (option == 1)
		write(1, "rrr\n", 4);
	rra(lista, 0);
	rrb(listb, 0);
}
