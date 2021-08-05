/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:07:24 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:07:25 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_A_stack **a, int i)
{
	t_A_stack	*t;

	t = *a;
	ft_lstadd_back(a, t);
	*a = (*a)->nexta;
	t->nexta = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_A_stack **b, int i)
{
	t_A_stack	*t;

	t = *b;
	ft_lstadd_backB(b, t);
	*b = (*b)->nextb;
	t->nextb = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_A_stack **a, t_A_stack **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
