/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:01:17 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/05 13:40:14 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putsign(int i)
{
	if (i == 1)
		ft_putchar('-');
}

void	ft_putzero(int i)
{
	if (i == 0)
		ft_putchar('0');
}

void	ft_setsign(long *i, int *n)
{
	if (*i < 0)
	{
		*i = -*i;
		*n = 1;
	}
}

void	ft_putnbr(int nb)
{
	int		is_negative;
	long	nbr;
	int		temp;
	long	factor;

	nbr = (long)nb;
	is_negative = 0;
	ft_putzero(nbr);
	ft_setsign(&nbr, &is_negative);
	factor = 1;
	temp = nbr;
	while (temp)
	{
		temp = temp / 10;
		factor = factor * 10;
	}
	ft_putsign(is_negative);
	while (factor > 1)
	{
		factor = factor / 10;
		ft_putchar((nbr / factor) + '0');
		nbr = nbr % factor;
	}
}
