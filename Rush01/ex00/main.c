/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:09:45 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/14 20:56:43 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solver.h"
#include "includes/parser.h"


int	main(int argc, char **argv)
{
	int	size;
	int	**rules;
	int	**grid;

	size = 0;
	if (!ft_check_input(argc, argv, &size))
		return (0);
	rules = ft_convert(argv, size);
	if (rules == NULL)
		return (0);
	if (!ft_compare(rules, size))
	{
		ft_free_tab(rules, 4);
		return (0);
	}
	ft_convert_constraints(rules, size);
	grid = create_grid(size);
	ft_include_n(rules, grid, size);
	if (solve(grid, size, 0, 0))
		ft_print_result(grid, size);
	else
		ft_print_str("Erreur");
	//ft_free_constraints();
	ft_free_tab(rules, 4);
	return (0);
}
