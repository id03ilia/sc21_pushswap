/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:04:49 by dflorenc          #+#    #+#             */
/*   Updated: 2021/08/04 15:04:50 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_line(char **line)
{
	if (*line)
	{
		while (*line)
		{
			free(*line);
			*line = NULL;
			(*line)++;
		}
		free(line);
	}
}

int	get_next_line(char **line)
{
	char	*arr;
	int		i;
	char	buff;

	i = 0;
	if (!line)
		return (-1);
	arr = malloc(4);
	if (!arr)
		return (-1);
	while (read(0, &buff, 1) > 0)
	{
		arr[i] = buff;
		if (arr[i] == '\n')
		{
			arr[i] = '\0';
			*line = arr;
			return (1);
		}
		++i;
	}
	arr[i] = '\0';
	*line = arr;
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &(s[i]), 1);
			i++;
		}
	}
}
