/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_A_rovno.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:08:28 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:08:29 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	st_A_Ra_Or_Rra(t_A_stack **a, int i_min, int s)
{
	if ((i_min > s / 2) && (i_min < s))
	{
		i_min = s - i_min;
		while (i_min > 0)
		{
			rra(a, 1);
			i_min--;
		}
	}
	else
	{
		while (i_min > 0)
		{
			ra(a, 1);
			i_min--;
		}
	}
}

void	st_A_rovno(t_A_stack **a)
{
	t_A_stack	*tempa;
	t_A_stack	*l_a;
	int			i;
	int			i_min_b;
	int			i_min;

	tempa = *a;
	i_min_b = tempa->index;
	i = 0;
	i_min = 0;
	while (tempa)
	{
		if (i_min_b >= tempa->index && i_min_b > 0)
		{
			i_min_b = tempa->index;
			i_min = i;
		}
		i++;
		tempa = tempa->nexta;
	}
	l_a = *a;
	st_A_Ra_Or_Rra(a, i_min, ft_lstsize(&l_a));
}
