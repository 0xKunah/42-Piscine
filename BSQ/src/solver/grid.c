/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:29:33 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 15:19:49 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver/grid.h"

void	goto_next_line(t_coords *coords)
{
	coords->y += 1;
	coords->x = 0;
}

int	is_grid_end(t_verif settings, t_coords pos)
{
	return ((pos.y == settings.nb_lines - 1 && pos.x == settings.line_len));
}

int	is_line_end(t_verif settings, t_coords pos)
{
	return (pos.x == settings.line_len);
}

int	obstacles_in_area(t_map map, t_coords start, t_coords end, char obstacle)
{
	t_coords	temp_pos;

	temp_pos = start;
	while (temp_pos.y < end.y)
	{
		while (temp_pos.x < end.x)
		{
			if (map.grid[temp_pos.y][temp_pos.x] == obstacle)
				return (1);
			temp_pos.x++;
		}
		temp_pos.x = start.x;
		temp_pos.y++;
	}
	return (0);
}
