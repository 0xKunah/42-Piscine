/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:55:03 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/24 17:03:23 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#ifndef STDIN_H
# define STDIN_H

char	*parse_stdin_param(char *str);
int		len_list(t_list *list);
int		ft_countl_stdin(char *stdin);
t_list	*get_stdin(void);
char	*parse_stdin(void);
int		len_stdin(void);
#endif
