/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:55:45 by user42            #+#    #+#             */
/*   Updated: 2021/03/11 11:02:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_flag(char c)
{
	int i;
    const char *char_flags;

	i = 0;
    char_flags = "*-+0 #.";
    while (char_flags[i])
    {
        if (char_flags[i] == c)
            return (1);
		i++;
    }
    return (0);
}

int ft_is_double_flag(char c, char *save_flags)
{
    int i;

    i = 0;
    while (save_flags[i])
    {
        if (c != '*' && c == save_flags[i])
            return (1);
		i++;
    }
    return (0);
}

int	ft_check_error(const char *str)
{
	int i;
	char *save_flags;

	i = 0;
	if (!(save_flags = malloc(sizeof(char) * 10)))
		return (1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
			{
				ft_free_ptr(save_flags);
				return (1);
			}
			while (str[i] && !ft_is_type(str, i))
			{
				if ((!ft_is_flag(str[i]) && !ft_isdigit(str[i])) || ft_is_double_flag(str[i], save_flags))
				{
					ft_free_ptr(save_flags);
					return (1);
				}
				*save_flags++ = str[i];
				i++;
			}
            if (!str[i])
			{
				ft_free_ptr(save_flags);
                return (1);
			}
		}
		i++;
	}
	ft_free_ptr(save_flags);
	return (0);
}

//cas trop grande taille de champ
//cas trop de chiffres
//cas multi 0
//cas multi *