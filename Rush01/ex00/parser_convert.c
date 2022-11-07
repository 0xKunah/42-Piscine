/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:16:13 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/14 20:49:22 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/solver.h"

void	ft_tab_char(char **argv, int **rules, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < size)
			{
				rules[j][k] = (argv[1][i] - 48);
				if (!argv[1][i + 1])
					i++;
				else
					i += 2;
				k++;
			}
			j++;
		}
	}
}

int	**ft_convert(char **argv, int size)
{
	int	**rules;
	int	i;

	i = 0;
	rules = malloc(sizeof(rules) * (4 * size));
	if (rules == NULL)
		return (rules);
	while (i < 4)
	{
		rules[i] = malloc(sizeof(rules) * size);
			i++;
	}
	ft_tab_char(argv, rules, size);
	i = 0;
	return (rules);
}

void	ft_free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

void	ft_convert_constraints(int **constraints, int size)
{
	g_up = malloc(sizeof(int) * size);
	g_down = malloc(sizeof(int) * size);
	g_left = malloc(sizeof(int) * size);
	g_right = malloc(sizeof(int) * size);
	g_up = constraints[0];
	g_down = constraints[1];
	g_left = constraints[2];
	g_right = constraints[3];
}

void	ft_free_constraints(void)
{
	free (g_up);
	free (g_down);
	free (g_left);
	free (g_right);
}
