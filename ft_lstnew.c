#include "push_swap.h"

t_A_stack	*ft_lstnew(int content)
{
	t_A_stack	*a;

	a = malloc(sizeof(t_A_stack));
	if (!a)
		return (NULL);
	a->numb = content;
	a->nexta = NULL;
	return (a);
}
