/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:37:06 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/04 11:42:05 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	*alpha;
	int		idx;

	alpha = "abcdefghijklmnopqrstuvwxyz";
	idx = 0;
	while (idx < 26)
	{
		write(1, &alpha[idx], 1);
		idx = idx +1;
	}
}
