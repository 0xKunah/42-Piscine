/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:29:51 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/24 15:19:42 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print.h"

void	ft_putchar(int mode, char c)
{
	write(mode, &c, 1);
}

void	ft_putstr(int mode, char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(mode, str[n]);
		n++;
	}
}

void	map_error(void)
{
	ft_putstr(2, "map error");
	ft_putchar(2, '\n');
}

void	ft_print_grid(t_valid_position map, t_verif verif)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	x = 0;
	y = 0;
	max_x = map.start_coords.x + map.size;
	max_y = map.start_coords.y + map.size;
	if (map.start_coords.x == -1)
	{
		map_error();
		return ;
	}
	while (y < verif.nb_lines)
	{
		x = 0;
		while (x < verif.line_len)
		{
			if (x >= map.start_coords.x && y >= map.start_coords.y)	
			{
				if (x < max_x && y < max_y)
				{
					map.grid[y][x] = verif.full;
				}
			}
			ft_putchar(0, map.grid[y][x]);
			x++;
		}
		ft_putchar(0, '\n');
		y++;
	}
}
