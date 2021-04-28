#include "utils.h"

int	median(t_list *lst_a, int size)
{
	int	ret;
	int	min;
	int	count;
	t_node	tmp;

	count = 0;
	ret = -2147483648;
	while (count < (size / 2))
	{
		min = 2147483647;
		tmp = *lst_a->head;
		while (tmp.next)
		{
			if (tmp.nb < min && tmp.nb > ret)
				min = tmp.nb;
			tmp = *tmp.next;
		}
		if (tmp.nb < min && tmp.nb > ret)
			min = tmp.nb;
		count++;
		ret = min;
	}
	return (ret);
}