/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:56:29 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:18:36 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	if (nb != -2147483648)
		ft_putchar((nb % 10) + 48);
	else
		write(1, "-2147483648", 11);
}

void		ft_putnbr_color(int nb, char *color)
{
	write(1, color, sizeof(color));
	ft_putnbr(nb);
	write(1, COLOR_DEFAULT, sizeof(COLOR_DEFAULT));
}
