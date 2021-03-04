/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:04:34 by salimon           #+#    #+#             */
/*   Updated: 2021/03/04 07:26:54 by user42           ###   ########.fr       */
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
		while (s[i + 1] && i++ < flags.width)
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

int		ft_conversion_s(const char *s, t_flags flags)
{
	int count;
	int len;
	int fill_width;

	count = 0;
	len = (ft_strlen(s) - flags.precision);
	fill_width = 0;
	if (!s)
		return (0);
	if (flags.minus)
		count = ft_putstr(s, flags, count);
	while (flags.precision != 0 && flags.width > 0 && (fill_width <= ((flags.width - len))))
	{
		write(1, " ", 1);
		fill_width++;
		count++;
	}
	if (!flags.minus)
		count = ft_putstr(s, flags, count);
	return (count);
}