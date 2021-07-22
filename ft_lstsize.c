/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:39:14 by dflorenc          #+#    #+#             */
/*   Updated: 2021/04/29 08:39:22 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_A_stack **lst)
{
	int	i;

	i = 0;
	while (*lst != NULL)
	{
		(*lst) = (*lst)->nexta;
		i++;
	}
	return (i);
}

int	ft_lstsizeB(t_A_stack **lst)
{
	int	i;

	i = 0;
	while (*lst != NULL)
	{
		(*lst) = (*lst)->nextb;
		i++;
	}
	return (i);
}
