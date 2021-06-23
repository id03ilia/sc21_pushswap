/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:18:22 by dflorenc          #+#    #+#             */
/*   Updated: 2021/04/27 13:18:24 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_itoa_out(char	*mem, int n, int min)
{
	int		i;
	int		l;
	char	tmp;

	i = 0;
	while (n > 0)
	{
		mem[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (min == 1)
		mem[i++] = '-';
	if (i == 0)
		mem[i++] = 48;
	mem[i] = '\0';
	l = ft_strlen(mem);
	i = -1;
	while (++i < (l / 2))
	{
		tmp = mem[i];
		mem[i] = mem[l - 1 - i];
		mem[l - 1 - i] = tmp;
	}
	return (mem);
}

static int	ft_itoa_len(int n)
{
	int		nn;
	int		len_num;

	len_num = 0;
	nn = n;
	while (nn > 0)
	{
		nn = nn / 10;
		len_num++;
	}
	if (n == 0)
		len_num++;
	return (len_num);
}

char	*ft_itoa(int n)
{
	char	*mem;
	int		min;

	min = 0;
	if (n == -2147483648)
	{
		mem = (char *)malloc(sizeof(char) * (12));
		if (!mem)
			return (NULL);
		ft_strlcpy(mem, "-2147483648", 12);
		return (mem);
	}
	if (n < 0)
	{
		min = 1;
		n = n * -1;
	}
	mem = (char *)malloc(sizeof(char) * (ft_itoa_len(n) + min + 1));
	if (!mem)
		return (NULL);
	ft_itoa_out(mem, n, min);
	return (mem);
}
