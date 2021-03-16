/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:35:33 by salimon           #+#    #+#             */
/*   Updated: 2021/03/16 14:22:08 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_is_type(const char *str, int i)
{
	const char* types;
	int j;

	types = "cspdiuxX%";
	j = 0;
	while (types[j])
	{
		if (str[i] == types[j])
			return (1);
		j++;
	}
	return (0);
}

t_flags	ft_manage_minus(t_flags flags)
{
	flags.zero = 0;
	flags.minus = 1;
	return (flags);
}

t_flags	ft_manage_width(const char* str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	if (str[i] == '*')
	{
		flags.width = va_arg(args, int);
		if (flags.width < 0)
		{
			flags.width *= -1;
			flags.minus = 1;
		}
		return (flags);
	}
	j = i;
	while (ft_isdigit(str[j]))
		j++;
	j = (j - i);
	if (!(save_digit = malloc(sizeof(char) * (j + 1))))
	{
		flags.precision = 0;
		return (flags);
	}
	j = 0;

	while (ft_isdigit(str[i]))
	{
		save_digit[j++] = str[i++];
	}
	save_digit[j] = '\0';
	flags.width = ft_atoi(save_digit);
	free(save_digit);
	return (flags);
}

t_flags ft_manage_precision(const char* str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	save_digit = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!save_digit)
	{
		flags.precision = 0;
		return (flags);
	}
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
		flags.precision = ft_atoi(save_digit);
	}
	free(save_digit);
	return (flags);
}

t_flags ft_manage_flags(const char *str, int i, t_flags flags, va_list args)
{
	while (str[i] && !ft_is_type(str, i))
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
