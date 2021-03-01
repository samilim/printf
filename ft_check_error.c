/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:55:45 by user42            #+#    #+#             */
/*   Updated: 2021/03/01 02:49:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_flag(char c)
{
    char *char_flags;

    char_flags = "-+0 #.";
    while (*char_flags)
    {
        if (*char_flags++ == c)
            return (1);
    }
    return (0);
}

int ft_is_double_flag(char c, char *save_flags)
{
    int i;

    i = 0;
    while (save_flags[i])
    {
        if (c == save_flags[i++])
            return (1);
    }
    return (0);
}

int	ft_check_error(const char *str)
{
	int i;
	char *save_flags;

	i = 0;
	save_flags = malloc(sizeof(char) * 10);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (1);
			while (str[i] && !ft_is_type(str, i))
			{
				if (!ft_is_flag(str[i]) || !ft_isdigit(str[i]) || ft_is_double_flag(str[i], save_flags))
					return (1); //wtf
				*save_flags++ = str[i];
				i++;
			}
            if (!str[i])
                return (1);
		}
		i++;
	}
	//free (save_flags);
	return (0);
}