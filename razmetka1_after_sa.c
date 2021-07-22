#include "push_swap.h"

static void	raztka1_po_max_sa(t_A_stack **a, t_A_stack *t, int y1)
{
	int	pre_numb;
	int	i;

	i = 0;
	pre_numb = t->numb;
	while (y1 > 0)
	{
		if (pre_numb <= t->numb)
		{
			pre_numb = t->numb;
			t->razmtk = 1;
			i++;
		}
		else
			t->razmtk = 0;
		t = t->nexta;
		if (t == NULL)
			t = *a;
		y1--;
	}
	t->marker = i * -1;
}

void	raztka1_sa(t_A_stack **a, t_A_stack *t_mark)
{
	t_A_stack	*ta;
	int			y;

	ta = *a;
	y = ft_lstsize(&ta);
	raztka1_po_max_sa(a, t_mark, y);
}
