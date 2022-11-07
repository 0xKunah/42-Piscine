/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:55:01 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/21 20:44:42 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		checkbase(char *base);
int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);

int	getsize(long int n, int size)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= size)
	{
		n /= size;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(long int nb, char *base, char *str)
{
	int	len;

	len = checkbase(base);
	if (!len)
		return ;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	if (nb >= len)
	{
		ft_putnbr_base(nb / len, base, str);
		ft_putnbr_base(nb % len, base, str);
	}
	else
		str[ft_strlen(str)] = base[nb];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		converted;
	char	*str;

	converted = ft_atoi_base(nbr, base_from);
	str = malloc((getsize(converted, ft_strlen(base_to)) + 300) * sizeof(char));
	str[0] = '\0';
	if (str == NULL)
		return (0);
	ft_putnbr_base(converted, base_to, str);
	str[ft_strlen(str)] = '\0';
	return (str);
}
