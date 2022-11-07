/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:22:17 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/14 23:18:08 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/utils.h"

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_print_result(int **grid, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < (size - 1))
				write(1, " ", 1);
			if (j == (size - 1))
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}

int	max_visible(int n, int pos, int size)
{
	if (n == size)
		return (pos);
	if (n == pos)
		return (size);
	if (n > pos)
		return (size - n + pos);
	if (n < pos)
		return (size - 1);
	return (0);
}
