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

static int	print_color(char *ope, char *add, char *color)
{
	if (color)
		write(1, color, sizeof(color));
	write(1, ope, ft_strlen(ope));
	if (color)
		write(1, COLOR_DEFAULT, sizeof(COLOR_DEFAULT));
	if (add)
		write(1, add, ft_strlen(add));
	return (1);
}

static void	debug_after_ope(t_list *lista, t_list *listb, int *tab)
{
	if (lista)
	{
		write(1, "A: ", 3);
		print_list_color(lista, tab);
	}
	if (listb)
	{
		write(1, "B: ", 3);
		print_list_color(listb, tab);
	}
	if ((listb && listb->head) || (lista && !is_sorted(lista)))
		write(1, "\n", 1);
	else
		print_color("\nSORTED!\n", 0, COLOR_GREEN);
}

static void	debug_before_ope(t_list *lista, t_list *listb, char *ope, int *tab)
{
	write(1, "\033[1m", sizeof("\033[1m"));
	print_color(ope, ": \n", 0);
	write(1, "\033[22m", sizeof("\033[22m"));
	if (lista)
	{
		write(1, "A: ", 3);
		print_list_color(lista, tab);
	}
	if (listb)
	{
		write(1, "B: ", 3);
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
		return (print_color(ope, "\n", 0));
	else if (option == 2 && step == 0)
	{
		step = 1;
		debug_before_ope(lista, listb, ope, tab);
	}
	else if (option == 2 && step == 1)
	{
		step = 0;
		write(1, "-----\n", 6);
		debug_after_ope(lista, listb, tab);
	}
	else if (option == 3)
		print_color(ope, "\n", lista && listb && !listb->head &&
			is_sorted(lista) ? COLOR_GREEN : 0);
	return (1);
}
