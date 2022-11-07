/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:04 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:06:03 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver/coords.h"

void	add_offset(t_coords *coords, int x_offset, int y_offset)
{
	coords->x += x_offset;
	coords->y += y_offset;
}

int	compare_coords(t_coords c1, t_coords c2)
{
	return ((c1.x >= c2.x && c1.y >= c2.y));
}

t_coords	get_coords_with_offset(t_coords coords, int offset)
{
	t_coords	new_coords;

	new_coords.x = coords.x + offset;
	new_coords.y = coords.y + offset;
	return (new_coords);
}

char	get_value_by_coords(t_map map, t_coords coords)
{
	return (map.grid[coords.y][coords.x]);
}

t_coords	vector2(int x, int y)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}
