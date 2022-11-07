/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:39:10 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/17 17:20:49 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	init(int *count, int *is_negative, int *found_number)
{
	*is_negative = 1;
	*found_number = 0;
	*count = 0;
}

int	ft_atoi(char *str)
{
	int	count;
	int	is_negative;
	int	found_number;

	init(&count, &is_negative, &found_number);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
		{
			count = count * 10 + (*str - 48);
			found_number = 1;
		}
		else if ((*str == '-' || *str == '+') && !found_number)
		{
			if (*str == '-')
				is_negative *= -1;
		}
		else if (((*str < 9 || *str > 13) && *str != 32) || found_number)
			return (count);
		str++;
	}
	return (count * is_negative);
}
