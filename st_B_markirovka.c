/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_B_markirovka.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:08:46 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:08:47 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	st_B_mark_p1(t_A_stack **a, t_A_stack *tpb)
{
	t_A_stack	*temp_a;
	int			j;
	int			j_min;
	int			j_min_temp;

	temp_a = *a;
	j = 0;
	j_min = -1;
	j_min_temp = -1;
	while (temp_a)
	{
		if (tpb->index > temp_a->index && j_min_temp < temp_a->index)
		{
			j_min_temp = temp_a->index;
			j++;
			j_min = j;
		}
		else
			j++;
		temp_a = temp_a->nexta;
	}
	return (j_min);
}

static int	st_B_mark_p2(t_A_stack **a, t_A_stack *tmb, int j_min)
{
	t_A_stack	*tepa;
	int			j;
	int			j_idx;

	j = 1;
	j_idx = 0;
	if (j_min == -1)
	{
		tepa = *a;
		j_idx = tmb->index;
		while (tepa)
		{
			if (j_idx < tepa->index)
			{
				j_idx = tepa->index;
				j_min = j;
			}
			j++;
			tepa = tepa->nexta;
		}
	}
	return (j_min);
}

static void	pozitionInStB(t_A_stack *temb, int b_j, int s_b)
{
	if (b_j > (s_b / 2 + s_b % 2))
		b_j = (s_b - b_j) * -1;
	temb->marker = b_j;
}

static void	pozitionInStA(t_A_stack *teb, int j, int s)
{
	if ((j > (s / 2)) && (j < s))
		j = (s - j) * -1;
	if (j == s)
		j = 0;
	teb->marker2 = j;
}

void	st_B_markirovka(t_A_stack **a, t_A_stack **b, int s, int s_b)
{
	t_A_stack	*tempb;
	int			j;
	int			j_min;
	int			b_j;

	tempb = *b;
	b_j = 0;
	while (tempb)
	{
		j_min = st_B_mark_p1(a, tempb);
		j = st_B_mark_p2(a, tempb, j_min);
		pozitionInStB(tempb, b_j, s_b);
		pozitionInStA(tempb, j, s);
		tempb = tempb->nextb;
		b_j++;
	}
}
