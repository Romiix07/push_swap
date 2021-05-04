#include "utils.h"
#include "push_swap.h"
#include "unistd.h"

void	three_swap(t_list *lst)
{
	int	nb;
	int	next;
	int	next2;

	nb = lst->head->nb;
	next = lst->head->next->nb;
	next2 = lst->head->next->next->nb;
	if (nb > next && nb < next2)
		sa(&lst, 1);
	else if (nb > next && next > next2)
	{
		sa(&lst, 1);
		rra(&lst, 1);
	}
	else if (nb > next && next < next2)
		ra(&lst, 1);
	else if (nb < next && nb < next2)
	{
		sa(&lst, 1);
		ra(&lst, 1);
	}
	else if (nb < next && nb > next2)
		rra(&lst, 1);
}

void	four_swap(t_list *lst_a, t_list *lst_b)
{
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
		pa(&lst_a, &lst_b);
	else if (lst_b->head->nb > lst_a->tail->nb)
	{
		pa(&lst_a, &lst_b);
		ra(&lst_a, 1);
	}
	else
	{
		while (lst_a->head->nb < lst_b->head->nb)
			ra(&lst_a, 1);
		pa(&lst_a, &lst_b);
	}
	while (is_sorted(lst_a) != 1)
		rra(&lst_a, 1);
}

void	five_swap(t_list *lst_a, t_list *lst_b)
{
	int	i;
	int	trash;
	int	count;
	int	direction;
	int	lowest;

	i = 0;
	count = 0;
	pb(&lst_a, &lst_b);
	pb(&lst_a, &lst_b);
	if (is_sorted(lst_a) != 1)
		three_swap(lst_a);
	if (lst_b->head->nb < lst_a->head->nb)
	{
		if (lst_b->head->nb > lst_b->head->next->nb)
		{
			pa(&lst_a, &lst_b);
			i++;
		}
		pa(&lst_a, &lst_b);
		i++;
		if (i < 2 && lst_b->head->nb > lst_a->tail->nb)
		{
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			i++;
		}
	}
	if (i < 2 && (lst_b->head->nb > lst_a->tail->nb))
	{
		if (lst_b->head->nb < lst_b->head->next->nb)
		{
			pa(&lst_a, &lst_b);
			ra(&lst_a, 1);
			i++;
		}
		pa(&lst_a, &lst_b);
		ra(&lst_a, 1);
		i++;
		if (i++ < 2 && lst_b->head->nb < lst_a->head->nb)
			pa(&lst_a, &lst_b);
	}
	if (i == 0 && (lst_b->head->next->nb > lst_a->tail->nb ||
		lst_b->head->next->nb < lst_a->head->nb))
	{
		rb(&lst_b, 1);
		pa(&lst_a, &lst_b);
		i++;
	}
	while (i < 2)
	{
		i++;
		direction = get_lowest_operation(lst_a, lst_b->head->nb, 0, &trash);
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
	lowest = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (lowest == 1)
			ra(&lst_a, 1);
		else
			rra(&lst_a, 1);
	}
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
	int	ahah;
	int	i;
	int	p;
	int	lstt;
	int	g;
	int	t;
	int	lowest;

	sorted = 0;
	chunk_size = 0;
	up = 0;
	down = 0;
	ahah = 40;
	i = 0;
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
							while (lst_a->head->nb > max_chunk &&
								lst_b->head->nb != down)
								rrr(&lst_a, &lst_b);
						if (direction < 0)
							while (lst_a->head->nb > max_chunk &&
								lst_b->head->nb != down)
								rr(&lst_a, &lst_b);
					}
				}
				else if (direction > 0 && put_to_head(lst_b, down) > 0)
					while (lst_a->head->nb > max_chunk &&
						lst_b->head->nb != down)
						rr(&lst_a, &lst_b);
				else if (direction < 0 && put_to_head(lst_b, down) < 0)
					while (lst_a->head->nb > max_chunk &&
						lst_b->head->nb != down)
						rrr(&lst_a, &lst_b);
			}
			else
			{
				t = put_to_tail(lst_b, up);
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
							while (lst_a->head->nb > max_chunk &&
								lst_b->tail->nb != up)
								rrr(&lst_a, &lst_b);
						if (direction < 0)
							while (lst_a->head->nb > max_chunk &&
								lst_b->tail->nb != up)
								rr(&lst_a, &lst_b);
					}
				}
				else if (direction > 0 && put_to_tail(lst_b, up) > 0)
					while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
						rr(&lst_a, &lst_b);
				else if (direction < 0 && put_to_head(lst_b, down) < 0)
					while (lst_a->head->nb > max_chunk && lst_b->tail->nb != up)
						rrr(&lst_a, &lst_b);
			}
		}
		direction = get_closest_nb(lst_a, max_chunk, &target);
		if (direction > 0)
			while (lst_a->head->nb > max_chunk)
				ra(&lst_a, 1);
		else if (direction < 0)
			while (lst_a->head->nb > max_chunk)
				rra(&lst_a, 1);
		if (lst_b->head != NULL)
		{
			if (get_up_down(lst_b, lst_a->head->nb, &up, &down) <= 0)
			{
				if (put_to_head(lst_b, down) > 0)
					while (lst_b->head->nb != down)
						rb(&lst_b, 1);
				else if (put_to_head(lst_b, down) < 0)
					while (lst_b->head->nb != down)
						rrb(&lst_b, 1);
			}
			else
			{
				if (put_to_tail(lst_b, up) > 0)
					while (lst_b->tail->nb != up)
						rb(&lst_b, 1);
				else if (put_to_tail(lst_b, up) < 0)
					while (lst_b->tail->nb != up)
						rrb(&lst_b, 1);
			}
		}
		pb(&lst_a, &lst_b);
		chunk_size--;
	}
	while (lst_b->head)
		pa(&lst_a, &lst_b);
	lowest = where_is_lowest_nb(lst_a);
	while (is_sorted(lst_a) != 1)
	{
		if (lowest == 1)
			ra(&lst_a, 1);
		else
			rra(&lst_a, 1);
	}
}

int	push_swap(t_list *lst_a, t_list *lst_b, int size, int med)
{
	if (is_sorted(lst_a) == 1)
		return (0);
	if (size == 2)
		sa(&lst_a, 1);
	if (size == 3)
		three_swap(lst_a);
	if (size == 4)
		four_swap(lst_a, lst_b);
	if (size == 5)
		five_swap(lst_a, lst_b);
	if (size > 5)
		hundred_swap(lst_a, lst_b, size);
}
