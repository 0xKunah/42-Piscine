/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:22:51 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/24 15:19:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	ft_non_printable(char c)
{
	if (c != '\n' && ((c > 0 && c <= 31) || c == 127))
		return (1);
	return (0);
}

int	ft_not_inside(char c, t_verif verif)
{
	if (c == verif.empty || c == verif.obstacle
		|| c == verif.full || c == '\n' || c == '\0')
		return (0);
	return (1);
}

/*Verifie si la 1ere lignes contient toute les infos 
necessaire : 
	- Il y a 4 char (len ligne,empty,obstacle,full)
	- Il n'y a pas 2 fois le meme char
	- Ils sont tout affichage*/

int	verif_first_line(char *str)
{
	int	i;
	int	j;
	int	matching;

	matching = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_non_printable(str[i]))
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				matching++;
			if (matching == 2)
				return (0);
			j++;
		}
		matching = 0;
		i++;
	}
	return (1);
}
/*Verification de la carte pour abort en cas d'erreur 
Renvoie la carte si tout est bon
Renvoie NULL si une regle n'est pas respecter*/


char	**ft_verif_map(char **map, t_verif verif)
{
	int	n;
	int	ref_len;
	int	len_line;
	int	index;

	if (!map || verif.nb_lines < 1)
		return (NULL);
	n = 0;
	ref_len = 0;
	while (n < verif.nb_lines - 1)
	{
		index = 0;
		len_line = ft_strlen(map[n]);
		if (n == 0)
			ref_len = len_line;
		if (len_line < 1 || len_line != ref_len)
			return (NULL);
		while (index < ref_len)
			if (ft_not_inside(map[n][index], verif)
			|| ft_non_printable(map[n][index++]))
				return (NULL);
		n++;
	}
	return (map);
}

int	is_number(char c)
{
	return ((c >= '0' && c <= '9'));
}
