/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:22:39 by bzentout          #+#    #+#             */
/*   Updated: 2022/08/14 20:08:39 by bboisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_str(char *str);

int	ft_check_value(char **argv, int *size)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((i + 1) % 2)
		{
			if (!(argv[1][i] > '0' && argv[1][i] <= (*size + 48)))
			{
				ft_print_str("Error");
				return (0);
			}
			i++;
		}
		else
		{
			if (argv[1][i] != ' ')
			{
				ft_print_str("Error");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	ft_check_input(int argc, char **argv, int *size)
{
	int	i;

	if (argc != 2)
	{
		ft_print_str("Error");
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	if ((i + 1) % (2 * 4))
	{
		ft_print_str("Error");
		return (0);
	}
	*size = ((i + 1) / 2 / 4);
	if (!ft_check_value(argv, size))
		return (0);
	return (1);
}
