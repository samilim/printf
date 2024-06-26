/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:59:35 by salimon           #+#    #+#             */
/*   Updated: 2021/03/27 15:07:39 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_cancel_zero(t_flags flags)
{
	flags.zero = 0;
	return (flags);
}

int		ft_div_nb(long long int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

int		ft_precision_zero(int len, t_flags flags)
{
	len = flags.width;
	while (flags.width--)
		write(1, " ", 1);
	return (len);
}

char	*ft_convert_low_hex(long long int nb, char *buf)
{
	const char	*base_hex;
	int			i;

	base_hex = "0123456789abcdef";
	i = 0;
	while (nb >= 16)
	{
		buf[i] = base_hex[(nb % 16)];
		nb = nb / 16;
		i++;
	}
	buf[i] = base_hex[(nb % 16)];
	buf[i + 1] = '\0';
	return (buf);
}

char	*ft_convert_up_hex(long long int nb, char *buf)
{
	const char	*base_hex;
	int			i;

	base_hex = "0123456789ABCDEF";
	i = 0;
	while (nb >= 16)
	{
		buf[i] = base_hex[(nb % 16)];
		nb = nb / 16;
		i++;
	}
	buf[i] = base_hex[(nb % 16)];
	buf[i + 1] = '\0';
	return (buf);
}
