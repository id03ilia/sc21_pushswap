/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:12:58 by dflorenc          #+#    #+#             */
/*   Updated: 2021/05/16 15:59:23 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_sifr(char *viv, int k, int m)
{
	unsigned long long	res;
	unsigned long long	c;

	c = 1;
	res = 0;
	while (k > 0)
	{
		res = res + (viv[k - 1] - 48) * c;
		c = c * 10;
		k--;
	}
	if ((res > 9223372036854775807) && (m == 1))
		return (-1);
	if (res > 9223372036854775807 && (m == -1))
		return (0);
	return (res);
}

int	ft_atoi(char *str)
{
	int		m;
	int		s;
	char	cifr[27];

	m = 1;
	s = 0;
	while (((*str > 8) && (*str < 14)) || (*str == 32))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			m = m * -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		cifr[s] = *str;
		str++;
		s++;
	}
	m = ft_atoi_sifr(cifr, s, m) * m;
	return (m);
}
