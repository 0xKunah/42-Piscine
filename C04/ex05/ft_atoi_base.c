/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:33 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/18 10:53:09 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] > 9 && base[i] < 13) || base[i] == 32)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	init(int *count, int *is_negative, int *found_number)
{
	*is_negative = 1;
	*found_number = 0;
	*count = 0;
}

int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	count;
	int	is_negative;
	int	found_number;

	if (!checkbase(base))
		return (0);
	init(&count, &is_negative, &found_number);
	while (*str)
	{
		if (in_base(*str, base) > -1)
		{
			count = count * checkbase(base) + in_base(*str, base);
			found_number = 1;
		}
		else if ((*str == '-' || *str == '+') && !found_number)
		{
			if (*str == '-')
				is_negative *= -1;
		}
		else if (found_number)
			return (count * is_negative);
		str++;
	}
	return (count * is_negative);
}
