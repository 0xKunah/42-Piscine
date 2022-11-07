/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:19:41 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/12 14:14:55 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (j <= nb)
	{
		i *= j;
		j++;
	}
	return (i);
}
