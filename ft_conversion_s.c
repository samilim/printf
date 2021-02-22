/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:04:34 by salimon           #+#    #+#             */
/*   Updated: 2021/02/22 03:43:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, t_flags flags)
{
	int i;

	i = 0;
	if (flags.precision >= 0)
	{
		while (s[i] && i < flags.precision)
			ft_putchar_fd(s[i++], 1);
	}
	else
		while (s[i])
			ft_putchar_fd(s[i++], 1);
}

int		ft_conversion_s(const char *s, t_flags flags)
{
	int count;
	int len;

	count = 0;
	len = (ft_strlen(s) - flags.precision);
	if (!s)
		return (0);
	if (flags.minus)
		ft_putstr(s, flags);
	while (flags.width > 0 && ((count + len) <= flags.width))
	{
		write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		ft_putstr(s, flags);
	return (count);
}