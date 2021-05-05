#include "utils.h"
#include "push_swap.h"

void	five_swap_1(t_list *lst_a, t_list *lst_b, int *i)
{
	pb(&lst_a, &lst_b);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
		if (lst_b->head->nb > lst_b->head->next->nb)
		{
			pa(&lst_a, &lst_b);
			*i += 1;
		}
		pa(&lst_a, &lst_b);
		*i += 1;
		if (*i < 2 && lst_b->head->nb > lst_a->tail->nb)
		{
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			*i += 1;
		}
	}
}

void	five_swap_2(t_list *lst_a, t_list *lst_b, int *i)
{
	if (*i < 2 && (lst_b->head->nb > lst_a->tail->nb))
	{
		if (lst_b->head->nb < lst_b->head->next->nb)
		{
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			*i += 1;
		}
		pa(&lst_a, &lst_b);
		ra(&lst_a, 1);
		*i += 1;
		if (*i < 2 && lst_b->head->nb < lst_a->head->nb)
		{
			*i += 1;
			pa(&lst_a, &lst_b);
		}
	}
	if (*i == 0 && (lst_b->head->next->nb > lst_a->tail->nb ||
		lst_b->head->next->nb < lst_a->head->nb))
	{
		rb(&lst_b, 1);
		pa(&lst_a, &lst_b);
		*i += 1;
	}
}

void	five_swap_3(t_list *lst_a, t_list *lst_b, int *i, int direction)
{
	while (*i < 2)
	{
		*i += 1;
		direction = get_lowest_operation(lst_a, lst_b->head->nb, 0);
		if (!(lst_b->head->nb < lst_a->head->nb &&
			lst_b->head->nb > lst_a->tail->nb))
		{
			if (direction >= 0)
			{
				while (lst_a->head->nb > lst_b->head->nb)
					ra(&lst_a, 1);
				while (lst_a->head->nb < lst_b->head->nb)
					ra(&lst_a, 1);
			}
			else if (direction < 0)
			{
				while (lst_a->tail->nb < lst_b->head->nb)
					rra(&lst_a, 1);
				while (lst_a->tail->nb > lst_b->head->nb)
					rra(&lst_a, 1);
			}
		}
		pa(&lst_a, &lst_b);
	}
}
