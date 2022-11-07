/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:55:46 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/14 17:52:44 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rules_0(int **rules, int **grid, int size, int j)
{
	int	k;

	k = 1;
	grid[0][j] = size;
	if (rules[1][j] == size)
	{
		while (k < size)
		{
			grid[k][j] = size - k;
			k++;
		}
	}
}

void	ft_rules_1(int **rules, int **grid, int size, int j)
{
	int	k;

	k = 1;
	grid[size - 1][j] = size;
	if (rules[0][j] == size)
	{
		while (k < size)
		{
			grid[size - 1 - k][j] = size - k;
			k++;
		}
	}
}

void	ft_rules_2(int **rules, int **grid, int size, int j)
{
	int	k;

	k = 1;
	grid[j][0] = size;
	if (rules[3][j] == size)
	{
		while (k < size)
		{
			grid[j][k] = size - k;
			k++;
		}
	}
}

void	ft_rules_3(int **rules, int **grid, int size, int j)
{
	int	k;

	k = 1;
	grid[j][size - 1] = size;
	if (rules[2][j] == size)
	{
		while (k < size)
		{
			grid[j][size - 1 - k] = size - k;
			k++;
		}
	}
}

void	ft_include_n(int **rules, int **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			if (rules[i][j] == 1)
			{
				if (i == 0)
					ft_rules_0(rules, grid, size, j);
				else if (i == 1)
					ft_rules_1(rules, grid, size, j);
				else if (i == 2)
					ft_rules_2(rules, grid, size, j);
				else if (i == 3)
					ft_rules_3(rules, grid, size, j);
			}
			j++;
		}
		i++;
	}
}
