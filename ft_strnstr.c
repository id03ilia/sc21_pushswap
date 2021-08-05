/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:10:16 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:10:17 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	b;
	size_t	k;

	i = 0;
	l = ft_strlen(little);
	b = ft_strlen(big);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		if ((big[i] == little[k]) && ((i + l) <= len))
		{
			while ((k < l) && (big[i + k] == little[k]))
			{
				if ((k + 1) == l)
					return ((char *)big + i);
				k++;
			}
		}
		i++;
	}
	return (0);
}
