/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:12:16 by salimon           #+#    #+#             */
/*   Updated: 2021/03/26 16:29:51 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.sign = 0;
	flags.zero = 0;
	flags.space = 0;
	flags.prefix = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.plus = 0;
	return (flags);
}

char	ft_is_type(const char *str, int i)
{
	const char	*types;
	int			j;

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

int		ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_manage_conversions(const char *str, int i,
va_list args, t_flags flags)
{
	if (str[i] == 'c')
		return (ft_conversion_c(va_arg(args, int), 1, flags));
	if (str[i] == 's')
		return (ft_conversion_s(va_arg(args, const char *), flags));
	if (str[i] == 'p')
		return (ft_conversion_p(va_arg(args, void *), flags));
	if ((str[i] == 'd' || str[i] == 'i') && (str[i - 1] == 'l'))
		return (ft_conversion_ll((long long int)va_arg(args, int), 1, flags));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_conversion_num(va_arg(args, int), 1, flags));
	if (str[i] == 'u')
		return (ft_conversion_u(va_arg(args, unsigned int), 1, flags));
	if (str[i] == 'x')
		return (ft_conversion_xlow(va_arg(args, unsigned int), flags));
	if (str[i] == 'X')
		return (ft_conversion_xup(va_arg(args, unsigned int), flags));
	if (str[i] == '%')
		return (ft_conversion_pct(flags));
	else
		return (0);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	t_flags	flags;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flags = ft_init_flags(flags);
			i++;
			flags = ft_manage_flags(str, i, flags, args);
			while (!ft_is_type(str, i))
				i++;
			count += ft_manage_conversions(str, i, args, flags);
			i++;
		}
		else
			count += ft_putchar_fd(str[i++], 1);
	}
	va_end(args);
	return (count);
}
