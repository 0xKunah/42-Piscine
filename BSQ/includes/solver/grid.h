/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:40:46 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:02:34 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "../types/t_coords.h"
# include "../types/t_map.h"

void	goto_next_line(t_coords *coords);
int		is_grid_end(t_verif settings, t_coords pos);
int		is_line_end(t_verif settings, t_coords pos);
int		obstacles_in_area(t_map map, t_coords start,
			t_coords end, char obstacle);

#endif
