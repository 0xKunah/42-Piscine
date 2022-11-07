/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:52:36 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 17:00:22 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "./types/t_verif.h"
# include <stdlib.h>
# include "./types/t_list.h"
# include "stdin.h"

t_verif	parse_param(char *str, int len_line);
char	**ft_verif_map(char **map, t_verif verif);
char	**ft_split(char *str, char *charset);
char	*parse_first_line_info(char *str);
char	*parse_file(char *path, char *first_line);
char	*ft_strdup(char *src);
int		ft_count_line(int mode, char *str);
int		verif_first_line(char *str);
int		ft_strlen(char *str);
int		file_len(char *path);
int		is_number(char c);



#endif
