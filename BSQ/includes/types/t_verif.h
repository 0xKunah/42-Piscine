/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_verif.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:58:23 by hjacquel          #+#    #+#             */
/*   Updated: 2022/08/23 11:37:58 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VERIF_H
# define T_VERIF_H

typedef struct s_verif
{
	char	empty;
	char	obstacle;
	char	full;
	int		nb_lines;
	int		line_len;
}	t_verif;
#endif
