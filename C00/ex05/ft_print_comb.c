/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:55:10 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/05 13:16:51 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int a, int b, int c)
{
	char	x;

	x = a + '0';
	write(1, &x, 1);
	x = b + '0';
	write(1, &x, 1);
	x = c + '0';
	write(1, &x, 1);
}

void	print_space(int i)
{
	if (i != 119)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	print_numbers(int *a, int *b, int *c)
{
	int	i;

	i = 0;
	while (i < 120)
	{
		print_number(*a, *b, *c);
		if (*c < 9)
			*c = *c + 1;
		else
		{
			if (*b < 8)
				*b = *b + 1;
			else if (*a < 7)
			{
				*a = *a + 1;
				*b = *a + 1;
			}
			*c = *b + 1;
		}
		print_space(i);
		i++;
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;
	print_numbers(&a, &b, &c);
}
