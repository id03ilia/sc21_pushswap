/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:06:47 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:06:48 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_A_stack **a, t_A_stack **b, int i)
{
	t_A_stack	*ta;
	t_A_stack	*tb;
	t_A_stack	*t;

	if (*a != NULL)
	{
		ta = *a;
		tb = *b;
		*b = ta;
		(*b)->nextb = tb;
		t = (*a)->nexta;
		(*a)->nexta = NULL;
		*a = t;
		if (i == 1)
			write(1, "pb\n", 3);
	}
}

void	pa(t_A_stack **a, t_A_stack **b, int i)
{
	t_A_stack	*ta;
	t_A_stack	*tb;
	t_A_stack	*t;

	if (*b != NULL)
	{
		ta = *a;
		tb = *b;
		*a = tb;
		(*a)->nexta = ta;
		t = (*b)->nextb;
		(*b)->nextb = NULL;
		*b = t;
		if (i == 1)
			write(1, "pa\n", 3);
	}
}
