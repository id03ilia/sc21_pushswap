#include "push_swap.h"

void	rra(t_A_stack **a, int y)
{
	t_A_stack	*t_first;
	t_A_stack	*t_last;
	t_A_stack	*t_last_pre;
	int			s;
	int			i;

	i = 0;
	t_first = *a;
	s = ft_lstsize(a);
	*a = t_first;
	if ((*a != NULL) && ((*a)->nexta != NULL))
	{
		while (i++ < s - 1)
		{
			t_last_pre = *a;
			*a = (*a)->nexta;
		}
		t_last = *a;
		(*a)->nexta = t_first;
		*a = t_last_pre;
		(*a)->nexta = NULL;
		*a = t_last;
		if (y == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_A_stack **b, int y)
{
	t_A_stack	*t_first;
	t_A_stack	*t_last;
	t_A_stack	*t_last_pre;
	int			s;
	int			i;

	i = 0;
	t_first = *b;
	s = ft_lstsizeB(b);
	*b = t_first;
	if ((*b != NULL) && ((*b)->nextb != NULL))
	{
		while (i++ < s - 1)
		{
			t_last_pre = *b;
			*b = (*b)->nextb;
		}
		t_last = *b;
		(*b)->nextb = t_first;
		*b = t_last_pre;
		(*b)->nextb = NULL;
		*b = t_last;
		if (y == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_A_stack **a, t_A_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
