/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:23:43 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 17:55:25 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../includes/types/t_list.h"

#include <stdio.h>

t_list	*ft_create_elem(char elem)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->c = elem;
		tmp->next = NULL;
	}
	return (tmp);
}

char	*parse_stdin_param(char *str)
{
	printf("BEGIN PARSE PARAM STDIN");
	int		n;
	char	*my_line;
	int		cpt;

	cpt = 0;
	n = 0;
	while (str[n] != '\n')
		n++;

	my_line = malloc(sizeof(char) * n);
	while (cpt < n)
	{
		my_line[cpt] = str[cpt];
		cpt++;
	}
	return (my_line);
}


int	len_list(t_list *list)
{
	printf("ENTRY LEN LIST");
	int	n;

	n = 0;
	while (list->next->next)
	{
		printf("DEBUG");
		n++;
		list = list->next;
	}
	return (n);
}


int	ft_countl_stdin(char *stdin)
{
	printf("BEGIN COUNT LINE PARAM");
	int	n;
	int	cpt;

	n = 0;
	cpt = 0;
	while (stdin[n])
		if (stdin[n++] == '\n')
			cpt++;
	return (cpt);
}





t_list	*get_stdin(void)
{
	t_list	*list;
	char	buffer[1];

	list = malloc(sizeof(t_list));
	while (read(STDIN_FILENO, &buffer[0], 1))
	{
		list->next = ft_create_elem(buffer[0]);
		list = list->next;
		list->next = NULL;
	}
	return (list);
}

char	*parse_stdin(void)
{
	printf("PARSE STDIN ON \n");
	t_list	*list;
	char	*str;
	int		index;

	index = 0;
	list = get_stdin();
	printf("%c",list->next->next->c);
	if (len_list(list) == 0)
		return (NULL);
	str = malloc(sizeof(char) * (len_list(list) + 1));
	while (list->next)
	{
		str[index] = list->c;
		list = list->next;
		index++;
	}
	str[index] = '\0';
	return (str);
}


