/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:31:42 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/21 17:39:49 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest + ft_strlen(dest);
	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr++ = '\0';
	return (dest);
}

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (strs[i] && i < size)
	{
		if (i + 1 == size)
			len += ft_strlen(strs[i]);
		else
			len += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = get_size(size, strs, sep);
	str = malloc(len * sizeof(char));
	str[0] = '\0';
	if (str != NULL)
	{
		i = 0;
		while (i < size && strs[i])
		{
			if (i + 1 == size || !strs[i + 1])
				ft_strcat(str, strs[i]);
			else
				ft_strcat(ft_strcat(str, strs[i]), sep);
			i++;
		}
	}
	return (str);
}
