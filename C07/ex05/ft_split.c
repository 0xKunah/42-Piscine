/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:19:04 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/25 16:34:28 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_separator(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = -1;
	while (!ft_is_separator(str[++i], charset))
		;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
		if (ft_is_separator(str[i++], charset))
			count++;
	return (count);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	int		len;
	char	*str;

	len = ft_wordlen(src, charset);
	if (!len)
		return (NULL);
	str = malloc((len + 1) * sizeof(*src));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		words_count;
	char	**tab;
	int		i;

	words_count = ft_count_words(str, charset);
	tab = malloc(sizeof(char *) * (words_count + 1));
	i = 0;
	while (i < words_count)
	{
		while (ft_is_separator(str[0], charset))
			str++;
		tab[i] = ft_strdup(str, charset);
		str += ft_wordlen(str, charset);
		if (tab[i])
			i++;
	}
	tab[i] = "\0";
	return (tab);
}

#include <stdio.h>

int main(void)
{
	char *str = "Ca/va+split*sur////les/slash";
	char **tab = ft_split(str, "/*+");
	int i = 0;
	
	while (i < 6)
	{
		printf("%d: %s ", i, tab[i]);
		i++;
	}
}
