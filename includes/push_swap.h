/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:19:17 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/04 15:50:18 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef struct	s_algo
{
	int	max_chunk;
	int	loop;
	int	direction;
	int	p;
	int	g;
	int	lstt;
	int	down;
	int	up;
	int	chunk_size;
	int	target;
}				t_algo;

void			sort(t_list **lista, t_list **listb);
void			fill_or_write(char *steps, unsigned char *s_len, char *add,
				unsigned char ad_len);
int				get_closest_nb(t_list *list, int max, int *target);
int				get_lowest_operation(t_list *list, int nb, char tmp);
int				where_is_lowest_nb(t_list *list);
int				get_nth_nb(t_list *list, int n);
int				get_up_down(t_list *list, int ref, int *max, int *min);
int				put_to_head(t_list *list, int nb);
int				put_to_tail(t_list *list, int nb);
void			var_edit(t_algo *var, int size);
void			check_sort(t_list *lst_a);
void			three_swap(t_list *lst_a);
void			five_swap_1(t_list *lst_a, t_list *lst_b, int *i);
void			five_swap_2(t_list *lst_a, t_list *lst_b, int *i);
void			five_swap_3(t_list *lst_a, t_list *lst_b, int *i,
		int direction);
void			hundred_swap_1(t_list *lst_a, int *size,
		t_algo *var);
void			hundred_swap_2(t_list *lst_a, t_list *lst_b, t_algo *var);
void			hundred_swap_3(t_list *lst_a, t_list *lst_b, t_algo *var);
void			hundred_swap_4(t_list *lst_a, t_list *lst_b, t_algo *var);
void			hundred_swap_5(t_list *lst_a, t_list *lst_b, t_algo *var);

#endif
