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
//		write(1, "sa\n", 3);
		sa(&lst, 1);
	}
	else if (lst->head->nb > lst->head->next->nb && lst->head->next->nb > lst->head->next->next->nb)
	{
//		write(1, "sa\nrra\n", 7);
		sa(&lst, 1);
		rra(&lst, 1);
	}
	else if (lst->head->nb > lst->head->next->nb && lst->head->next->nb < lst->head->next->next->nb)
	{
//		write(1, "ra\n", 3);
		ra(&lst, 1);
	}
	else if (lst->head->nb < lst->head->next->nb && lst->head->nb < lst->head->next->next->nb)
	{
//		write(1, "sa\nra\n", 6);
		sa(&lst, 1);
		ra(&lst, 1);
	}
	else if (lst->head->nb < lst->head->next->nb && lst->head->nb > lst->head->next->next->nb)
	{
//		write(1, "rra\n", 4);
		rra(&lst, 1);
	}
}

void	four_swap(t_list *lst_a, t_list *lst_b)
{
//	write(1, "pb\n", 3);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
//		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	else if (lst_b->head->nb > lst_a->tail->nb)
	{
//		write(1, "pa\nra\n", 6);
		pa(&lst_a, &lst_b);
		ra(&lst_a, 1);
	}
	else
	{
		while (lst_a->head->nb < lst_b->head->nb)
		{
//			write(1, "ra\n", 3);
			ra(&lst_a, 1);
		}
//		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	while (is_sorted(lst_a) != 1)
	{
//		write(1, "rra\n", 4);
		rra(&lst_a, 1);
	}
}

void	five_swap(t_list *lst_a, t_list *lst_b)
{
	int i = 0;
	int	trash;
	int count = 0;
//	write(1, "pb\npb\n", 6);
	pb(&lst_a, &lst_b);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
		if (lst_b->head->nb > lst_b->head->next->nb)
		{
//			write(1, "pa\n", 3);
			pa(&lst_a, &lst_b);
			i++;
		}
//		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
		i++;
		if (i < 2 && lst_b->head->nb > lst_a->tail->nb)
		{
//			write(1, "pa\nra\n", 6);
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			i++;
		}
	}
	if (i < 2 && (lst_b->head->nb > lst_a->tail->nb))
	{
		if (lst_b->head->nb < lst_b->head->next->nb)
		{
//			write(1, "pa\nra\n", 6);
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			i++;
		}
//		write(1, "pa\nra\n", 6);
		pa(&lst_a, &lst_b);
		ra(&lst_a, 1);
		i++;
		if (i < 2 && lst_b->head->nb < lst_a->head->nb)
		{
//			write(1, "pa\n", 3);
			pa(&lst_a, &lst_b);
			i++;
		}
	}
	if (i == 0 && (lst_b->head->next->nb > lst_a->tail->nb || lst_b->head->next->nb < lst_a->head->nb))
	{
//		write(1, "rb\npa\n", 6);
		rb(&lst_b, 1);
		pa(&lst_a, &lst_b);
		i++;
	}
	while (i < 2)
	{
		i++;
		int w;
		w = get_lowest_operation(lst_a, lst_b->head->nb, 0, &trash);
		if (!(lst_b->head->nb < lst_a->head->nb && lst_b->head->nb > lst_a->tail->nb))
		{	
			if (w >= 0)
			{
				while (lst_a->head->nb > lst_b->head->nb)
				{
//					write(1, "ra\n", 3);
					ra(&lst_a, 1);
				}
				while (lst_a->head->nb < lst_b->head->nb)
				{
//					write(1, "ra\n", 3);
					ra(&lst_a, 1);
				}
			}
			else if (w < 0)
			{
				while (lst_a->tail->nb < lst_b->head->nb)
				{
//					write(1, "rra\n", 4);
					rra(&lst_a, 1);
				}
				while (lst_a->tail->nb > lst_b->head->nb)
				{
//					write(1, "rra\n", 4);
					rra(&lst_a, 1);
				}
			}
		}
//		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	int x = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (x == 1)
		{
//			write(1, "ra\n", 3);
			ra(&lst_a, 1);
		}
		else
		{
//			write(1, "rra\n", 4);
			rra(&lst_a, 1);
		}
	}
}

