#include "utils.h"

int	push_swap(t_list *lst_a, t_list *lst_b, int size ,int med)
{
	int	half;
	int	sorted;

	sorted = 0;
	half = 0;
	while (half < (size / 2))
	{
		if (lst_a->head->nb <= med)
		{
			pb(&lst_a, &lst_b);
			half++;
		}
		else
			ra(&lst_a);
	}
	int i = 0;
	while (sorted != 1)
	{
		if (((lst_a->head->nb > lst_a->head->next->nb) && (lst_a->head->nb < 100)) && ((lst_b->head->nb < lst_b->head->next->nb) && (lst_b->head->nb > -100)))
		{
			ss(&lst_a, &lst_b);
		}
		else if ((lst_a->head->nb > lst_a->head->next->nb) && (lst_a->head->nb < 100))
		{
			sa(&lst_a);
		}
		else if ((lst_b->head->nb < lst_b->head->next->nb) && (lst_b->head->nb > -100)/* || (lst_b->head->next->nb < -100)*/)
		{
			sb(&lst_b);
		}
		int a = is_sorted(lst_a);
		int b = is_rev_sorted(lst_b);
		if (a == 0 && b == 0)
			rr(&lst_a, &lst_b);
		else if (a == 0)
			ra(&lst_a);
		else if (b == 0/* && lst_b->head->next->nb > -100*/)
			rb(&lst_b);
		if (a == 1 && b == 1)
		{
			while (half-- > 0)
			{
				print_list(lst_a);
				print_list(lst_b);
		//		rrb(&lst_b);
				pa(&lst_a, &lst_b);
			}
			sorted = 1;
		}
		i++;
		if (i == 30)
			break ;
	}
	print_list(lst_a);
	print_list(lst_b);
}
