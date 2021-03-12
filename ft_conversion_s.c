/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:04:34 by salimon           #+#    #+#             */
/*   Updated: 2021/03/12 16:02:11 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s, t_flags flags, int count)
{
	int i;

	i = 0;
	if (flags.precision > 0)
	{
		while (s[i] && i < flags.precision)
		{
			ft_putchar_fd(s[i++], 1);
			count++;
		}
	}
	else if (flags.precision == 0)
	{
		while (s[i++] && i <= flags.width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	else
		while (s[i])
		{
			ft_putchar_fd(s[i++], 1);
			count++;
		}
	return (count);
}

int		ft_conversion_s(/*const char *s,*/ t_flags flags, va_list args)
{
	int count;
	int len;
	int fill_width;
	const char *s;

	s = va_arg(args, const char *);
	if (!s)
		s = "(null)";
	//return (ft_is_null(flags));
	//write(1, "W", 1);
	count = 0;
	if (flags.precision > 0 && ((unsigned int)flags.precision < ft_strlen(s)))
		len = flags.precision;
	else
		len = ft_strlen(s);
	//len = (ft_strlen(s) - flags.precision);
	fill_width = 0;
	if (flags.minus)
		count = ft_putstr(s, flags, count);
	while (flags.width > 0 && (fill_width < (flags.width - len))) //(fill_width <= ((flags.width - len))))
	{
		write(1, " ", 1);
		fill_width++;
		count++;
	}
	if (!flags.minus)
		count = ft_putstr(s, flags, count);
	//printf("\n%d\n", flags.precision);
	return (count);
}