int	abso(int nb)
{
	if (nb == -2147483648)
		return (0);
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	hundred_swap(t_list *lst_a, t_list *lst_b, int size)
{
	int	sorted;
	int	max_chunk;
	int	chunk_size;
	int	direction;
	int	up;
	int	down;
	int	target;

	sorted = 0;
	chunk_size = 0;
	up = 0;
	down = 0;
	int ahah = 40;
	int i = 0;
	while (size > 0 || chunk_size > 0)
	{
		if (chunk_size == 0)
		{
			if ((size - ahah) < 0)
				ahah = size;
			size -= ahah;
			chunk_size = ahah;
			max_chunk = get_nth_nb(lst_a, ahah);
		}
		i++;
		direction = get_closest_nb(lst_a, max_chunk, &target);
		if (lst_b->head != NULL)
		{
/*			write(1, "Step ", 5);
			ft_putnbr(i);
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "Target :\n", 9);
			ft_putnbr(target);
			write(1, "\nMax Chunk :\n", 13);
			ft_putnbr(max_chunk);
			write(1, "\n", 1);
			write(1, "\n", 1);
			write(1, "Direction :\n", 12);
			ft_putnbr(direction);
			write(1, "\nList A :\n", 10);
			print_list(lst_a);
			write(1, "Size :\n", 7);
			ft_putnbr(lst_size(lst_a));
			write(1, "\nList B :\n", 10);
			print_list(lst_b);
			write(1, "Size :\n", 7);
			ft_putnbr(lst_size(lst_b));
			write(1, "\n", 1);
*/			if (get_up_down(lst_b, target, &up, &down) <= 0)
			{
				int p = put_to_head(lst_b, down);
				int lstt;
				int g;
/*				write(1, "to_head :\n", 10);
				ft_putnbr(p);
				write(1, "\n\n", 2);
*/				if (abso(direction) > abso(p))
				{
					g = abso(direction);
					lstt = lst_size(lst_a);
				}
				else
				{
					g = abso(p);
					lstt = lst_size(lst_b);
				}
				if ((abso(direction) + abso(p)) > (lstt - g))
					{
						if (abso(direction) > abso(put_to_head(lst_b, down)))
						{
							if (direction > 0)
							{
								while (lst_a->head->nb > max_chunk && lst_b->head->nb != down)
								{
								//	write(1, "rrr\n", 4);
									rrr(&lst_a, &lst_b);
								}
							}
							if (direction < 0)
							{
								while (lst_a->head->nb > max_chunk && lst_b->head->nb != down)
								{
								//	write(1, "rr\n", 3);
									rr(&lst_a, &lst_b);
								}
							}
						}
					}
				else if (direction > 0 && put_to_head(lst_b, down) > 0)
				{
					while (lst_a->head->nb > max_chunk && lst_b->head->nb != down)
					{
					//	write(1, "rr\n", 3);
						rr(&lst_a, &lst_b);
					}
				}
				else if (direction < 0 && put_to_head(lst_b, down) < 0)
				{
					while (lst_a->head->nb > max_chunk && lst_b->head->nb != down)
					{	
					//	write(1, "rrr\n", 4);
						rrr(&lst_a, &lst_b);
					}
				}
			}
			else
			{
				int t = put_to_tail(lst_b, up);
/*				write(1, "to_tail :\n", 10);
				ft_putnbr(t);
				write(1, "\n\n", 2);
*/				if (abso(direction) + abso(put_to_tail(lst_b, up)) >
					lst_size(abso(direction) > abso(put_to_tail(lst_b, up)) ?
					lst_a : lst_b) - (abso(direction) > abso(put_to_tail(lst_b,
					up)) ? abso(direction) : abso(put_to_tail(lst_b, up))))
				{
					if (abso(direction) > abso(put_to_head(lst_b, down)))
					{
						if (direction > 0)
						{
							while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
							{
					//			write(1, "rrr\n", 4);
								rrr(&lst_a, &lst_b);
							}
						}
						if (direction < 0)
						{
							while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
							{
					//			write(1, "rr\n", 3);
								rr(&lst_a, &lst_b);
							}
						}
					}
				}
				else if (direction > 0 && put_to_tail(lst_b, up) > 0)
				{
					while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
					{
					//	write(1, "rr\n", 3);
						rr(&lst_a, &lst_b);
					}
				}
				else if (direction < 0 && put_to_head(lst_b, down) < 0)
				{
					while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
					{
					//	write(1, "rrr\n", 4);
						rrr(&lst_a, &lst_b);
					}
				}
			}
		}
		direction = get_closest_nb(lst_a, max_chunk, &target);
		if (direction > 0)
		{
			while (lst_a->head->nb > max_chunk)
			{
			//	write(1, "ra\n", 3);
				ra(&lst_a, 1);
			}
		}
		else if (direction < 0)
		{
			while (lst_a->head->nb > max_chunk)
			{
			//	write(1, "rra\n", 4);
				rra(&lst_a, 1);
			}
		}
		if (lst_b->head != NULL)
		{
			if (get_up_down(lst_b, lst_a->head->nb, &up, &down) <= 0)
			{
				if (put_to_head(lst_b, down) > 0)
				{
					while (lst_b->head->nb != down)
					{
					//	write(1, "rb\n", 3);
						rb(&lst_b, 1);
					}
				}
				else if (put_to_head(lst_b, down) < 0)
				{
					while (lst_b->head->nb != down)
					{
					//	write(1, "rrb\n", 4);
						rrb(&lst_b, 1);
					}
				}
			}
			else
			{
				if (put_to_tail(lst_b, up) > 0)
				{
					while (lst_b->tail->nb != up)
					{
					//	write(1, "rb\n", 3);
						rb(&lst_b, 1);
					}
				}
				else if (put_to_tail(lst_b, up) < 0)
				{
					while (lst_b->tail->nb != up)
					{
					//	write(1, "rrb\n", 4);
						rrb(&lst_b, 1);
					}
				}
			}
		}
//		write(1, "pb\n", 3);
		pb(&lst_a, &lst_b);
		chunk_size--;
	}
	while (lst_b->head)
	{
//		write(1, "pa\n", 3);
		pa(&lst_a, &lst_b);
	}
	int x = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (x == 1)
		{
//			write(1, "ra\n", 3);
			ra(&lst_a, 1);
		}
		else
		{
//			write(1, "rra\n", 4);
			rra(&lst_a, 1);
		}
	}
}

int	push_swap(t_list *lst_a, t_list *lst_b, int size ,int med)
{
	if (is_sorted(lst_a) == 1)
		return (0);
	if (size == 2)
	{
//		write(1, "sa\n", 3);
		sa(&lst_a, 1);
	}
	if (size == 3)
		three_swap(lst_a);
	if (size == 4)
		four_swap(lst_a, lst_b);
	if (size == 5)
		five_swap(lst_a, lst_b);
	if (size > 5)
		hundred_swap(lst_a, lst_b, size);
}
