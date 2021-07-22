#include "push_swap.h"

static int	proverka_sa_i1(t_A_stack **a, t_A_stack *t, int s)
{
	int	t_numb_pre;
	int	i_after_sa;
	int	i1_do_sa;

	i_after_sa = 0;
	i1_do_sa = t->marker * -1;
	t_numb_pre = t->numb;
	while (s > 0)
	{
		if (t_numb_pre <= t->numb)
		{
			i_after_sa++;
			t_numb_pre = t->numb;
		}
		t = t->nexta;
		if (t == NULL)
			t = *a;
		s--;
	}
	if (i1_do_sa < i_after_sa)
		i_after_sa = 1;
	else
		i_after_sa = 0;
	return (i_after_sa);
}

static int	proverka_sa_i2(t_A_stack **a, t_A_stack *t, int s)
{
	int	t_index;
	int	i_after_sa;
	int	i1_do_sa;

	i_after_sa = 0;
	i1_do_sa = t->marker * -1;
	t_index = t->index;
	while (s > 0)
	{
		if (t_index == t->index)
		{
			i_after_sa++;
			t_index = t_index + 1;
		}
		t = t->nexta;
		if (t == NULL)
			t = *a;
		s--;
	}
	if (i1_do_sa < i_after_sa)
		i_after_sa = 1;
	else
		i_after_sa = 0;
	return (i_after_sa);
}

int	proverka_sa(t_A_stack **a, t_A_stack *t, int i)
{
	int			i_sa;
	t_A_stack	*l_a;
	int			s;

	sa(a);
	l_a = *a;
	s = ft_lstsize(&l_a);
	if (s <= 5)
	{
		if (i == 1)
			i_sa = proverka_sa_i1(a, t, s);
		else
			i_sa = proverka_sa_i2(a, t, s);
	}
	else
		i_sa = 0;
	sa(a);
	return (i_sa);
}

int	proverka_a_fls(t_A_stack **a)
{
	t_A_stack	*t;

	t = *a;
	while (t != NULL)
	{
		if (t->razmtk == 0)
			return (1);
		t = t->nexta;
	}
	return (0);
}

int	check_a_false(t_A_stack **a, int i)
{
	t_A_stack	*t;

	t = *a;
	if (i == 1 && t->razmtk == 0)
		return (1);
	if (i == 2 && t->razmtk2 == 0)
		return (1);
	return (0);
}
