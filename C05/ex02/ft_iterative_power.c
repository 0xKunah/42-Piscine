/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:33:27 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/09 12:45:46 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	base;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	base = nb;
	while (--power)
		nb *= base;
	return (nb);
}
