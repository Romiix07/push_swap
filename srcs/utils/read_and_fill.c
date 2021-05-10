/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:08:03 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/10 23:04:28 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*read_from_stdin(void)
{
	char	c;
	char	*s;
	int		r;

	s = 0;
	while ((r = read(0, &c, 1)) > 0)
		s = concatenate_str(s, c);
	return (s);
}

int			read_and_fill(int **tab)
{
	char	*s;

	if (!(s = read_from_stdin()))
		return (0);
	return (1);
}
