/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:46:45 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:03:35 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "../types/t_valid_position.h"
# include "./coords.h"
# include "./grid.h"
# include "./math.h"
# include "./square.h"

t_valid_position	solve(t_map map);

#endif
