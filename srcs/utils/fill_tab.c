/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:55:47 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/16 13:07:16 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

static int	check_duplicate(int *tab, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac - 1)
	{
		j = -1;
		while (++j < i)
			if (tab[i] == tab[j])
				return (0);
	}
	return (1);
}

static int	check_arg(char *s)
{
	int			i;
	char		sign;
	long long	nb;

	if (!ft_strcmp(s, "") || !ft_strcmp(s, "-"))
		return (0);
	nb = 0;
	i = -1;
	sign = s[0] == '-' ? -1 : 1;
	if (s[0] == '-' || s[0] == '+')
		++i;
	while (s[++i] != 0)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		nb = nb * 10 + s[i] - '0';
		if (nb > 2147463648 || (nb > 2147483647 && sign == 1))
			return (0);
	}
	nb *= sign;
	return (1);
}

int			fill_tab(int ac, char **av, int **tab)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!check_arg(av[i]))
			return (0);
		(*tab)[i - 1] = ft_atoi(av[i]);
	}
	if (!check_duplicate(*tab, ac))
		return (0);
	return (1);
}
