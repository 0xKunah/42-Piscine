/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:45:49 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/14 22:21:37 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include <stdlib.h>
# include "utils.h"

// Backtrack
int	solve(int **grid, int size, int row, int col);
int	**create_grid(int size);

// Solver
int *g_up;
int *g_right;
int *g_down;
int *g_left;

typedef struct s_coords {
	int	row;
	int	col;
}	t_coords;

int	check_left_constraints(int **grid, int size, t_coords coords, int n);
int	check_right_constraints(int **grid, int size, t_coords coords, int n);
int	check_up_constraints(int **grid, int size, t_coords coords, int n);
int	check_down_constraints(int **grid, int size, t_coords coords, int n);
int	check_validity(int **grid, int size, t_coords coords, int n);

#endif
