/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:09:15 by salimon           #+#    #+#             */
/*   Updated: 2021/03/20 23:52:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_byte(int nb, t_flags flags)
{
	int count;
	int f;

	count = 0;
	f = 0;
	if (nb < 0)
		flags.sign = 1;
	if (nb < 0 || (nb >= 0 && (flags.sign || flags.space)))
		f++;
	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width > count) &&
	(flags.width > flags.precision))
		return (flags.width);
	if (flags.precision >= flags.width && flags.precision > count)
		return (f + flags.precision);
	return (count + f);
}

static int		ft_manage_sign(char *buf, int i, int nb, t_flags flags)
{
	if (flags.sign && nb >= 0)
		buf[i++] = '+';
	if (flags.sign && nb < 0)
		buf[i++] = '-';
	return (i);
}

static int		ft_manage_postnb(char *buf, int nb,
int nb_len, t_flags flags)
{
	int i;

	i = 0;
	if (flags.space && (nb >= 0))
		buf[i++] = ' ';
	if (flags.space && nb < 0)
		flags.space = 0;
	if (nb < 0)
		flags.sign = 1;
	if (!flags.minus)
	{
		while ((i < (flags.width - (nb_len + flags.sign))))
		{
			if (flags.zero)
			{
				i = ft_manage_sign(buf, i, nb, flags);
				if (flags.sign && nb < 0)
					flags.sign = 0;
				buf[i++] = '0';
			}
			else
				buf[i++] = ' ';
		}
	}
	return (ft_manage_sign(buf, i, nb, flags));
}

static char		*ft_manage_buffer(int nb, int nb_len, char *buf, t_flags flags)
{
	int		prec_i;
	int		div_nb;
	int		i;
	int		len;
	char	*nb_pos;

	i = 0;
	len = ft_count_byte(nb, flags);
	div_nb = ft_div_nb(nb);
	prec_i = 0;
	nb_pos = ft_itoa_noneg(nb);
	if (flags.space && (nb >= 0))
		buf[i++] = ' ';
	i = ft_manage_postnb(buf, nb, nb_len, flags);
	while (((div_nb + prec_i++) < flags.precision))
		buf[i++] = '0';
	div_nb = 0;
	while (nb_pos[div_nb])
		buf[i++] = nb_pos[div_nb++];
	free(nb_pos);
	if (flags.minus)
		while (i < len)
			buf[i++] = ' ';
	return (buf);
}

int				ft_conversion_num(int nb, int fd, t_flags flags)
{
	int		len;
	int		nb_len;
	char	*buf;

	len = 0;
	if (flags.precision == 0 && nb == 0)
		return (ft_precision_zero(len, flags));
	if (flags.precision != (-1))
		flags = ft_cancel_zero(flags);
	len = ft_count_byte(nb, flags);
	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return (0);
	buf[len] = '\0';
	if (flags.precision > (ft_div_nb(nb) + flags.sign))
		nb_len = flags.precision;
	else
		nb_len = (ft_div_nb(nb) + flags.sign);
	buf = ft_manage_buffer(nb, nb_len, buf, flags);
	write(fd, buf, len);
	free(buf);
	return (len);
}
