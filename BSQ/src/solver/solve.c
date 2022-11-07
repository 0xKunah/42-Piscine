/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:07:39 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 18:05:43 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver/solve.h"

t_valid_position	solve(t_map map)
{
	int					square_size;
	t_coords			coords;
	t_valid_position	final_pos;

	final_pos.grid = NULL;
	final_pos.size = 0;
	final_pos.start_coords = vector2(-1, -1);
	square_size = min(map.settings.line_len, map.settings.nb_lines);
	while (square_size > 0)
	{
		coords = vector2(0, 0);
		while (compare_coords(vector2(map.settings.line_len,
					map.settings.nb_lines), coords_offset(coords, square_size)))
		{
			if (!obstacles_in_area(map, coords,
					coords_offset(coords, square_size), map.settings.obstacle))
				return (update_final_pos(&final_pos, coords, square_size, map));
			if (is_line_end(map.settings, coords_offset(coords, square_size)))
				goto_next_line(&coords);
			else
				add_offset(&coords, 1, 0);
		}
		square_size--;
	}
	return (final_pos);
}

t_valid_position	update_final_pos(t_valid_position *final,
	t_coords coords, int square_size, t_map map)
{
	final->start_coords = coords;
	final->size = square_size;
	final->grid = map.grid;
	return (*final);
}
