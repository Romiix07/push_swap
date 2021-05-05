/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:24:14 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:23:04 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	rr(t_list **lista, t_list **listb, int option)
{
	if (option == 1)
		write(1, "rr\n", 3);
	ra(lista, 0);
	rb(listb, 0);
}
