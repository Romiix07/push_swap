#include "utils.h"

void	get_min_max(int	*min, int *max, t_list *lst_a)
{
	t_node	tmp;

	tmp = *lst_a->head;
	*min = tmp.nb;
	*max = tmp.nb;
	while (tmp.next)
	{
		if (*max < tmp.nb)
			*max = tmp.nb;
		if (*min > tmp.nb)
			*min = tmp.nb;
		tmp = *tmp.next;
	}
	if (*max < tmp.nb)
		*max = tmp.nb;
	if (*min > tmp.nb)
		*min = tmp.nb;
}

void	three_swap(t_list *lst)
{
	if (lst->head->nb > lst->head->next->nb && lst->head->nb < lst->head->next->next->nb)
	{
		write(1, "sa\n", 3);
		sa(&lst);
	}
	else if (lst->head->nb > lst->head->next->nb && lst->head->next->nb > lst->head->next->next->nb)
	{
		write(1, "sa\nrra\n", 7);
		sa(&lst);
		rra(&lst);
	}
	else if (lst->head->nb > lst->head->next->nb && lst->head->next->nb < lst->head->next->next->nb)
	{
		write(1, "ra\n", 3);
		ra(&lst);
	}
	else if (lst->head->nb < lst->head->next->nb && lst->head->nb < lst->head->next->next->nb)
	{
		write(1, "sa\nra\n", 7);
		sa(&lst);
		ra(&lst);
	}
	else if (lst->head->nb < lst->head->next->nb && lst->head->nb > lst->head->next->next->nb)
	{
		write(1, "rra\n", 4);
		rra(&lst);
	}
}

void	five_swap(t_list *lst_a, t_list *lst_b)
{
	int i = 0;
	write(1, "pb\npb\n", 6);
	pb(&lst_a, &lst_b);
	pb(&lst_a, &lst_b);
	three_swap(lst_a);
	print_list(lst_b);
	while (i < 2)
	{
		i++;
		write("%d\n", lst_b->head->nb);
	}
}

int	push_swap(t_list *lst_a, t_list *lst_b, int size ,int med)
{
	if (is_sorted(lst_a) == 1)
		return ;
	if (size == 2)
	{
		write(1, "sa\n", 3);
		sa(lst_a);
	}
	if (size == 3)
		three_swap(lst_a);
	if (size == 5)
		five_swap(lst_a, lst_b);
}
