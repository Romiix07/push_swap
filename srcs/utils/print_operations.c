/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:32:30 by rmouduri          #+#    #+#             */
/*   Updated: 2021/05/08 02:28:24 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static int	print_color(char *ope, char *add, char *color, int fd)
{
	if (color)
		write(fd, color, sizeof(color));
	write(fd, ope, ft_strlen(ope));
	if (color)
		write(fd, COLOR_DEFAULT, sizeof(COLOR_DEFAULT));
	if (add)
		write(fd, add, ft_strlen(add));
	return (1);
}

static void	debug_after_ope(t_list *lista, t_list *listb, int *tab)
{
	if (lista)
	{
		write(lista->fd, "A: ", 3);
		print_list_color(lista, tab);
	}
	if (listb)
	{
		write(lista->fd, "B: ", 3);
		print_list_color(listb, tab);
	}
	if ((listb && listb->head) || (lista && !is_sorted(lista)))
		write(lista->fd, "\n", 1);
	else
		print_color("\nSORTED!\n", 0, COLOR_GREEN, lista ? lista->fd :
			listb->fd);
}

static void	debug_before_ope(t_list *lista, t_list *listb, char *ope, int *tab)
{
	write(lista->fd, "\033[1m", sizeof("\033[1m"));
	print_color(ope, ": \n", 0, lista ? lista->fd : listb->fd);
	write(lista->fd, "\033[22m", sizeof("\033[22m"));
	if (lista)
	{
		write(lista->fd, "A: ", 3);
		print_list_color(lista, tab);
	}
	if (listb)
	{
		write(lista->fd, "B: ", 3);
		print_list_color(listb, tab);
	}
}

int			print_ope(t_list *lista, t_list *listb, char *ope, int *tab)
{
	int			option;
	static int	step = 0;

	if ((option = lista ? lista->option : listb->option) == 0)
		return (0);
	if (option == 1)
		return (print_color(ope, "\n", 0, lista ? lista->fd : listb->fd));
	else if (option == OPT_DEBUG && step == 0)
	{
		step = 1;
		debug_before_ope(lista, listb, ope, tab);
	}
	else if (option == OPT_DEBUG && step == 1)
	{
		step = 0;
		write(lista->fd, "-----\n", 6);
		debug_after_ope(lista, listb, tab);
	}
	else if (option == OPT_COLOR)
		print_color(ope, "\n", lista && listb && !listb->head &&
			is_sorted(lista) ? COLOR_GREEN : 0, lista ? lista->fd : listb->fd);
	return (1);
}
