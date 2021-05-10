/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:41:11 by rmouduri          #+#    #+#             */
/*   Updated: 2020/08/09 15:03:21 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	str_like(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

char		*ft_strstr(char *str, char *to_find)
{
	int i;

	if (str[0] == '\0' && to_find[0] == '\0')
		return (str);
	if (!str || !to_find)
		return (0);
	i = -1;
	while (str[++i])
		if (str_like(&str[i], to_find))
			return (&str[i]);
	return (0);
}
