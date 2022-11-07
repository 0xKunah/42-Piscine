/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:20:41 by bboisson          #+#    #+#             */
/*   Updated: 2022/08/14 18:02:10 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_str(char *str);

int	ft_opposite(int **rules, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			if ((rules[i][j] + rules[i + 1][j]) > (size + 1))
			{
				ft_print_str("Error : combi impossible");
				return (0);
			}
			j++;
		}
		i += 2;
	}
	return (1);
}

int	ft_n_same_line(int **rules, int nb, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		k = 0;
		while (j < size)
		{
			if ((rules[i][j]) == nb)
				k++;
			j++;
			if (k > 1)
			{
				ft_print_str("Error : too much n on 1 line");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_compare(int **rules, int size)
{
	if (!ft_opposite(rules, size))
		return (0);
	if (!ft_n_same_line(rules, size, size) 
		|| !ft_n_same_line(rules, 1, size))
		return (0);
	return (1);
}
