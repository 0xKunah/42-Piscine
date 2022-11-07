/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:57:16 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/16 15:06:56 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	tab = malloc(sizeof(char) * len);
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		
	}
}
