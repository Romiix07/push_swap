/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:19:17 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/28 15:02:03 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	sort(t_list **lista, t_list **listb);
void	fill_or_write(char *steps, unsigned char *s_len, char *add,
					  unsigned char ad_len);
int		get_closest_nb(t_list *list, int max);
int		get_lowest_operation(t_list *list, int nb);


#endif
