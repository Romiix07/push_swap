/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:42 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/10 22:25:47 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

static char	*concatenate_str(char *s, char c)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 2))))
	{
		if (s)
			free(s);
		return (NULL);
	}
	i = -1;
	j = -1;
	while (s && s[++j])
		ret[++i] = s[j];
	if (s)
		free(s);
	j = 0;
	ret[++i] = c;
	ret[++i] = '\0';
	return (ret);
}

char		*read_array(void)
{
	int		r;
	char	c;
	char	*s;

	s = 0;
	while ((r = read(0, &c, 1)) > 0)
	{
		if (c == 0 || c == '\n')
		{
			while ((r = read(0, &c, 1)) > 0)
				;
			break ;
		}
		if (!(s = concatenate_str(s, c)))
			return (0);
	}
	return (s);
}

int			get_str_size(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			++i;
		if (!ft_isdigit(s[i]))
			return (-1);
		++count;
		while (ft_isdigit(s[i]))
			++i;
		while (s[i] == ' ' || s[i] == '\t')
			++i;
	}
	return (count);
}

int			fill_read_tab(char *s, int **tab)
{
	int	i;
	int	count;

	count = -1;
	i = 0;
	while (s[i])
	{
		if (!check_arg(&s[i]))
			return (0);
		(*tab)[++count] = ft_atoi(&s[i]);
		if (s[i] == '-' || s[i] == '+')
			++i;
		while (ft_isdigit(s[i]))
			++i;
		while (s[i] == ' ' || s[i] == '\t')
			++i;
	}
	if (!check_duplicate(*tab, get_str_size(s)))
		return (0);
	return (1);
}
