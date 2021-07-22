#include "push_swap.h"

static int	r1_markrA_2(t_A_stack **a, t_A_stack *t2, int n, int y1)
{
	int	i;

	i = 0;
	while (y1 > 0)
	{
		if (n <= t2->numb)
		{
			i++;
			n = t2->numb;
		}
		t2 = t2->nexta;
		if (t2 == NULL)
			t2 = *a;
		y1--;
	}
	return (i);
}

static void	razmt1_markrA(t_A_stack **a)
{
	t_A_stack	*t;
	t_A_stack	*ta;
	t_A_stack	*t2;
	int			i;
	int			y;

	t = *a;
	ta = *a;
	y = ft_lstsize(&ta);
	while (t != NULL)
	{
		t2 = t;
		t->marker = 1;
		i = r1_markrA_2(a, t2, t->numb, y);
		t->marker = i;
		t = t->nexta;
	}
}

static t_A_stack	*razmt1sch_max_mark(t_A_stack **a)
{
	t_A_stack	*t;
	t_A_stack	*t_mark;

	t = *a;
	t_mark = t;
	while (t != NULL)
	{
		if (t_mark->marker < t->marker)
			t_mark = t;
		else
			if (t_mark->marker == t->marker)
				if (t_mark->index >= t->index)
					t_mark = t;
		t = t->nexta;
	}
	t_mark->marker = t_mark->marker * -1;
	return (t_mark);
}

static void	raztka1_po_max_markr(t_A_stack **a, t_A_stack *t, int y1)
{
	int	pre_numb;

	pre_numb = t->numb;
	while (y1 > 0)
	{
		if (pre_numb <= t->numb)
		{
			pre_numb = t->numb;
			t->razmtk = 1;
		}
		else
			t->razmtk = 0;
		t = t->nexta;
		if (t == NULL)
			t = *a;
		y1--;
	}
}

t_A_stack	*razmtka1(t_A_stack **a)
{
	t_A_stack	*ta;
	t_A_stack	*t_mark;
	int			y;

	razmt1_markrA(a);
	t_mark = razmt1sch_max_mark(a);
	ta = *a;
	y = ft_lstsize(&ta);
	raztka1_po_max_markr(a, t_mark, y);
	return (t_mark);
}
