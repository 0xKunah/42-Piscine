/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:39:14 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/15 16:56:19 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solver.h"
#include <stdio.h>

int	check_left_constraints(int **grid, int size, t_coords coords, int n)
{
	int	i;
	int	highest;
	int	visible_cells;

	i = 0;
	highest = 0;
	visible_cells = 0;
	while (i < size)
	{
		if (grid[coords.row][i] > highest)
		{
			highest = grid[coords.row][i];
			visible_cells++;
		}
		i++;
	}
	if (visible_cells > g_left[coords.row]
		|| max_visible(n, coords.col + 1, size) < g_left[coords.row])
		{
			printf("Erreur left");
			return (0);
		}
	return (1);
}

int	check_right_constraints(int **grid, int size, t_coords coords, int n)
{
	int	i;
	int	highest;
	int	visible_cells;

	i = size - 1;
	highest = 0;
	visible_cells = 0;
	while (i >= 0)
	{
		if (grid[coords.row][i] > highest)
		{
			highest = grid[coords.row][i];
			visible_cells++;
		}
		i--;
	}
	if (visible_cells > g_right[coords.row]
		|| max_visible(n, size - coords.col, size) < g_right[coords.row])
		{
			printf("Erreur right");
			return (0);
		}
	return (1);
}

int	check_up_constraints(int **grid, int size, t_coords coords, int n)
{
	int	i;
	int	highest;
	int	visible_cells;

	i = 0;
	highest = 0;
	visible_cells = 0;
	while (i < size)
	{
		if (grid[i][coords.col] > highest)
		{
			highest = grid[i][coords.col];
			visible_cells++;
		}
		i++;
	}
	if (visible_cells > g_up[coords.col]
		|| max_visible(n, coords.row + 1, size) < g_up[coords.col])
		{
			printf("Erreur up");
			return (0);
		}
	return (1);
}

int	check_down_constraints(int **grid, int size, t_coords coords, int n)
{
	int	i;
	int	highest;
	int	visible_cells;

	i = size - 1;
	highest = 0;
	visible_cells = 0;
	while (i >= 0)
	{
		if (grid[i][coords.col] > highest)
		{
			highest = grid[i][coords.col];
			visible_cells++;
		}
		i--;
	}
	if (visible_cells > g_down[coords.col]
		|| max_visible(n, size - coords.row, size) < g_down[coords.col])
		{
			printf("Erreur down");
			return (0);
		}
	return (1);
}

int	check_validity(int **grid, int size, t_coords coords, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[i][coords.col] == n)
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (grid[coords.row][i] == n)
			return (0);
		i++;
	}
	if (check_left_constraints(grid, size, coords, n)
		&& check_right_constraints(grid, size, coords, n)
		&& check_up_constraints(grid, size, coords, n)
		&& check_down_constraints(grid, size, coords, n))
		return (1);
	return (0);
}
