/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:31:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/10 22:26:36 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

# define COLOR_RED		"\033[0;31m"
# define COLOR_GREEN	"\033[0;32m"
# define COLOR_BLUE		"\033[0;34m"
# define COLOR_PUR		"\033[0;35m"
# define COLOR_DEFAULT	"\033[0m"

# define OPT_DEBUG		2
# define OPT_COLOR		3

typedef struct	s_node {
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_list {
	struct s_node	*head;
	struct s_node	*tail;
	int				option;
	int				fd;
	int				*tab;
	char			**colors;
	int				read;
}				t_list;

int				print_ope(t_list *lista, t_list *listb, char *ope, int *tab);

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
int				free_list(t_list **list, int *tab);
void			print_list(t_list *list);
void			print_list_color(t_list *list, int *tab);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putnbr_color(int nb, char *color, int fd);
int				is_rev_sorted(t_list *lista);
int				is_sorted(t_list *lista);
int				median(t_list *list_a, int size);
void			push_swap(t_list *list_a, t_list *list_b, int size);
int				lst_size(t_list *list);
int				abso(int nb);
int				get_options(int ac, char **av, t_list *lista, t_list *listb);
char			*ft_strstr(char *str, char *to_find);
char			*read_array(void);
int				fill_read_tab(char *s, int **tab);
int				get_str_size(char *s);
int				check_arg(char *s);
int				check_duplicate(int *tab, int ac);

void			sa(t_list **lista, t_list **listb);
void			sb(t_list **lista, t_list **listb);
void			ss(t_list **lista, t_list **listb);
void			pa(t_list **lista, t_list **listb);
void			pb(t_list **lista, t_list **listb);
void			ra(t_list **lista, t_list **listb);
void			rb(t_list **lista, t_list **listb);
void			rr(t_list **lista, t_list **listb);
void			rra(t_list **lista, t_list **listb);
void			rrb(t_list **lista, t_list **listb);
void			rrr(t_list **lista, t_list **listb);

#endif
