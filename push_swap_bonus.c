/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:07:15 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:07:16 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str_eof(char *str)
{
	if (str[0] == '\0')
		error(-1);
}

int	check_sort_a(t_A_stack **a, t_A_stack **b)
{
	t_A_stack	*t;
	int			i;

	i = 0;
	t = *a;
	if (*b == NULL)
	{
		while (t != NULL)
		{
			if (t->index != i)
				return (0);
			i++;
			t = t->nexta;
		}
	}
	return (1);
}

static void	check_line2(t_A_stack **a, t_A_stack **b, char **line)
{
	if (ft_strnstr("rra", (*line), 3))
		rra(a, 0);
	else
		if (ft_strnstr("rrb", (*line), 3))
			rrb(b, 0);
	else
		if (ft_strnstr("rrr", (*line), 3))
			rrr(a, b, 0);
	else
		if (ft_strnstr("pa", (*line), 2))
			pa(a, b, 0);
	else
		if (ft_strnstr("pb", (*line), 2))
			pb(a, b, 0);
	else
		error(1);
}

static void	check_line(t_A_stack **a, t_A_stack **b, char **line)
{
	if (ft_strlen(*line) == 1 || ft_strlen(*line) == 0)
		error(1);
	if (ft_strnstr("sa", (*line), 2))
		sa(a);
	else
		if (ft_strnstr("sb", (*line), 2))
			sb(b, 0);
	else
		if (ft_strnstr("ra", (*line), 2))
			ra(a, 0);
	else
		if (ft_strnstr("rb", (*line), 2))
			rb(b, 0);
	else
		if (ft_strnstr("rr", (*line), 2))
			rr(a, b, 0);
	else
		check_line2(a, b, line);
}

int	main(int argc, char **argv)
{
	t_A_stack	*a;
	t_A_stack	*b;
	char		*line;

	a = create_steakA(argc, argv, &a);
	dublikat(&a);
	index_mas_A(&a);
	while (get_next_line(&line))
	{
		check_line(&a, &b, &line);
		free(line);
	}
	if (check_sort_a(&a, &b))
	{
		write(1, "OK", 2);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "KO", 2);
		write(1, "\n", 1);
	}
	return (0);
}
