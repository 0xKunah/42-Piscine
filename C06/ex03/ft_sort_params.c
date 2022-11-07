/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:29:37 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/09 14:38:19 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}

void	ft_sort_tab(char **tab, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (++i < size)
	{
		if (ft_strcmp(tab[i - 1], tab[i]) == 1)
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i = 0;
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*t;

	i = 0;
	t = argv[0];
	ft_sort_tab(argv, argc);
	while (argv[i])
	{
		if (argv[i] != t)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
		}
		i++;
	}
	return (0);
}
