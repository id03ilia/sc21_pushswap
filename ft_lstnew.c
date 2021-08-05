/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:10:25 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:10:26 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
