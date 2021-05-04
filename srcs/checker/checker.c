/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:06:02 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:09:56 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	goto_operation(char *s, t_list **lista, t_list **listb)
{
	if (ft_strcmp(s, "sa") == 0)
		sa(lista, 0);
	else if (ft_strcmp(s, "sb") == 0)
		sb(listb, 0);
	else if (ft_strcmp(s, "ss") == 0)
		ss(lista, listb);
	else if (ft_strcmp(s, "pa") == 0)
		pa(lista, listb);
	else if (ft_strcmp(s, "pb") == 0)
		pb(lista, listb);
	else if (ft_strcmp(s, "ra") == 0)
		ra(lista, 0);
	else if (ft_strcmp(s, "rb") == 0)
		rb(listb, 0);
	else if (ft_strcmp(s, "rr") == 0)
		rr(lista, listb);
	else if (ft_strcmp(s, "rra") == 0)
		rra(lista, 0);
	else if (ft_strcmp(s, "rrb") == 0)
		rrb(listb, 0);
	else if (ft_strcmp(s, "rrr") == 0)
		rrr(lista, listb);
	else
		return (0);
	return (1);
}

int			read_and_exec_lines(t_list **lista, t_list **listb, int i, char c)
{
	int		r;
	char	s[4];

	while ((r = read(0, &c, 1)) > 0)
	{
		if (c == '\0')
			break ;
		if (c == '\n')
		{
			s[++i] = '\0';
			if (goto_operation((char *)s, lista, listb) == 0)
			{
				write(1, "0", 1);
				return (0);
			}
			i = -1;
		}
		else
		{
			if (i > 2)
				return (0);
			s[++i] = c;
		}
	}
	return (1);
}
