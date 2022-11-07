/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:48:42 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/14 20:59:56 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// parser_convert.c
int		**ft_convert(char **argv, int n);
int		ft_free_tab(int **nbr, int size);
void	ft_convert_constraints(int **nbr, int size);
void	ft_free_constraints(void);

// parser_compare.c
int		ft_compare(int **nbr, int n);

// parser_input.c
int		ft_check_input(int argc, char **argv, int *n);

// parser_rules.c
void	ft_include_n(int **nbr, int **grid, int n);

#endif
