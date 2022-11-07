/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:23:17 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/21 16:15:31 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	diff;

	i = 0;
	diff = max - min;
	if (diff < 1)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(diff * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < diff)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (diff);
}
