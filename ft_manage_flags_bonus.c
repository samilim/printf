/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:05:53 by user42            #+#    #+#             */
/*   Updated: 2021/03/21 15:51:08 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_manage_minus(t_flags flags)
{
	flags.zero = 0;
	flags.minus = 1;
	return (flags);
}

t_flags	ft_manage_precision(const char *str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	if (!(save_digit = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (flags);
	j = 0;
	if (str[i + 1] != '*' && !ft_isdigit(str[i + 1]))
		flags.precision = 0;
	if (str[i + 1] == '*')
	{
		flags.precision = va_arg(args, int);
		if (flags.precision < (-1))
			flags.precision = (-1);
	}
	if (str[i + 1] && str[i + 1] != '*' && ft_isdigit(str[i + 1]))
	{
		i++;
		while (ft_isdigit(str[i]))
			save_digit[j++] = str[i++];
		save_digit[j] = '\0';
		flags.precision = ft_atoi(save_digit);
	}
	free(save_digit);
	return (flags);
}

t_flags	ft_manage_flags_ext(const char *str, int i, t_flags flags)
{
	if (str[i] == '0' && flags.minus == 0)
		flags.zero = 1;
	else if (str[i] == '-')
		flags = ft_manage_minus(flags);
	else if (str[i] == '+')
	{
		flags.sign = 1;
		flags.space = 0;
	}
	else if (str[i] == ' ' && flags.sign == 0)
		flags.space = 1;
	else if (str[i] == '#')
		flags.prefix = 1;
	return (flags);
}

t_flags	ft_manage_flags(const char *str, int i, t_flags flags, va_list args)
{
	while (str[i] && !ft_is_type(str, i))
	{
		if (str[i] == '0' || str[i] == '-'
		|| str[i] == '+' || str[i] == ' ' || str[i] == '#')
			flags = ft_manage_flags_ext(str, i, flags);
		else if (ft_isdigit(str[i]) || (str[i] == '*' && str[i - 1] != '.'))
		{
			flags = ft_manage_width(str, i, flags, args);
			while (ft_isdigit(str[i + 1]))
				i++;
		}
		else if (str[i] == '.')
		{
			flags = ft_manage_precision(str, i, flags, args);
			while (ft_isdigit(str[i + 1]))
				i++;
		}
		i++;
	}
	return (flags);
}
