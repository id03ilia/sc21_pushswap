#include "push_swap.h"

void	pb(t_A_stack **a, t_A_stack **b)
{
	t_A_stack	*ta;
	t_A_stack	*tb;
	t_A_stack	*t;

	if (*a != NULL)
	{
		ta = *a;
		tb = *b;
		*b = ta;
		(*b)->nextb = tb;
		t = (*a)->nexta;
		(*a)->nexta = NULL;
		*a = t;
		write(1, "pb\n", 3);
	}
}

void	pa(t_A_stack **a, t_A_stack **b)
{
	t_A_stack	*ta;
	t_A_stack	*tb;
	t_A_stack	*t;

	if (*b != NULL)
	{
		ta = *a;
		tb = *b;
		*a = tb;
		(*a)->nexta = ta;
		t = (*b)->nextb;
		(*b)->nextb = NULL;
		*b = t;
		write(1, "pa\n", 3);
	}
}
