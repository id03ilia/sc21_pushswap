/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:08:36 by dflorenc          #+#    #+#             */
/*   Updated: 2021/04/28 21:08:38 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_A_stack **lst, t_A_stack *new)
{
	t_A_stack	*last;

	if (*lst)
	{
		last = *lst;
		while (last->nexta != NULL)
			last = last->nexta;
		last->nexta = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_backB(t_A_stack **lst, t_A_stack *new)
{
	t_A_stack	*last;

	if (*lst)
	{
		last = *lst;
		while (last->nextb != NULL)
			last = last->nextb;
		last->nextb = new;
	}
	else
		*lst = new;
}
