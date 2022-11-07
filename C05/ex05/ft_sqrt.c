/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:02:56 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/17 16:27:37 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	low;
	int	mid;
	int	high;

	low = 0;
	mid = 0.5 * nb;
	high = nb;
	if (nb == 1)
		return (1);
	while (low < high - 1)
	{
		if (mid == nb / mid)
			return (mid);
		if (mid > nb / mid)
			high = mid;
		else
			low = mid;
		mid = (high + low) / 2;
	}
	return (0);
}
