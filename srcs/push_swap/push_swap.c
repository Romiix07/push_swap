#include "utils.h"
#include "push_swap.h"
#include "unistd.h"

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

void	four_swap(t_list *lst_a, t_list *lst_b)
{
	write(1, "pb\n", 3);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	else if (lst_b->head->nb > lst_a->tail->nb)
	{
		write(1, "pa\nra\n", 6);
		pa(&lst_a, &lst_b);
		ra(&lst_a);
	}
	else
	{
		while (lst_a->head->nb < lst_b->head->nb)
		{
			write(1, "ra\n", 3);
			ra(&lst_a);
		}
		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	while (is_sorted(lst_a) != 1)
	{
		write(1, "rra\n", 4);
		rra(&lst_a);
	}
//	print_list(lst_a);
}

void	five_swap(t_list *lst_a, t_list *lst_b)
{
	int i = 0;
	int count = 0;
	write(1, "pb\npb\n", 6);
	pb(&lst_a, &lst_b);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
		if (lst_b->head->nb > lst_b->head->next->nb)
		{
			write(1, "pa\n", 3);
			pa(&lst_a, &lst_b);
			i++;
		}
		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
		i++;
		if (i < 2 && lst_b->head->nb > lst_a->tail->nb)
		{
			write(1, "pa\nra\n", 6);
			pa(&lst_a, &lst_b);
			ra(&lst_a);
			i++;
		}
	}
	if (i < 2 && (lst_b->head->nb > lst_a->tail->nb))
	{
		if (lst_b->head->nb < lst_b->head->next->nb)
		{
			write(1, "pa\nra\n", 6);
			pa(&lst_a, &lst_b);
			ra(&lst_a);
			i++;
		}
		write(1, "pa\nra\n", 6);
		pa(&lst_a, &lst_b);
		ra(&lst_a);
		i++;
		if (i < 2 && lst_b->head->nb < lst_a->head->nb)
		{
			write(1, "pa\n", 3);
			pa(&lst_a, &lst_b);
			i++;
		}
	}
//	print_list(lst_a);
	if (i == 0 && (lst_b->head->next->nb > lst_a->tail->nb || lst_b->head->next->nb < lst_a->head->nb))
	{
		write(1, "rb\npa\n", 6);
		rb(&lst_b);
		if (lst_b->head->nb > lst_a->tail->nb)
		{
			write(1, "ra\n", 3);
			pa(&lst_a, &lst_b);
			ra(&lst_a);
		}
		else
			pa(&lst_a, &lst_b);
		i++;
	}
//	print_list(lst_b);
//	return ;
	while (i < 2)
	{
//		print_list(lst_a);
		i++;
		int w;
		w = get_lowest_operation(lst_a, lst_b->head->nb);
//		printf("%d\n", w);
		if (!(lst_b->head->nb < lst_a->head->nb && lst_b->head->nb > lst_a->tail->nb))
		{	
			if (w == 1)
			{
				while (lst_a->head->nb > lst_b->head->nb)
				{
					write(1, "ra\n", 3);
					ra(&lst_a);
				}
				while (lst_a->head->nb < lst_b->head->nb)
				{
					write(1, "ra\n", 3);
					ra(&lst_a);
				}
			}
			else
			{
				while (lst_a->tail->nb < lst_b->head->nb)
				{
					write(1, "rra\n", 4);
					rra(&lst_a);
				}
				while (lst_a->tail->nb > lst_b->head->nb)
				{
					write(1, "rra\n", 4);
					rra(&lst_a);
				}
			}
		}
		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
//	print_list(lst_a);
//	return;
	int x = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (x == 1)
		{
			write(1, "ra\n", 3);
			ra(&lst_a);
		}
		else
		{
			write(1, "rra\n", 4);
			rra(&lst_a);
		}
	}
//	print_list(lst_a);
}

int	push_swap(t_list *lst_a, t_list *lst_b, int size ,int med)
{
	if (is_sorted(lst_a) == 1)
		return (0);
	if (size == 2)
	{
		write(1, "sa\n", 3);
		sa(&lst_a);
	}
	if (size == 3)
		three_swap(lst_a);
	if (size == 4)
		four_swap(lst_a, lst_b);
	if (size == 5)
		five_swap(lst_a, lst_b);
}
