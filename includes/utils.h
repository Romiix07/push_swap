/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:31:37 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 12:06:35 by rmouduri         ###   ########.fr       */
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
int				fill_tab(int ac, char **av, int **tab);
int				return_error(char *str);
int				ft_strcmp(const char *s1, const char *s2);
t_node			*ft_lstnew(int nb);
int				init_lists(t_list **list1, t_list **list2);
int				convert(int *tab, t_list **list, int tab_size);

#endif
