/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkAandPB.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:05:01 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:05:02 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	after_proverka_sa(t_A_stack **a, t_A_stack *t, int i)
{
	write(1, "sa\n", 3);
	if (i == 1)
		raztka1_sa(a, t);
	else
		razmtka2_sa(a, t);
}

int	checkAandPB(t_A_stack **a, t_A_stack **b, t_A_stack *t, int i)
{
	int	s;

	s = 0;
	while (proverka_a_fls(a))
	{
		if (proverka_sa(a, t, i))
		{
			sa(a);
			after_proverka_sa(a, t, i);
		}
		else
		{
			if (check_a_false(a, i))
			{
				pb(a, b, 1);
				s++;
			}
			else
				ra(a, 1);
		}
	}
	return (s);
}
