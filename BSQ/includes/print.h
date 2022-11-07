/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:48:59 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:04:54 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include <unistd.h>
# include <stdlib.h>
# include "./types/t_verif.h"
# include "./types/t_valid_position.h"

void	map_error(void);
void	ft_putchar(int mode, char c);
void	ft_putstr(int mode, char *str);
void	ft_print_grid(t_valid_position map, t_verif verif);
#endif
