/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:50:52 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/24 15:53:01 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../../includes/parser.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

/*Cette fonction compte le nombre de \n 
dans un fichier avec open. Renvoie -1 si 
le fichier n'existe pas et un int positif 
pour le nb de lignes

MODE = 0 => Prend l'entrée standard 
MODE = 1 => Prend str en argument*/

int	file_len(char *path)
{
	int		fd;
	char	buffer[1];
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buffer, 1))
		i++;
	return (i);
}

int	ft_count_line(int mode, char *str)
{
	char	*file;
	int		size;
	int		n_cout;
	int		fd;
	int		len;

	n_cout = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1 && mode)
		return (-1);
	file = parse_file(str, "");
	if (!file)
		return (-1);
	size = 0;
	len = file_len(str);
	while (size < len)
	{
		if (file[size] == '\n')
			n_cout++;
		size++;
	}
	return (n_cout);
}


