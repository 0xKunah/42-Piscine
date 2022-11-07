/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_valid_position.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:37:59 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 14:04:11 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VALID_POSITION_H
# define T_VALID_POSITION_H
# include "./t_coords.h"

typedef struct s_valid_position {
	t_coords	start_coords;
	char		**grid;
	int			size;
}	t_valid_position;

#endif
