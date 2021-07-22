#include "push_swap.h"

static int	proverka_dubl(t_A_stack *ta, int t_i, int i)
{
	int	j;

	j = 0;
	while (ta && j < i)
	{
		if (ta->numb == t_i)
			return (1);
		ta = ta->nexta;
		j++;
	}
	return (0);
}

void	dublikat(t_A_stack **a)
{
	t_A_stack	*te;
	t_A_stack	*l;
	int			i;
	int			n;

	te = *a;
	i = 1;
	te = te->nexta;
	l = *a;
	n = ft_lstsize(&l);
	while (i < n)
	{
		if (proverka_dubl(*a, te->numb, i))
			error (-1);
		te = te->nexta;
		i++;
	}
}
