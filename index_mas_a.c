#include "push_swap.h"

static int	index_mas_a2(t_A_stack **a, int *mas, int l_A)
{
	t_A_stack	*t;
	int			i;

	t = *a;
	i = 0;
	while (t != NULL)
	{
		i = 0;
		while (i < l_A)
		{
			if (mas[i] == t->numb)
			{
				t->index = i;
				break ;
			}
			i++;
		}
		t = t->nexta;
	}
	if (i > 0)
		return (0);
	else
		return (-1);
}

static int	*sort_vstavka(int *mas, int l_A)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < l_A)
	{
		x = mas[i];
		j = i;
		while ((j > 0) && (mas[j - 1] > x))
		{
			mas[j] = mas[j - 1];
			j--;
		}
		mas[j] = x;
		i++;
	}
	return (mas);
}

void	index_mas_A(t_A_stack **a)
{
	t_A_stack	*t;
	int			i;
	int			l_A;
	int			*mas;

	t = *a;
	l_A = ft_lstsize(&t);
	mas = malloc(sizeof(int) * l_A);
	if (!mas)
		error (-1);
	mas[l_A] = '\0';
	t = *a;
	i = 0;
	while (t != NULL)
	{
		mas[i] = t->numb;
		t->nextb = NULL;
		t = t->nexta;
		i++;
	}
	mas = sort_vstavka(mas, l_A);
	i = index_mas_a2(a, mas, l_A);
	free(mas);
}
