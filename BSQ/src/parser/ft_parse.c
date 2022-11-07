/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:53:16 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/24 16:44:04 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../../includes/parser.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest + ft_strlen(dest);
	while (*src != '\0')
		*ptr++ = *src++;
	*ptr++ = '\0';
	return (dest);
}

char	*parse_first_line_info(char *str)
{
	int		fd;
	int		cpt;
	char	*my_first_line;
	char	buffer[1];
	int		range;

	fd = 0;
	cpt = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &buffer[0], 1))
	{
		if (buffer[0] == '\n')
			break ;
		cpt++;
	}
	my_first_line = malloc(sizeof(char) * cpt);
	range = 0;
	fd = open(str, O_RDONLY);
	while (range < cpt)
		read(fd, &my_first_line[range++], 1);
	return (my_first_line);
}

char	*parse_file(char *path, char *first_line)
{
	int		fd;
	int		len;
	char	*str;
	int		index;
	char	input;

	index = 0;
	len = file_len(path);
	if (len == -1)
		return (NULL);
	fd = open(path, O_RDONLY);
	input = '0';
	while (input != '\n')
		read(fd, &input, 1);
	str = malloc(sizeof(char) * (len - ft_strlen(first_line)));
	while (read(fd, &str[index], 1))
		index++;
	str[index] = '\0';
	return (str);
}

/*Renvoie une structure t_verif pour la map
prend en parametre la 1ere ligne du fichier et
la longueur d'une ligne*/
t_verif	parse_param(char *str, int len_line)
{
	t_verif	tab;
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (is_number(str[i]))
	{	
		num = num * 10 + (str[i] - 48);
		i++;
	}
	tab.nb_lines = num;
	tab.empty = str[i];
	tab.obstacle = str[i + 1];
	tab.full = str[i + 2];
	tab.line_len = len_line;
	return (tab);
}
