#include "push_swap.h"

void	razmt2poMaxMrkSa(t_A_stack **a, t_A_stack *t_mark, int y)
{
	t_A_stack	*t;
	int			i;

	t = t_mark;
	t->razmtk = 1;
	while (y > 0)
	{
		if (t == t_mark)
			i = t->index;
		else
		{
			if (t->index == 1 + i)
			{
				i++;
				t->razmtk = 1;
			}
			else
				t->razmtk = 0;
		}
		t = t->nexta;
		if (t == NULL)
			t = *a;
		y--;
	}
	t->marker = (i - t->index + 1) * -1;
}

void	razmtka2_sa(t_A_stack **a, t_A_stack *t_mark)
{
	t_A_stack	*ta;
	int			y;

	ta = *a;
	y = ft_lstsize(&ta);
	razmt2poMaxMrkSa(a, t_mark, y);
}
