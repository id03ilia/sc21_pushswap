/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vibor_razmetki.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:09:05 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:09:06 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	i_ravno_2(t_A_stack **a)
{
	t_A_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->marker = tmp->marker2;
		tmp->razmtk = tmp->razmtk2;
		tmp = tmp->nexta;
	}
}

int	vibor_razmtki5(t_A_stack **a, t_A_stack *t, t_A_stack *t2)
{
	int			i;

	if (t->marker > t2->marker2)
		i = 2;
	else
	{
		if (t->marker == t2->marker2)
		{
			if (t->index <= t2->index)
				i = 1;
			else
				i = 2;
		}
		else
			i = 1;
	}
	if (i == 2)
		i_ravno_2(a);
	return (i);
}

int	vibor_razmtki100(t_A_stack **a, t_A_stack *t, t_A_stack *t2)
{
	int			i;

	if (t->marker > t2->marker2)
		i = 2;
	else
	{
		if (t->marker == t2->marker2)
		{
			if (t->index < t2->index)
				i = 1;
			else
				i = 2;
		}
		else
			i = 1;
	}
	if (i == 2)
		i_ravno_2(a);
	return (i);
}
