#include "push_swap.h"

t_A_stack	*ft_lstnew(int content)
{
	t_A_stack	*a;

	a = (t_A_stack *)malloc(sizeof(t_A_stack));
	if (!a)
		return (NULL);
	a->numb = content;
	a->next = NULL;
	return (a);
}

void	ft_lstadd_back(t_A_stack **a, t_A_stack *new)
{
	t_A_stack	*last;

	if (*a)
	{
		last = *a;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		*a = new;
}

void pfint_ps(t_A_stack **p)
{
	t_A_stack	*t;

	t = *p;
	while (t->next != NULL)
	{
		write(1, (ft_itoa(t->numb)), 1);
		write(1, " ", 1);
		t = t->next;
	}
	write(1, (ft_itoa(t->numb)), 1);
}

int		main(int argc, char **argv)
{
	t_A_stack	*temp;
	t_A_stack	**a;
	int 		i;
	t_A_stack	*t;

	a = malloc(sizeof(t_A_stack *));
	*a = NULL;
	i = 1;
	if (argc == 1)
		return 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			temp = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(a, temp);
			i++;
		}
	}
	pfint_ps(a);
	free(a);
	return (0);
//	exit(0);
}
