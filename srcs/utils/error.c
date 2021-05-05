/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:38:35 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:12:35 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int	return_error(char *str)
{
	if (str)
	{
		write(2, "Error\n", 6);
		write(2, str, ft_strlen(str));
	}
	return (0);
}
