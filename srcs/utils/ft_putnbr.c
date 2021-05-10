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

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	if (nb != -2147483648)
		ft_putchar((nb % 10) + 48, fd);
	else
		write(fd, "-2147483648", 11);
}

void		ft_putnbr_color(int nb, char *color, int fd)
{
	write(fd, color, sizeof(color));
	ft_putnbr_fd(nb, fd);
	write(fd, COLOR_DEFAULT, sizeof(COLOR_DEFAULT));
}
