/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:43:05 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/10 09:19:48 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if (
		(c < 65 || c > 90)
		&& (c < 97 || c > 122)
	)
		return (0);
	return (1);
}

int	ft_char_is_upper(char c)
{
	if (c < 65 || c > 90)
		return (0);
	return (1);
}

int	ft_char_is_lower(char c)
{
	if (c < 97 || c > 122)
		return (0);
	return (1);
}

int	ft_char_is_numeric(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (ft_char_is_lower(str[i]))
				str[i] -= 32;
		}
		else if (ft_char_is_upper(str[i])
			&& ft_char_is_numeric(str[i - 1])
			&& ft_char_is_alpha(str[i - 1]))
			str[i] += 32;
		else if (!ft_char_is_alpha(str[i - 1])
			&& !ft_char_is_numeric(str[i - 1])
			&& ft_char_is_lower(str[i])
			&& ft_char_is_alpha(str[i + 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
