/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:10:36 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:10:37 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int i)
{
	if (i > -10)
		write (1, "Error", 5);
	write (1, "\n", 1);
	exit (-1);
}

void	ft_lstclear(t_A_stack **lst)
{
	t_A_stack	*p;

	p = *lst;
	if (!*lst)
		error(-1);
	while (*lst)
	{
		p = (*lst)->nexta;
		free(*lst);
		*lst = NULL;
		*lst = p;
	}
	free(*lst);
	*lst = NULL;
}

void	mall_free(char **res, int r)
{
	while (r >= 0)
	{
		free(res[r]);
		r--;
	}
	free(res);
	res = NULL;
}

void	free_and_error(t_A_stack **a)
{
	ft_lstclear(a);
	error(-1);
}

void	free_mall_and_error(t_A_stack **a, char **mas_numb, int r)
{
	mall_free(mas_numb, r);
	ft_lstclear(a);
	error(-1);
}
