#include "push_swap.h"

static void	stB_to_stA(t_A_stack *min_b, t_A_stack **a, t_A_stack **b)
{
	int	j;
	int	b_j;

	if (min_b->razmtk2 > 0)
		while (min_b->razmtk2-- > 0)
			rr(a, b);
	else
		while (min_b->razmtk2++ < 0)
			rrr(a, b);
	b_j = min_b->marker;
	j = min_b->marker2;
	if (b_j > 0)
		while (b_j-- > 0)
			rb(b, 1);
	else
		while (b_j++ < 0)
			rrb(b, 1);
	if (j > 0)
		while (j-- > 0)
			ra(a, 1);
	else
		while (j++ < 0)
			rra(a, 1);
	pa(a, b);
}

void	mark_and_BtoA(t_A_stack **a, t_A_stack **b, int s)
{
	t_A_stack	*min_b;
	t_A_stack	*tempa;
	int			s_a;

	tempa = *a;
	s_a = ft_lstsize(&tempa);
	while (s > 0)
	{
		st_B_markirovka(a, b, s_a, s);
		min_b = st_B_min_mark(b);
		stB_to_stA(min_b, a, b);
		s--;
		s_a++;
	}
}
