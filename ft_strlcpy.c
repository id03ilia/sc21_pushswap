/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:18:19 by dflorenc          #+#    #+#             */
/*   Updated: 2021/04/21 10:27:29 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	k;

	k = 0;
	if ((dst == NULL) && (src == NULL))
		return (0);
	if (size > 0)
	{
		while (k < (size - 1) && src[k] != 0)
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = 0;
	}
	while (src[k] != 0)
		k++;
	return (k);
}
