/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:09:15 by salimon           #+#    #+#             */
/*   Updated: 2021/02/24 18:10:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_div_nb(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_count_byte(int nb, t_flags flags)
{
	int count;
	int f;

	count = 0;
	f = 0;
	if ((nb >= 0 && (flags.sign || flags.space)))
		f++;
	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width >= flags.precision))
		return (flags.width);
	if (flags.precision > flags.width)
		return (flags.precision + f);
	return (count + f);
}

char*ft_manage_buffer(char *buf, int i)
{

	return (buf);
}

int	ft_conversion_num(int nb, int fd, t_flags flags)
{
	int len;
	int i;
	int prec_i;
	int nb_len;
	char *buf;
	char *nb_pos;

	len = ft_count_byte(nb, flags);
	i = 0;
	prec_i = 0;
	if (flags.precision > ft_div_nb(nb))
		nb_len = flags.precision;
	else
		nb_len = ft_div_nb(nb);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	nb_pos = ft_itoa_noneg(nb);
	if (flags.space && (nb >= 0))
		buf[i++] = ' ';
	if (flags.space && nb < 0)
		flags.space = 0;
	if (!flags.minus)
	{
		while (((flags.width - (nb_len + flags.sign)) > 0) && i < (flags.width - (nb_len + flags.sign)))//((i + 1) < (len - (nb_len + flags.space + flags.sign)))
		{
			if (flags.zero && flags.precision == -1)
				buf[i++] = '0';
			else
				buf[i++] = ' ';
		}
	}
	if (flags.sign && nb >= 0)
		buf[i++] = '+';
	if (nb < 0)
		buf[i++] = '-';
	while ((ft_div_nb(nb) + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	while (*nb_pos)
		buf[i++] = *nb_pos++;
	if (flags.minus)
		while (i < len)
			buf[i++] = ' ';
	buf[i] = '\0';
	write (fd, buf, len);
	free(buf);
	return (len);
}