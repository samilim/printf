/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:35:24 by user42            #+#    #+#             */
/*   Updated: 2021/03/19 23:36:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_star_width(t_flags flags, va_list args)
{
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.width *= -1;
		flags.minus = 1;
	}
	return (flags);
}

t_flags	ft_manage_width(const char *str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	if (str[i] == '*')
		return (flags = ft_star_width(flags, args));
	j = i;
	while (ft_isdigit(str[j]))
		j++;
	j = (j - i);
	if (!(save_digit = malloc(sizeof(char) * (j + 1))))
		return (flags);
	j = 0;
	while (ft_isdigit(str[i]))
		save_digit[j++] = str[i++];
	save_digit[j] = '\0';
	flags.width = ft_atoi(save_digit);
	free(save_digit);
	return (flags);
}