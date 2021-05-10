/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:55:47 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:35:39 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

int			check_duplicate(int *tab, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < i)
			if (tab[i] == tab[j])
				return (0);
	}
	return (1);
}

static int	get_i(int ac, char **av)
{
	int	i;

	i = -1;
	while (av[1][++i] && av[1][0] == '-' &&
		!ft_isdigit(av[1][i]))
		if (av[1][i] == 'w')
			return (ac > 2 ? 2 : ac - 1);
	if (av[1][0] != 0 && av[1][0] == '-' && !ft_isdigit(av[1][1]))
		return (1);
	return (0);
}

int			check_arg(char *s)
{
	int			i;
	char		sign;
	long long	nb;

	if (!ft_strcmp(s, "") || !ft_strcmp(s, "-"))
		return (0);
	nb = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		++i;
	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	if (!ft_isdigit(s[i]) && (s[i] || (i > 0 && (s[i - 1] == '-'
												|| s[i - 1] == '+'))))
		return (0);
	while (ft_isdigit(s[i]))
	{
		nb = nb * 10 + s[i] - '0';
		if (nb > 2147483648 || (nb > 2147483647 && sign == 1))
			return (0);
		++i;
	}
	nb *= sign;
	return (s[i] == 0 ? 1 : check_arg(&s[i]));
}

int			fill_tab(int ac, char **av, int **tab)
{
	int	i;
	int	j;
	int	count;

	i = get_i(ac, av);
	count = -1;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!check_arg(&av[i][j]))
				return (0);
			(*tab)[++count] = ft_atoi(&av[i][j]);
			if (av[i][j] == '-' || av[i][j] == '+')
				++j;
			while (ft_isdigit(av[i][j]))
				++j;
			while (av[i][j] == ' ' || av[i][j] == '\t')
				++j;
		}
	}
	if (!check_duplicate(*tab, get_tab_size(ac, av)))
		return (0);
	return (1);
}

int			get_tab_size(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = get_i(ac, av);
	count = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				++j;
			if (!ft_isdigit(av[i][j]))
				return (-1);
			++count;
			while (ft_isdigit(av[i][j]))
				++j;
			while (av[i][j] == ' ' || av[i][j] == '\t')
				++j;
		}
	}
	return (count);
}
