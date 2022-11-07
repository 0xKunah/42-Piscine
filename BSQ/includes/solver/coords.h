/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:32:51 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 18:02:49 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDS_H
# define COORDS_H
# include "../types/t_coords.h"
# include "../types/t_map.h"

int			compare_coords(t_coords c1, t_coords c2);
char		get_value_by_coords(t_map map, t_coords coords);
void		add_offset(t_coords *coords, int x_offset, int y_offset);
t_coords	coords_offset(t_coords coords, int offset);
t_coords	vector2(int x, int y);

#endif
