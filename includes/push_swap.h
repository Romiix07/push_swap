/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:19:17 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/03 11:02:23 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	sort(t_list **lista, t_list **listb);
void	fill_or_write(char *steps, unsigned char *s_len, char *add,
					unsigned char ad_len);
int		get_closest_nb(t_list *list, int max);
int		get_lowest_operation(t_list *list, int nb, char tmp, int *min_returned);
int		where_is_lowest_nb(t_list *list);
int		get_nth_nb(t_list *list, int n);
int		get_up_down(t_list *list, int ref, int *max, int *min);
int		put_to_head(t_list *list, int nb);
int		put_to_tail(t_list *list, int nb);

#endif
