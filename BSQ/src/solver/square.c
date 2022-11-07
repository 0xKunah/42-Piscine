/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:08:53 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:06:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver/square.h"

char	*create_row(int size, char filler)
{
	int		i;
	char	*row;

	i = 0;
	row = malloc(sizeof(char) * size);
	if (!row)
		exit(1);
	while (i < size)
		row[i++] = filler;
	return (row);
}

char	**create_square(int size, char filler)
{
	int		i;
	char	**square;

	i = 0;
	square = malloc(sizeof(char) * (size - 1));
	if (!square)
		exit(1);
	while (i < size)
		square[i++] = create_row(size, filler);
	return (square);
}

void	free_square(char **square, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(square[i]);
	free(square);
}
