/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:31:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/05 14:24:12 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

typedef struct	s_node {
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_list {
	struct s_node	*head;
	struct s_node	*tail;
}				t_list;

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				get_tab_size(int ac, char **av);
int				fill_tab(int ac, char **av, int **tab);
int				return_error(char *str);
int				ft_strcmp(const char *s1, const char *s2);
t_node			*ft_lstnew(int nb);
int				init_lists(t_list **list1, t_list **list2);
int				convert(int *tab, t_list **list, int tab_size);
void			free_list(t_list **list);
void			print_list(t_list *list);
void			ft_putnbr(int nb);
int				is_rev_sorted(t_list *lista);
int				is_sorted(t_list *lista);
int				median(t_list *list_a, int size);
void			push_swap(t_list *list_a, t_list *list_b, int size);
int				lst_size(t_list *list);
int				abso(int nb);

void			sa(t_list **lista, int option);
void			sb(t_list **listb, int option);
void			ss(t_list **lista, t_list **listb, int option);
void			pa(t_list **lista, t_list **listb, int option);
void			pb(t_list **lista, t_list **listb, int option);
void			ra(t_list **lista, int option);
void			rb(t_list **listb, int option);
void			rr(t_list **lista, t_list **listb, int option);
void			rra(t_list **lista, int option);
void			rrb(t_list **listb, int option);
void			rrr(t_list **lista, t_list **listb, int option);

#endif
