/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_backtrack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:41:35 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/14 20:58:10 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solver.h"

t_coords	coords(int x, int y)
{
	t_coords	coords;

	coords.row = x;
	coords.col = y;
	return (coords);
}

int	solve(int **grid, int size, int row, int col)
{
	int	i;

	if (row == size - 1 && col == size)
		return (1);
	if (col == size)
	{
		row++;
		col = 0;
	}
	if (grid[row][col] > 0)
		return (solve(grid, size, row, col + 1));
	i = 1;
	while (i <= size)
	{
		if (check_validity(grid, size, coords(row, col), i))
		{
			grid[row][col] = i;
			if (solve(grid, size, row, col + 1))
				return (1);
		}
		grid[row][col] = 0;
		i++;
	}
	return (0);
}

int	**create_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **) malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		grid[i] = (int *) malloc(size * sizeof(int));
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
