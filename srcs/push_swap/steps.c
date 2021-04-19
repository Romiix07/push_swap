/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:58:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/16 16:42:23 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_or_write(char *steps, unsigned char *s_len, char *add,
					unsigned char ad_len)
{
	if ((short)(*s_len + ad_len) > 255)
	{
		write(1, "write\n", 6);
		write(1, steps, *s_len);
		*s_len = 0;
	}
	while (*add)
	{
		steps[(*s_len)++] = *add;
		++add;
	}
}
