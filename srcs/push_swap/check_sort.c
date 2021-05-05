#include "utils.h"
#include "push_swap.h"

void	check_sort(t_list *lst_a)
{
	int lowest;

	lowest = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (lowest == 1)
			ra(&lst_a, 1);
		else
			rra(&lst_a, 1);
	}
}
