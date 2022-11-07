/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:56:56 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/24 14:57:34 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	check_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	cpt(char *str, char *sep)
{
	int	n;
	int	words;

	words = 0;
	n = 0;
	while (str[n] != '\0')
	{
		if (check_sep(str[n + 1], sep) == 1
			&& check_sep(str[n], sep) == 0)
			words++;
		n++;
	}
	return (words);
}

void	ft_strcpy_s(char *dest, char *from, char *sep)
{
	int	i;

	i = 0;
	while (check_sep(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	tab_write(char **tab, char *str, char *sep)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], sep) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(str[i + j], sep) == 0)
				j++;
			tab[word] = (char *) malloc(sizeof(char) * (j + 1));
			ft_strcpy_s(tab[word], str + i, sep);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		n;

	if (!str)
		return (NULL);
	n = cpt(str, charset);
	res = (char **) malloc(sizeof(char *) * (n));
	res[n] = "\0";
	tab_write(res, str, charset);
	return (res);
}
