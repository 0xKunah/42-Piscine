/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:59:39 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 17:45:26 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/types/t_map.h"
#include "../includes/types/t_verif.h"
#include "../includes/print.h"
#include "../includes/parser.h"
#include "../includes/solver/solve.h"
#include "../includes/types/t_list.h"

/*Fonction main : Parse les arguments et verifie
si les maps fournis en arguments sont correct

Si pas d'argument -> Prendre le carée de l'entrée
standard STDIN_FILENO
*/

int		build_stdin(char *stdin, int line_number, char *first_line);
void	build(char *argv, int line_number, char *first_line);


#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		line_number;
	char	*first_line;
	int		cpt;
	char	*my_stdin;

	cpt = 1;
	printf("%i",argc);
	if (argc == 1)
	{
		printf("STDIN ON");
		my_stdin = parse_stdin();
		line_number = ft_countl_stdin(my_stdin);
		printf("%i",line_number);
		first_line = parse_stdin_param(my_stdin);
		build_stdin(my_stdin, line_number, first_line);
	}
	while (cpt < argc)
	{
		line_number = ft_count_line(1, argv[cpt]);
		first_line = parse_first_line_info(argv[cpt]);
		build(argv[cpt], line_number, first_line);
		cpt++;
	}
	return (0);
}

void	build(char *argv, int line_number, char *first_line)
{
	t_verif	verif;
	t_map	map;

	if (!(verif_first_line(first_line)))
	{	
		map_error();
	}
	verif = parse_param(first_line, line_number);
	map.settings = verif;
	map.grid = ft_verif_map(ft_split(parse_file(argv, first_line), "\n"), verif);
	if (!map.grid)
		map_error();
	else
		ft_print_grid(solve(map), verif);
}

int	build_stdin( char *stdin, int line_number, char *first_line)
{
	t_verif	verif;
	t_map	map;


	if (!(verif_first_line(first_line)))
		map_error();
	verif = parse_param(first_line, line_number);
	map.settings = verif;
	map.grid = ft_verif_map(ft_split(stdin, "\n"), verif);
	if (!map.grid)
		map_error();
	else
		ft_print_grid(solve(map), verif);

	return (0);
}

