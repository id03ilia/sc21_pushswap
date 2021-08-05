/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:08:18 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:08:19 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_A_stack **a)
{
	t_A_stack	*p1;
	t_A_stack	*p2;
	t_A_stack	*p3;

	if ((*a != NULL) && ((*a)->nexta != NULL))
	{
		p1 = *a;
		p2 = p1->nexta;
		p3 = p2->nexta;
		*a = p2;
		(*a)->nexta = p1;
		(*a)->nexta->nexta = p3;
	}
}

void	sb(t_A_stack **b, int i)
{
	t_A_stack	*b1;
	t_A_stack	*b2;
	t_A_stack	*b3;

	if ((*b != NULL) && ((*b)->nextb != NULL))
	{
		b1 = *b;
		b2 = (*b)->nextb;
		b3 = (*b)->nextb->nextb;
		*b = b2;
		(*b)->nextb = b1;
		(*b)->nextb->nextb = b3;
		if (i == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_A_stack **a, t_A_stack **b, int i)
{
	sa(a);
	sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
