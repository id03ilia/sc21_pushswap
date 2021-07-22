#include "push_swap.h"

static int	stB_min_rr(t_A_stack **t_b)
{
	int	i;

	i = 0;
	if (((*t_b)->marker < 0) && ((*t_b)->marker2 < 0))
	{
		while (((*t_b)->marker < 0) && ((*t_b)->marker2 < 0))
		{
			(*t_b)->marker = (*t_b)->marker + 1;
			(*t_b)->marker2 = (*t_b)->marker2 + 1;
			i++;
		}
		(*t_b)->razmtk2 = i * -1;
	}
	if (((*t_b)->marker > 0) && ((*t_b)->marker2 > 0))
	{
		while (((*t_b)->marker > 0) && ((*t_b)->marker2 > 0))
		{
			(*t_b)->marker = (*t_b)->marker - 1;
			(*t_b)->marker2 = (*t_b)->marker2 - 1;
			i++;
		}
		(*t_b)->razmtk2 = i;
	}
	return (i);
}

static int	stB_min_sum_step(t_A_stack **t_b)
{
	int			i_t;
	int			i_ta;
	int			i_tb;
	int			i;
	t_A_stack	*tb;

	tb = *t_b;
	i = stB_min_rr(t_b);
	if (i == 0)
		tb->razmtk2 = 0;
	if (tb->marker < 0)
		i_tb = tb->marker * -1;
	else
		i_tb = tb->marker;
	if (tb->marker2 < 0)
		i_ta = tb->marker2 * -1;
	else
		i_ta = tb->marker2;
	i_t = i_ta + i_tb + i;
	return (i_t);
}

t_A_stack	*st_B_min_mark(t_A_stack **b)
{
	t_A_stack	*tempb;
	t_A_stack	*min_b;
	int			i_min_b;
	int			i_t;

	tempb = *b;
	min_b = tempb;
	i_min_b = stB_min_sum_step(&tempb);
	while (tempb)
	{
		i_t = stB_min_sum_step(&tempb);
		if (i_min_b > i_t)
		{
			i_min_b = i_t;
			min_b = tempb;
		}
		tempb = tempb->nextb;
	}
	return (min_b);
}
