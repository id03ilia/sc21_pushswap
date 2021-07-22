#include "push_swap.h"

static int	r2_markrA_2(t_A_stack **a, t_A_stack *t2, int n, int y)
{
	int	i;

	i = 0;
	while (y > 0)
	{
		if (n == t2->index)
		{
			n++;
			i++;
		}
		t2 = t2->nexta;
		if (t2 == NULL)
			t2 = *a;
		y--;
	}
	return (i);
}

static void	razmt2_markA(t_A_stack **a)
{
	t_A_stack	*t;
	t_A_stack	*ta;
	t_A_stack	*t2;
	int			y;
	int			i;

	t = *a;
	ta = *a;
	y = ft_lstsize(&ta);
	while (t != NULL)
	{
		t2 = t;
		i = r2_markrA_2(a, t2, t->index, y);
		t->marker2 = i;
		t = t->nexta;
	}
}

static t_A_stack	*razmt2_1sch_max_mark(t_A_stack **a)
{
	t_A_stack	*t;
	t_A_stack	*t_mark;

	t = *a;
	t_mark = t;
	while (t != NULL)
	{
		if (t_mark->marker2 < t->marker2)
			t_mark = t;
		else
		{
			if (t_mark->marker2 == t->marker2)
				if (t_mark->index >= t->index)
					t_mark = t;
		}
		t = t->nexta;
	}
	t_mark->marker2 = t_mark->marker2 * -1;
	return (t_mark);
}

static void	raztka2_po_max_markr(t_A_stack **a, t_A_stack *t_mark, int y)
{
	t_A_stack	*t;
	int			i;

	i = 0;
	t = t_mark;
	t->razmtk2 = 1;
	while (y > 0)
	{
		if (t == t_mark)
			i = t->index;
		else
		{
			if (t->index == 1 + i)
			{
				i++;
				t->razmtk2 = 1;
			}
			else
				t->razmtk2 = 0;
		}
		t = t->nexta;
		if (t == NULL)
			t = *a;
		y--;
	}
}

t_A_stack	*razmtka2_indx(t_A_stack **a)
{
	t_A_stack	*ta;
	t_A_stack	*t_mark;
	int			y;

	razmt2_markA(a);
	t_mark = razmt2_1sch_max_mark(a);
	ta = *a;
	y = ft_lstsize(&ta);
	raztka2_po_max_markr(a, t_mark, y);
	return (t_mark);
}
